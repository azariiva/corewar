/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstadd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 02:19:28 by blinnea           #+#    #+#             */
/*   Updated: 2020/07/16 02:35:27 by blinnea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_dlist.h"

void	ft_dlstadd(t_dlist **alst, t_dlist *new)
{
	t_dlist	*tmp;

	if (alst && new)
	{
		tmp = *alst;
		*alst = new;
		new->next = tmp;
		tmp->prev = new;
	}
}
