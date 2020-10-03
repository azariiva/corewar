/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_pls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhilary <fhilary@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 15:20:25 by fhilary           #+#    #+#             */
/*   Updated: 2020/10/03 16:40:05 by fhilary          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void	load_pl(t_vm *vm, int p)
{
	int		position;

	position = MEM_SIZE / vm->pls_size * p;
	ft_memcpy(vm->mem + position, ((t_player*)(vm->pls + p))->exec,
	((t_player*)(vm->pls + p))->header.prog_size);
}

void		load_pls(t_vm *vm)
{
	uint32_t	i;

	i = -1;
	while (++i < vm->pls_size)
		load_pl(vm, i);
}
