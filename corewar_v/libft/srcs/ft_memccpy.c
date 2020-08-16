/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaple <rmaple@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 17:40:38 by rmaple            #+#    #+#             */
/*   Updated: 2019/09/17 22:35:29 by rmaple           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*p_dest;
	unsigned char	*p_src;
	unsigned char	c2;

	c2 = (unsigned char)c;
	p_src = (unsigned char *)src;
	p_dest = (unsigned char *)dst;
	i = 0;
	while (i < n)
	{
		p_dest[i] = p_src[i];
		if (p_src[i] == c2)
			return (dst + i + 1);
		i++;
	}
	return (NULL);
}
