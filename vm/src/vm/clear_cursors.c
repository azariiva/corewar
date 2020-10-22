/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_cursors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 16:58:51 by blinnea           #+#    #+#             */
/*   Updated: 2020/10/06 17:00:23 by blinnea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void	del(void *c, size_t cs)
{
	if (cs && c)
		ft_memdel(&c);
}

void		clear_cursors(t_vm *vm)
{
	ft_lstdel(&(vm->cursors), del);
}
