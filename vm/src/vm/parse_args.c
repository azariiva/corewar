/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 14:56:27 by blinnea           #+#    #+#             */
/*   Updated: 2020/10/03 15:19:38 by blinnea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

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

t_vm	*parse_args(t_acav acav)
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
