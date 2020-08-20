/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 18:12:50 by blinnea           #+#    #+#             */
/*   Updated: 2020/08/20 17:29:09 by blinnea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include "libft.h"
#include <stdbool.h>

inline static void	add_champ(const char*const fname, const uint32_t idx,
t_player*const players, bool*const occidxs)
{
	static uint32_t	pidx;

	if (idx < 1 || idx > MAX_PLAYERS || occidxs[idx] == true)
	{
		players[pidx++].fname = fname;
		return ;
	}
	players[pidx].idx = idx;
	players[pidx++].fname = fname;
	occidxs[idx] = true;
}

static void			assign_idxs(t_player*const players, bool*const occidxs,
const uint32_t pidx)
{
	uint32_t	i;
	uint32_t	j;

	i = -1;
	j = 1;
	while (++i < pidx)
	{
		if (!players[i].idx)
		{
			while (occidxs[j] == true)
				++j;
			players[i].idx = j;
			occidxs[j++] = true;
		}
	}
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
t_player			*parse_args(t_acav acav)
{
	static t_player	players[MAX_PLAYERS];
	bool			occidxs[MAX_PLAYERS + 1];
	int				c;
	uint32_t		pidx;

	ft_bzero(occidxs, MAX_PLAYERS * sizeof(*occidxs));
	pidx = 0;
	while (pidx <= MAX_PLAYERS)
	{
		if ((c = ft_getopt(acav, ":n:")) == -1)
		{
			if (acav.av[g_optind] == NULL)
				break;
			else
			{
				add_champ(acav.av[g_optind++], 0, players, occidxs);
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
				occidxs);
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
	assign_idxs(players, occidxs, pidx);
	FT_QUICKSORT(players, pidx, cmp);
	return (players);
}
