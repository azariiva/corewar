/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 20:30:13 by blinnea           #+#    #+#             */
/*   Updated: 2020/10/03 15:19:54 by blinnea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int	main(int ac, char **av)
{
	t_vm	*vm;

	vm = parse_args((t_acav){.ac = ac, .av = av});
	init_pls(vm->pls, vm->pls_size);
	for (int i = 0; i < vm->pls_size; i++)
	{
		show_pl(vm->pls + i);
		ft_printf("\n");
	}
	return (0);
}
