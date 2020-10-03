/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_pl.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 14:39:29 by blinnea           #+#    #+#             */
/*   Updated: 2020/10/03 14:54:32 by blinnea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pl.h"

void					show_pl(t_player *pl)
{
	ft_printf("id: %d\n", pl->id);
	ft_printf("filename: %s\n", pl->fname);
	ft_printf("program name: %s\n", pl->header.prog_name);
	ft_printf("program size: %u\n", pl->header.prog_size);
	ft_printf("comment: %s\n", pl->header.comment);
}
