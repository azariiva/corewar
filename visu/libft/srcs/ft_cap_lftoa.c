/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cap_lftoa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: torange <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 19:45:16 by torange           #+#    #+#             */
/*   Updated: 2020/02/11 19:45:18 by torange          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdlib.h>

static int		countnumbers(long long n)
{
	int	result;

	result = 0;
	if (n <= 0)
		result = 1;
	while (n != 0)
	{
		n /= 10;
		result++;
	}
	return (result);
}

static void		reverse_string(char *str)
{
	char	temp;
	int		index;
	int		index2;
	int		length;

	temp = 0;
	length = 0;
	index = 0;
	while (str[length + 1])
		length++;
	index2 = length;
	while (index < index2)
	{
		temp = str[index];
		str[index++] = str[index2];
		str[index2--] = temp;
	}
}

int				inttostr(long long x, char *result, int d)
{
	int			index;
	long long	temp;

	index = 0;
	temp = x;
	if (x == 0)
		result[index++] = '0';
	if (x < 0)
		x *= -1;
	while (x != 0)
	{
		result[index++] = (x % 10) + '0';
		x /= 10;
	}
	while (index < d)
	{
		result[index] = '0';
		index++;
	}
	if (temp < 0)
		result[index++] = '-';
	result[index] = '\0';
	reverse_string(result);
	return (index);
}

void			fill_result(long long i_part, long double f_part,
							int precision, char **result)
{
	int	i;

	i = inttostr(i_part, *result, 0);
	if (precision >= 1)
		(*result)[i] = '.';
	while (precision > 1)
	{
		i++;
		ft_cap_lftoa_add_number(&i, result, &f_part);
		precision--;
	}
	if (precision == 1)
	{
		i++;
		if (ft_cap_lftoa_rounding(f_part * 10, precision, &f_part, &i_part))
			ft_cap_lftoa_set_other_nums(i, result);
		else
			ft_cap_lftoa_add_number(&i, result, &f_part);
	}
}

char			*ft_cap_lftoa(long double n, int precision)
{
	long long	i_part;
	long double	f_part;
	char		*result;

	i_part = (long long)n;
	f_part = n - (long double)i_part;
	result = (char*)malloc(countnumbers(i_part) + precision + 2);
	if (!result)
		return (NULL);
	if (f_part < 0)
		f_part *= -1;
	if (precision <= 0)
		ft_cap_lftoa_rounding(f_part, precision, &f_part, &i_part);
	fill_result(i_part, f_part, precision, &result);
	return (result);
}
