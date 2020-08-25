/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: torange <@student.42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 20:30:13 by blinnea           #+#    #+#             */
/*   Updated: 2020/08/25 18:05:19 by torange          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int	main(int ac, char **av)
{
	t_vm	vm;

	ft_bzero(&vm, sizeof(vm));
	read_champs(&vm, (t_acav){.ac = ac, .av = av});
	if (!init_champs(&vm))
		ft_printf_fd(STDERR_FILENO, "Initialization error\n");
	if (!init_body(&vm))
		ft_printf_fd(STDERR_FILENO, "Initialization error\n");
	for (size_t i = 0; i < vm.psize; i++)
		ft_printf("%d %s\n", vm.pls[i].idx, vm.pls[i].name);
	return (0);
}
