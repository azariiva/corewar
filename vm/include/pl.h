/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pl.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 14:39:52 by blinnea           #+#    #+#             */
/*   Updated: 2020/10/06 17:16:10 by blinnea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	PL_H

# define PL_H

# include "op.h"
# include <unistd.h>
# include <stdint.h>
# include <stdbool.h>

typedef struct s_player	t_player;

struct					s_player
{
	uint8_t		id;
	const char	*fname;
	header_t	header;
	char		exec[CHAMP_MAX_SIZE + 1];
	size_t		last_report;
	bool		alive;
};

void					show_pl(t_player *pl);

#endif
