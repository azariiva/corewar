/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cap_lftoa2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: torange <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 19:45:47 by torange           #+#    #+#             */
/*   Updated: 2020/02/11 19:45:49 by torange          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdlib.h>

int		ft_cap_lftoa_rounding(long double f_part_c, int precision,
				long double *f_part, long long *i_part)
{
	long long	n;

	n = (long long)f_part_c % 10;
	f_part_c = f_part_c * 10;
	if (((long long)f_part_c) % 10 >= 5)
	{
		if (precision > 0)
		{
			(*f_part) += 0.1;
			if (n == 9)
				return (1);
		}
		else if ((*i_part) < 0)
			(*i_part)--;
		else
			(*i_part)++;
	}
	return (0);
}

void	ft_cap_lftoa_add_number(int *i, char **result, long double *f_part)
{
	*f_part *= 10;
	(*result)[*i] = (long long)*f_part % 10 + '0';
	*f_part -= (long long)*f_part % 10;
	(*result)[*i + 1] = '\0';
}

void	round_first_chars(int i, char **result, char **tmp)
{
	if ((*result)[i] == '-')
	{
		(*result)[i] = '1';
		*tmp = ft_strjoin("-", *result);
		free(*result);
	}
	else if (i == 0)
	{
		if ((*result)[i] == '9')
		{
			(*result)[i] = '0';
			*tmp = ft_strjoin("1", *result);
			free(*result);
		}
		else
			(*result)[i] += 1;
	}
	else
	{
		(*result)[i] += 1;
		*tmp = ft_strdup(*result);
		free(*result);
	}
}

void	ft_cap_lftoa_set_other_nums(int i, char **result)
{
	char	*tmp;

	i--;
	tmp = NULL;
	while (((*result)[i] == '9' || (*result)[i] == '.') && i)
	{
		if ((*result)[i] == '.')
		{
			i--;
			continue;
		}
		(*result)[i] -= 9;
		i--;
	}
	round_first_chars(i, result, &tmp);
	*result = ft_strjoin(tmp, "0");
	free(tmp);
}
