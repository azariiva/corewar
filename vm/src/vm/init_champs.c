/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_champs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 15:23:48 by blinnea           #+#    #+#             */
/*   Updated: 2020/10/01 19:41:24 by blinnea          ###   ########.fr       */
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
	// ft_memcpy(buff, bbuff, sz); // I think this is not neccessary at all.
	return (rc);
}

static bool			init_champ(t_player *p)
{
	int			fd;
	uint32_t	null;

	if ((fd = open(p->fname, O_RDONLY)) < 0)
		return (false);
	if (rread(fd, &p->header.magic, sizeof(p->header.magic)) != sizeof(p->header.magic) || p->header.magic != COREWAR_EXEC_MAGIC /* Magic Header*/)
		return (close(fd) & false);
	if (read(fd, p->header.prog_name, PROG_NAME_LENGTH * sizeof(*(p->header.prog_name))) != PROG_NAME_LENGTH * sizeof(*(p->header.prog_name)) || /* Name */
		read(fd, &null, 4) != 4 || null || /* NULL */
		rread(fd, &p->header.prog_size, sizeof(p->header.prog_size)) != sizeof(p->header.prog_size) || p->header.prog_size > CHAMP_MAX_SIZE || /* Champ Size */
		read(fd, p->header.comment, COMMENT_LENGTH * sizeof(*(p->header.comment))) != COMMENT_LENGTH * sizeof(*(p->header.comment)) || /* Comment */
		read(fd, &null, 4) != 4 || null || /* NULL */
		read(fd, p->exec, p->header.prog_size * sizeof(*(p->exec))) != p->header.prog_size /* Executable Code */)
		return (close(fd) & false);
	return (close(fd) | true);
}

bool				init_champs(t_player *pls)
{
	uint32_t	i;

	i = -1;
	while (++i < MAX_PLAYERS && pls[i].id)
		if (!init_champ(pls + i))
			return (false);
	return (true);
}
