/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_champs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 18:12:50 by blinnea           #+#    #+#             */
/*   Updated: 2020/08/23 15:19:30 by blinnea          ###   ########.fr       */
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
	players[pidx++].fname = fname;
	occidxs[idx] = true;
}

static int			cmp(const void *a, const void *b)
{
	t_player	*aa;
	t_player	*bb;

	aa = (t_player *)a;
	bb = (t_player *)b;
	if (aa->idx == bb->idx)
		return (0);
	return (aa->idx > bb->idx ? 1 : -1);
}
/*
** TODO: add option for visualizer
*/
t_player			*read_champs(t_acav acav)
{
	static t_player	players[MAX_PLAYERS];
	int				c;
	int				pidx;

	pidx = 0;
	while (1)
	{
		if ((c = ft_getopt(acav, ":n:")) == -1)
		{
			if (acav.av[g_optind] == NULL)
				break;
			else
			{
				add_champ(acav.av[g_optind++], 1, players);
				pidx++;
			}
		}
		else if (c == ':')
		{
			ft_printf_fd(STDERR_FILENO, "Option \'-%c\' requires an argument\n",
			g_optopt);
		}
		else if (c == 'n')
		{
			if (ft_strisnum(g_optarg))
			{
				add_champ(acav.av[++g_optind], ft_atoi(g_optarg), players);
				pidx++;
			}
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
	FT_QUICKSORT(players, pidx, cmp);
	return (players);
}
