/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 20:30:13 by blinnea           #+#    #+#             */
/*   Updated: 2020/10/03 14:50:34 by blinnea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int	main(int ac, char **av)
{
	t_player	*players;

	players = parse_args((t_acav){.ac = ac, .av = av});
	init_pls(players);
	for (int i = 0; i < MAX_PLAYERS; i++)
	{
		if (players[i].id)
		{
			show_pl(players + i);
			ft_printf("\n");
		}
	}
	return (0);
}
