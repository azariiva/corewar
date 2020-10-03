/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 18:12:50 by blinnea           #+#    #+#             */
/*   Updated: 2020/10/03 14:59:27 by blinnea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pl.h"

inline static void	add_champ(const char*const fname, const uint32_t id,
t_player*const players, bool*const occids)
{
	static uint32_t	pidx;

	if (id < 1 || id > MAX_PLAYERS || occids[id] == true)
	{
		players[pidx++].fname = fname;
		return ;
	}
	players[pidx].id = id;
	players[pidx++].fname = fname;
	occids[id] = true;
}

static void			assign_ids(t_player*const players, bool*const occids,
const uint32_t pidx)
{
	uint32_t	i;
	uint32_t	j;

	i = -1;
	j = 1;
	while (++i < pidx)
	{
		if (!players[i].id)
		{
			while (occids[j] == true)
				++j;
			players[i].id = j;
			occids[j++] = true;
		}
	}
}

static int			cmp(const void *a, const void *b)
{
	t_player	*player_a;
	t_player	*player_b;

	player_a = (t_player *)a;
	player_b = (t_player *)b;
	if (player_a->id == player_b->id)
		return (0);
	return (player_a->id > player_b->id ? 1 : -1);
}
/*
** TODO: add option for visualizer
*/
t_player			*parse_args(t_acav acav)
{
	static t_player	players[MAX_PLAYERS];
	bool			occids[MAX_PLAYERS + 1];
	int				c;
	uint32_t		pidx;

	ft_bzero(occids, sizeof(occids));
	pidx = 0;
	while (pidx <= MAX_PLAYERS)
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
		else if (c == ':')
		{
			ft_printf_fd(STDERR_FILENO, "Option \'-%c\' requires an argument\n",
			g_optopt);
		}
		else if (c == 'n')
		{
			if (ft_strisnum(g_optarg))
			{
				add_champ(acav.av[g_optind++], ft_atou(g_optarg), players,
				occids);
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
	assign_ids(players, occids, pidx);
	FT_QUICKSORT(players, pidx, cmp);
	return (players);
}
