/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 20:30:13 by blinnea           #+#    #+#             */
/*   Updated: 2020/08/15 20:37:38 by blinnea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int	main(int ac, char **av)
{
	t_player	*players;

	players = read_champs((t_acav){.ac = ac, .av = av});
	for (int i = 0; i < MAX_PLAYERS; i++)
	{
		if (players[i].idx)
			ft_printf("%s: %d\n", players[i].fname, players[i].idx);
	}
	return (0);
}
