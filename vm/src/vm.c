/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 20:30:13 by blinnea           #+#    #+#             */
/*   Updated: 2020/10/01 20:28:53 by blinnea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int	main(int ac, char **av)
{
	t_player	*players;

	players = parse_args((t_acav){.ac = ac, .av = av});
	for (int i = 0; i < MAX_PLAYERS; i++)
	{
		if (players[i].id)
			ft_printf("%d | %s: %d\n", i, players[i].fname, players[i].id);
	}
	return (0);
}
