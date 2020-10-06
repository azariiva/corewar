/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaple <rmaple@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 17:47:34 by rmaple            #+#    #+#             */
/*   Updated: 2019/09/17 21:43:24 by rmaple           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t n)
{
	size_t	len;

	if (*to_find == '\0')
		return ((char *)str);
	len = ft_strlen(to_find);
	while (*str != '\0' && n-- >= len)
	{
		if (*str == *to_find && ft_memcmp(str, to_find, len) == 0)
			return ((char *)str);
		str++;
	}
	return (NULL);
}
