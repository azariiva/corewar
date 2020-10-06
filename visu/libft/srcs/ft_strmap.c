/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaple <rmaple@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 19:42:44 by rmaple            #+#    #+#             */
/*   Updated: 2019/09/23 22:16:08 by rmaple           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strmap(char const *s, char (*f) (char))
{
	char	*str;
	int		i;
	size_t	mem;

	if (s && f)
	{
		i = 0;
		mem = ft_strlen(s);
		str = (char *)malloc(sizeof(char) * (mem + 1));
		if (str == NULL)
			return (NULL);
		while (s[i] != 0)
		{
			str[i] = f(s[i]);
			i++;
		}
		str[i] = '\0';
		return (str);
	}
	return (NULL);
}
