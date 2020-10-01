/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 18:00:13 by blinnea           #+#    #+#             */
/*   Updated: 2020/10/01 19:56:02 by blinnea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H

# define VM_H

# include "libft.h"
# include "op.h"
# include <limits.h>
# include <unistd.h>
# include <stdint.h>

/*
** Change that on blissdeathour branch if needed.
*/
# ifdef MAX_PLAYERS
#  undef MAX_PLAYERS
# endif

# define MAX_PLAYERS (4)

typedef struct s_player	t_player;
typedef struct s_vm		t_vm;

struct					s_player
{
	int			id;
	const char	*fname;
	header_t	header;
	char		exec[CHAMP_MAX_SIZE + 1];
};

t_player				*parse_args(t_acav acav);
bool					init_champs(t_player *pls);

// struct					s_vm
// {
// 	char		*l
// 	char		mem[MEM_SIZE];

// };

#endif
