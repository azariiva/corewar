/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_cursor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 16:59:12 by blinnea           #+#    #+#             */
/*   Updated: 2020/10/03 17:07:35 by blinnea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

bool	add_cursor(t_vm *vm, t_cursor *c)
{
	t_list	*new;

	if (!(new = ft_lstnew((void *)c, sizeof(*c))))
		return (false);
	ft_lstadd(&(vm->cursors), new);
	return (true);
}

