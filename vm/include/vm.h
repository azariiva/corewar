/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 18:00:13 by blinnea           #+#    #+#             */
/*   Updated: 2020/08/23 15:14:25 by blinnea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H

# define VM_H

# include "libft.h"
# include "op.h"
# include <limits.h>
# include <unistd.h>

/*
** Change that on blissdeathour branch if needed.
*/
# ifdef MAX_PLAYERS
#  undef MAX_PLAYERS
# endif

# define MAX_PLAYERS (4)

typedef struct s_player	t_player;

struct					s_player
{
	const char	*fname;
	char		name[PROG_NAME_LENGTH + 1];
	char		comment[COMMENT_LENGTH + 1];
	char		exec[CHAMP_MAX_SIZE + 1];
	int			idx;
};

t_player				*read_champs(t_acav acav);
bool					init_champs(t_player *pls);

#endif
