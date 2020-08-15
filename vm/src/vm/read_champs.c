/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_champs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 18:12:50 by blinnea           #+#    #+#             */
/*   Updated: 2020/08/15 21:06:57 by blinnea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include "libft.h"
#include <unistd.h>
#include <stdbool.h>

inline static void	add_champ(char *fname, int idx, t_player *players)
{
	static bool		occidxs[MAX_PLAYERS];
	static int		pidx;

	if (idx < 1 || idx > MAX_PLAYERS || occidxs[idx] == true)
	{
		idx = 0;
		while (occidxs[idx] == true)
			++idx;
	}
	players[pidx].idx = idx + 1;
	ft_strcpy(players[pidx++].fname, fname);
	occidxs[idx] = true;
}

t_player			*read_champs(t_acav acav)
{
	static t_player	players[MAX_PLAYERS];
	const char		*shortopts = ":n:";
	int				c;

	while (1)
	{
		if ((c = ft_getopt(acav, shortopts)) == -1)
		{
			if (acav.av[g_optind] == NULL)
				break;
			else
				add_champ(acav.av[g_optind++], 1, players);
		}
		else if (c == ':')
		{
			ft_printf_fd(STDERR_FILENO, "Option \'-%c\' requires an argument\n",
			g_optopt);
		}
		else if (c == 'n')
		{
			if (ft_strisnum(g_optarg))
				add_champ(acav.av[++g_optind], ft_atoi(g_optarg), players);
			else
			{
				/*
				** TODO: norme this string.
				*/
				ft_printf_fd(STDERR_FILENO,
				"Option \'-n\' requires number as argument.\nWarning: Argument after \'-n\' ignored!\n");
			}
		}
	}
	return (players);
}
