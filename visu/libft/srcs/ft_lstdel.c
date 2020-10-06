/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaple <rmaple@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 20:57:19 by rmaple            #+#    #+#             */
/*   Updated: 2019/09/17 21:43:24 by rmaple           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*list;
	t_list	*nxtlst;

	list = *alst;
	while (list)
	{
		nxtlst = list->next;
		del(list->content, list->content_size);
		free(list);
		list = nxtlst;
	}
	*alst = NULL;
}
