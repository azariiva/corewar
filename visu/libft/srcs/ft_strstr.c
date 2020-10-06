/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaple <rmaple@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 17:47:09 by rmaple            #+#    #+#             */
/*   Updated: 2019/09/20 18:30:01 by rmaple           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strstr(const char *str, const char *to_find)
{
	int i;
	int pos;
	int len;

	i = 0;
	pos = 0;
	len = 0;
	while (to_find[len] != '\0')
		len++;
	if (len == 0)
		return ((char *)str);
	while (str[i])
	{
		while (to_find[pos] == str[i + pos])
		{
			if (pos == len - 1)
				return ((char *)str + i);
			pos++;
		}
		pos = 0;
		i++;
	}
	return (0);
}
