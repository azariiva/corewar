/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaple <rmaple@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 17:45:43 by rmaple            #+#    #+#             */
/*   Updated: 2019/09/17 21:43:24 by rmaple           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	dest_size;

	i = 0;
	dest_size = 0;
	while (s1[dest_size] != '\0')
		dest_size++;
	while (i < n && s2[i] != '\0')
	{
		s1[dest_size] = s2[i];
		dest_size++;
		i++;
	}
	s1[dest_size] = '\0';
	return (s1);
}
