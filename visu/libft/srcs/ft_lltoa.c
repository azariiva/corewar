/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: torange <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 18:34:07 by torange           #+#    #+#             */
/*   Updated: 2020/02/10 18:34:11 by torange          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char			*ft_lltoa(long long n)
{
	char		*s;
	size_t		len;
	long long	tmp;

	len = (n <= 0);
	tmp = n;
	while (tmp)
	{
		++len;
		tmp /= 10;
	}
	if (!(s = ft_strnew(len)))
		return (0);
	tmp = len - 2;
	s[len - 1] = ft_llabs(n % 10) + '0';
	if (n < 0)
		s[0] = '-';
	n = ft_llabs(n / 10);
	while (n)
	{
		s[tmp--] = n % 10 + '0';
		n /= 10;
	}
	return (s);
}
