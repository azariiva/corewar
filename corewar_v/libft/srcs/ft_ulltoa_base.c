/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulltoa_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: torange <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 18:34:34 by torange           #+#    #+#             */
/*   Updated: 2020/02/10 18:36:51 by torange          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static char	tobase(unsigned digit)
{
	if (digit <= 9)
		return (digit + '0');
	return (digit - 10 + 'a');
}

static void	fill_arr(char *arr, unsigned long long num, unsigned base, \
		unsigned len)
{
	unsigned i;

	i = len;
	arr[i--] = 0;
	while (num)
	{
		arr[i--] = tobase(num % base);
		num /= base;
	}
}

char		*ft_ulltoa_base(unsigned long long num, int base)
{
	unsigned long long	tmp;
	char				*arr;
	size_t				len;

	len = (num <= 0);
	tmp = num;
	while (tmp)
	{
		++len;
		tmp /= base;
	}
	arr = ft_strnew(len);
	if (num == 0)
		arr[0] = '0';
	fill_arr(arr, num, base, len);
	return (arr);
}
