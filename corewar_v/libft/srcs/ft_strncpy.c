/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaple <rmaple@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 17:44:40 by rmaple            #+#    #+#             */
/*   Updated: 2019/09/20 18:28:12 by rmaple           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strncpy(char *s1, const char *s2, size_t len)
{
	size_t	i;
	int		cpy_end;

	i = 0;
	cpy_end = 0;
	while (i < len)
	{
		if (s2[i] && !cpy_end)
			s1[i] = s2[i];
		else
		{
			s1[i] = '\0';
			cpy_end = 1;
		}
		i++;
	}
	return (s1);
}
