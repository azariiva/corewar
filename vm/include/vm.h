/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 18:00:13 by blinnea           #+#    #+#             */
/*   Updated: 2020/08/25 14:57:29 by blinnea          ###   ########.fr       */
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

typedef struct			s_vm
{
	t_player	pls[MAX_PLAYERS];
	size_t		psize;
	u_int8_t	body[MEM_SIZE];
}						t_vm;

void					read_champs(t_vm *vm, t_acav acav);
bool					init_champs(t_vm *vm);

#endif
