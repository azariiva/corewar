/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_champs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 15:23:48 by blinnea           #+#    #+#             */
/*   Updated: 2020/08/20 17:48:41 by blinnea          ###   ########.fr       */
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
		return (false);
	if (rread(fd, &buff, 4) != 4 || buff != 0x00ea83f3 /* Magic Header*/)
		return (close(fd) & false);
	if (read(fd, p->name, PROG_NAME_LENGTH) != PROG_NAME_LENGTH || /* Name */
		read(fd, &buff, 4) != 4 || buff || /* NULL */
		rread(fd, &champ_size, 4) != 4 || champ_size > CHAMP_MAX_SIZE || /* Champ Size */
		read(fd, p->comment, COMMENT_LENGTH) != COMMENT_LENGTH || /* Comment */
		read(fd, &buff, 4) != 4 || buff || /* NULL */
		read(fd, p->exec, champ_size) != champ_size /* Executable Code */)
		return (close(fd) & false);
	return (close(fd) | true);
}

bool				init_champs(t_player *pls)
{
	uint32_t	i;

	i = -1;
	while (++i < MAX_PLAYERS && pls[i].idx)
		if (!init_champ(pls + i))
			return (false);
	return (true);
}
