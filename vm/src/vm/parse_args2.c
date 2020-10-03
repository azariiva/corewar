/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 14:56:27 by blinnea           #+#    #+#             */
/*   Updated: 2020/10/03 15:03:38 by blinnea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

inline static void	add_champ(const char*const fname, const uint32_t id,
t_vm*const vm, bool*const occids)
{
	if (id < 1 || id > MAX_PLAYERS || occids[id] == true)
	{
		vm->pls[vm->pls_size++].fname = fname;
		return ;
	}
	players[pidx].id = id;
	players[pidx++].fname = fname;
	occids[id] = true;
}

t_vm	*parse_args2(t_acav acav)
{
	static t_vm	vm;
	bool		occids[MAX_PLAYERS + 1];
	int			c;
	uint32_t	pidx;

	ft_bzero(occids, sizeof(occids));
	while (vm.pls_size <= MAX_PLAYERS)
	{
		if ((c = ft_getopt(acav, ":n:")) == -1)
		{
			if (acav.av[g_optind] == NULL)
				break;
			else
			{
				add_champ(acav.av[g_optind++], 0, players, occids);
				pidx++;
			}
		}
	}
}
