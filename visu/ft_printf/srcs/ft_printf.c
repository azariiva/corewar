/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: torange <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 18:38:36 by torange           #+#    #+#             */
/*   Updated: 2020/02/12 19:10:27 by torange          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	if_conversion(t_pf *pf, const char *fmt, va_list va, int *i)
{
	parse_placeholder(pf, fmt, va, i);
	if (pf->data_type > 0)
		print_placeholder(pf, va);
	if (pf->data_type == -1 && fmt[*i])
		print_txt_c(pf, fmt[*i]);
	pf->flag = 0;
	pf->width = 0;
	pf->prec = 0;
	pf->mod = 0;
	pf->data_type = 0;
}

static int	loop_format(t_pf *pf, const char *fmt, va_list va)
{
	int	i;

	i = 0;
	while (fmt[i])
	{
		if (fmt[i] == '{')
			print_color(pf, fmt, &i);
		if (fmt[i] != '%')
			pf->len += ft_putchar_buf(&(pf->buf), fmt[i]);
		if (fmt[i] == '%')
			if_conversion(pf, fmt, va, &i);
		if (fmt[i])
			i++;
	}
	return (0);
}

int			ft_printf(const char *fmt, ...)
{
	int		length;
	t_pf	*pf;
	va_list	va;

	if (!fmt)
		return (-1);
	if ((pf = (t_pf*)malloc(sizeof(t_pf))) == NULL)
		return (-1);
	ft_bzero(pf, sizeof(t_pf));
	va_start(va, fmt);
	if (loop_format(pf, fmt, va))
		return (-1);
	ft_fflush(&(pf->buf));
	va_end(va);
	length = pf->len;
	free(pf);
	return (length);
}
