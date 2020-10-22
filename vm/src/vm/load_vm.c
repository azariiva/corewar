/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_vm.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 15:20:25 by fhilary           #+#    #+#             */
/*   Updated: 2020/10/06 17:34:00 by blinnea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include <fcntl.h>

inline static void	add_champ(const char*const fname, const uint32_t id,
t_vm*const vm, bool*const occids)
{
	if (id < 1 || id > MAX_PLAYERS || occids[id] == true)
	{
		vm->pls[vm->pls_size++].fname = fname;
		return ;
	}
	vm->pls[vm->pls_size].id = id;
	vm->pls[vm->pls_size++].fname = fname;
	occids[id] = true;
}

static void			assign_ids(t_vm*const vm, bool*const occids)
{
	uint32_t	i;
	uint32_t	j;

	i = -1;
	j = 1;
	while (++i < vm->pls_size)
	{
		if (!vm->pls[i].id)
		{
			while (occids[j] == true)
				++j;
			vm->pls[i].id = j;
			occids[j++] = true;
		}
	}
}

static int			cmp(const void *a, const void *b)
{
	t_player	*player_a;
	t_player	*player_b;

	player_a = (t_player *)a;
	player_b = (t_player *)b;
	if (player_a->id == player_b->id)
		return (0);
	return (player_a->id > player_b->id ? 1 : -1);
}

/*
** 1) Parsing command line arguments
*/
t_vm				*parse_args(t_acav acav)
{
	static t_vm	vm;
	bool		occids[MAX_PLAYERS + 1];
	int			c;

	ft_bzero(occids, sizeof(occids));
	while (vm.pls_size <= MAX_PLAYERS)
	{
		if ((c = ft_getopt(acav, ":n:")) == -1)
		{
			if (acav.av[g_optind] == NULL)
				break;
			else
				add_champ(acav.av[g_optind++], 0, &vm, occids);
		}
		else if (c == ':')
		{
			ft_printf_fd(STDERR_FILENO, "Option \'-%c\' requires an argument\n",
			g_optopt);
		}
		else if (c == 'n')
		{
			if (ft_strisnum(g_optarg))
				add_champ(acav.av[g_optind++], ft_atou(g_optarg), &vm, occids);
			else
			{
				/*
				** TODO: norme this string.
				*/
				ft_printf_fd(STDERR_FILENO,
				"Option \'-n\' requires number as argument.\nWarning: Argument after \'-n\' ignored!\n");
			}
		}
	}
	assign_ids(&vm, occids);
	FT_QUICKSORT(vm.pls, vm.pls_size, cmp);
	return (&vm);
}

/*
** ########################################################################## **
*/

static ssize_t		rread(const int fd, void *buff, size_t sz)
{
	size_t			i;
	ssize_t			rc;
	unsigned char	*bbuff;

	rc = read(fd, buff, sz);
	i = -1;
	bbuff = buff;
	while (++i < sz / 2)
	{
		bbuff[i] ^= bbuff[sz - 1 - i];
		bbuff[sz - 1 - i] ^= bbuff[i];
		bbuff[i] ^= bbuff[sz - 1 - i];
	}
	return (rc);
}


static bool			init_pl(t_player *p)
{
	int			fd;
	uint32_t	null;

	if ((fd = open(p->fname, O_RDONLY)) < 0)
		return (ft_printf_fd(STDERR_FILENO, "Error: can't open file %s\n", p->fname) & false);
	if (rread(fd, &p->header.magic, sizeof(p->header.magic)) != sizeof(p->header.magic) || p->header.magic != COREWAR_EXEC_MAGIC)
		return (ft_printf_fd(STDERR_FILENO, "Error: Magic Header not found in %s\n", p->fname) & (close(fd) & false));
	if (read(fd, p->header.prog_name, PROG_NAME_LENGTH * sizeof(*(p->header.prog_name))) != PROG_NAME_LENGTH * sizeof(*(p->header.prog_name)))
		return (ft_printf_fd(STDERR_FILENO, "Error: File %s too short\n", p->fname) & (close(fd) & false));
	if (read(fd, &null, sizeof(null)) != sizeof(null) || null)
		return (ft_printf_fd(STDERR_FILENO, "Error: 1st separator is absent in %s\n", p->fname) & (close(fd) & false));
	if (rread(fd, &p->header.prog_size, sizeof(p->header.prog_size)) != sizeof(p->header.prog_size))
		return (ft_printf_fd(STDERR_FILENO, "Error: File %s too short\n", p->fname) & (close(fd) & false));
	if (p->header.prog_size > CHAMP_MAX_SIZE)
		return (ft_printf_fd(STDERR_FILENO, "Error: program size in %s is too big: %u > %u\n", p->fname, p->header.prog_size, CHAMP_MAX_SIZE) & (close(fd) & false) );
	if (read(fd, p->header.comment, COMMENT_LENGTH * sizeof(*(p->header.comment))) != COMMENT_LENGTH * sizeof(*(p->header.comment)))
		return (ft_printf_fd(STDERR_FILENO, "Error: File %s too short\n", p->fname) & (close(fd) & false));
	if (read(fd, &null, sizeof(null)) != sizeof(null) || null)
		return (ft_printf_fd(STDERR_FILENO, "Error: 2nd separator is absent in %s\n", p->fname) & (close(fd) & false));
	if (read(fd, p->exec, p->header.prog_size * sizeof(*(p->exec))) != p->header.prog_size)
		return (ft_printf_fd(STDERR_FILENO, "Error: actual executable code in %s is smaller than %u\n", p->fname, p->header.prog_size) & close(fd) & false);
	return (close(fd) | true);
}

/*
** 2) Reading players from file given as command line args
*/
static bool			init_pls(t_player *pls, uint8_t pls_size)
{
	uint32_t	i;

	i = -1;
	while (++i < pls_size)
		if (!init_pl(pls + i))
			return (false);
	return (true);
}

/*
** ########################################################################## **
*/

/*
** 3) Loading players to arena
*/

static bool			load_pls(t_vm *vm)
{
	t_cursor	c;
	uint32_t	i;
	uint32_t	j;
	uint32_t	step;

	step =  MEM_SIZE / vm->pls_size;
	i = -1;
	while (++i < vm->pls_size)
	{
		INIT_CURSOR(&c, vm->pls[i].id, i * step);
		if (add_cursor(vm, &c) == false)
		{
			clear_cursors(vm);
			return (false);
		}
		j = -1;
		while (++j < vm->pls[i].header.prog_size)
		{
			vm->mem[j + i * step].data = vm->pls[i].exec[j];
			vm->mem[j + i * step].owner = i;
		}
	}
	return (true);
}

t_vm			*init_vm(t_acav acav)
{
	t_vm	*vm;

	vm = parse_args(acav);
	if (!init_pls(vm->pls, vm->pls_size) || !load_pls(vm))
		return (NULL);
	return (vm);
}
