/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_champs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: torange <@student.42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 15:23:48 by blinnea           #+#    #+#             */
/*   Updated: 2020/08/25 17:41:46 by torange          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include <fcntl.h>
#include <unistd.h>

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
	ft_memcpy(buff, bbuff, sz);
	return (rc);
}

static bool			init_champ(t_player *p)
{
	int			fd;
	uint32_t	buff;
	uint32_t	champ_size;

	if ((fd = open(p->fname, O_RDONLY)) < 0)
		return (ft_printf("Error: open\n") && false);
	if (rread(fd, &buff, 4) != 4 || buff != COREWAR_EXEC_MAGIC)
		return (ft_printf("Error: Magic Header\n") && (close(fd) & false));
	if (read(fd, p->name, PROG_NAME_LENGTH) != PROG_NAME_LENGTH)
		return (ft_printf("Error: Name\n") && (close(fd) & false));
	if (read(fd, &buff, 4) != 4 || buff)
		return (ft_printf("Error: NULL\n") && (close(fd) & false));
	if (rread(fd, &champ_size, 4) != 4 || champ_size > CHAMP_MAX_SIZE)
		return (ft_printf("Error: Champ Size\n") && (close(fd) & false) );
	if (read(fd, p->comment, COMMENT_LENGTH) != COMMENT_LENGTH)
		return (ft_printf("Error: Comment\n") && (close(fd) & false));
	if (read(fd, &buff, 4) != 4 || buff)
		return (ft_printf("Error: NULL\n") && (close(fd) & false));
	if (read(fd, p->exec, champ_size) != champ_size)
		return (ft_printf("Error: Executable Code\n") && (close(fd) & false));
	return (close(fd) | true);
}

bool				init_champs(t_vm *vm)
{
	uint32_t	i;

	i = 0;
	while (i < vm->psize)
		if (!init_champ(vm->pls + i++))
			return (false);
	return (true);
}

bool				init_body(t_vm *vm)
{
	ft_bzero(vm->body, MEM_SIZE);
	return (true);
}
