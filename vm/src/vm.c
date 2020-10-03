/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhilary <fhilary@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 20:30:13 by blinnea           #+#    #+#             */
/*   Updated: 2020/10/03 16:41:35 by fhilary          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int	main(int ac, char **av)
{
	t_vm	*vm;

	vm = parse_args((t_acav){.ac = ac, .av = av});
	if (init_pls(vm->pls, vm->pls_size) == false)
		return (-1);
	load_pls(vm);
	for (int i = 0; i < vm->pls_size; i++)
	{
		show_pl(vm->pls + i);
		ft_printf("\n");
	}
	return (0);
}
