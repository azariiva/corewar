/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 16:09:17 by blinnea           #+#    #+#             */
/*   Updated: 2020/07/01 19:31:07 by blinnea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	char	*p;
	size_t	i;

	p = s1;
	while (*p)
		++p;
	i = 0;
	while (*s2 && i < n)
		p[i++] = *s2++;
	p[i] = 0;
	return (s1);
}