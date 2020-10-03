/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 15:23:48 by blinnea           #+#    #+#             */
/*   Updated: 2020/10/03 14:38:26 by blinnea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pl.h"
#include <fcntl.h>

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

static bool			init_pl(t_player *p)
{
	int			fd;
	uint32_t	null;

	if ((fd = open(p->fname, O_RDONLY)) < 0)
		return (ft_printf_fd(STDERR_FILENO, "Error: open\n") && false);
	if (rread(fd, &p->header.magic, sizeof(p->header.magic)) != sizeof(p->header.magic) || p->header.magic != COREWAR_EXEC_MAGIC)
		return (ft_printf_fd(STDERR_FILENO, "Error: Magic Header\n") && (close(fd) & false));
	if (read(fd, p->header.prog_name, PROG_NAME_LENGTH * sizeof(*(p->header.prog_name))) != PROG_NAME_LENGTH * sizeof(*(p->header.prog_name)))
		return (ft_printf_fd(STDERR_FILENO, "Error: Name\n") && (close(fd) & false));
	if (read(fd, &null, sizeof(null)) != sizeof(null) || null)
		return (ft_printf_fd(STDERR_FILENO, "Error: NULL\n") && (close(fd) & false));
	if (rread(fd, &p->header.prog_size, sizeof(p->header.prog_size)) != sizeof(p->header.prog_size) || p->header.prog_size > CHAMP_MAX_SIZE)
		return (ft_printf_fd(STDERR_FILENO, "Error: Champ Size\n") && (close(fd) & false) );
	if (read(fd, p->header.comment, COMMENT_LENGTH * sizeof(*(p->header.comment))) != COMMENT_LENGTH * sizeof(*(p->header.comment)))
		return (ft_printf_fd(STDERR_FILENO, "Error: Comment\n") && (close(fd) & false));
	if (read(fd, &null, sizeof(null)) != sizeof(null) || null)
		return (ft_printf_fd(STDERR_FILENO, "Error: NULL\n") && (close(fd) & false));
	if (read(fd, p->exec, p->header.prog_size * sizeof(*(p->exec))) != p->header.prog_size)
		return (ft_printf_fd(STDERR_FILENO, "Error: Executable Code\n") && (close(fd) & false));
	return (close(fd) | true);
}

bool				init_pls(t_player *pls, uint8_t pls_size)
{
	uint32_t	i;

	i = -1;
	while (++i < pls_size)
		if (!init_pl(pls + i))
			return (false);
	return (true);
}

void				show_pl(t_player *pl)
{
	ft_printf("id: %d\n", pl->id);
	ft_printf("filename: %s\n", pl->fname);
	ft_printf("program name: %s\n", pl->header.prog_name);
	ft_printf("program size: %u\n", pl->header.prog_size);
	ft_printf("comment: %s\n", pl->header.comment);
}