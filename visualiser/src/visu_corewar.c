/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu_corewar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhitmonc <lhitmonc@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 19:31:23 by lhitmonc          #+#    #+#             */
/*   Updated: 2020/08/08 18:36:18 by lhitmonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu_corewar.h"

int		main(int ac, char **av)
{
	t_window	window;

	init(&window);
	make_background(&window);
	show_corewar(&window);
	quit(&window);
	return (0);
}
