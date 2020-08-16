/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaple <rmaple@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 17:41:10 by rmaple            #+#    #+#             */
/*   Updated: 2019/09/20 17:48:06 by rmaple           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	const unsigned char	*p_src;
	unsigned char		*p_dest;

	p_src = (unsigned char *)src;
	p_dest = (unsigned char *)dst;
	if (p_dest == p_src)
		return (dst);
	if (p_src > p_dest)
		while (len--)
			*p_dest++ = *p_src++;
	else
	{
		p_dest += len;
		p_src += len;
		while (len--)
			*--p_dest = *--p_src;
	}
	return (dst);
}
