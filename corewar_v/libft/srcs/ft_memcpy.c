/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaple <rmaple@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 17:40:10 by rmaple            #+#    #+#             */
/*   Updated: 2019/09/23 23:08:25 by rmaple           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*p_dest;
	unsigned char	*p_src;

	if (src == NULL && dst == NULL)
		return (NULL);
	p_src = (unsigned char *)src;
	p_dest = (unsigned char *)dst;
	while (n--)
		*p_dest++ = *p_src++;
	return (dst);
}
