/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 18:00:13 by blinnea           #+#    #+#             */
/*   Updated: 2020/10/03 16:42:02 by blinnea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H

# define VM_H

# include "pl.h"

typedef struct s_vm		t_vm;

struct					s_vm
{
	uint8_t		mem[MEM_SIZE];
	t_player	pls[MAX_PLAYERS];
	uint8_t		pls_size;
	t_player	*last_alive; // Why?
	t_list		*cursors;
	size_t		live_execs;
	size_t		curr_cycle;
	ssize_t		cycles_to_die;
	size_t		after_check_cycle;
	uint8_t		checks_num;
	size_t		dump_cycle;
	uint8_t		dump_mode;
};

t_vm	*parse_args(t_acav acav);

#endif
