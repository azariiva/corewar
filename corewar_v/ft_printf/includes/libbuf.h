/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libbuf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: torange <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 19:00:42 by torange           #+#    #+#             */
/*   Updated: 2020/02/12 19:02:24 by torange          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBBUF_H

# define LIBBUF_H

# define MAX_BUF 64

# include "libft.h"

typedef struct	s_buf
{
	unsigned char	body[MAX_BUF];
	size_t			total;
}				t_buf;

ssize_t			ft_putstr_buf(t_buf *buf, const char *str);
ssize_t			ft_putchar_buf(t_buf *buf, char c);
ssize_t			ft_fflush(t_buf *buf);
ssize_t			ft_putcharn_buf(t_buf *buf, char c, size_t n);
ssize_t			ft_putstrn_buf(t_buf *buf, const char *str, size_t n);

#endif
