/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libbuf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: torange <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 19:03:58 by torange           #+#    #+#             */
/*   Updated: 2020/02/12 19:09:31 by torange          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libbuf.h"

ssize_t		ft_fflush(t_buf *buf)
{
	ssize_t	res;

	res = write(STDOUT_FILENO, buf->body, buf->total);
	ft_bzero(buf->body, MAX_BUF);
	buf->total = 0;
	return (res);
}

ssize_t		ft_putstr_buf(t_buf *buf, const char *str)
{
	ssize_t	res;

	res = 0;
	while (*str)
	{
		buf->body[buf->total++] = *str;
		++str;
		++res;
		if (buf->total == MAX_BUF && ft_fflush(buf) < 0)
			res = 0;
	}
	return (res);
}

ssize_t		ft_putchar_buf(t_buf *buf, char c)
{
	buf->body[buf->total++] = c;
	if (buf->total == MAX_BUF && ft_fflush(buf) < 0)
		return (0);
	return (1);
}

ssize_t		ft_putcharn_buf(t_buf *buf, char c, size_t n)
{
	ssize_t	res;

	res = 0;
	while (n-- > 0)
	{
		buf->body[buf->total++] = c;
		++res;
		if (buf->total == MAX_BUF && ft_fflush(buf) < 0)
			res = 0;
	}
	return (res);
}

ssize_t		ft_putstrn_buf(t_buf *buf, const char *str, size_t n)
{
	size_t	i;
	ssize_t	res;

	res = 0;
	i = 0;
	if (ft_strlen(str) > n)
		while (i < n)
		{
			buf->body[buf->total++] = str[i];
			++i;
			++res;
			if (buf->total == MAX_BUF && ft_fflush(buf) < 0)
				res = 0;
		}
	else
		while (*str)
		{
			buf->body[buf->total++] = *str;
			++str;
			++res;
			if (buf->total == MAX_BUF && ft_fflush(buf) < 0)
				res = 0;
		}
	return (res);
}
