/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 18:00:13 by blinnea           #+#    #+#             */
/*   Updated: 2020/10/06 17:20:19 by blinnea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H

# define VM_H

# include "cursor.h"
# include "pl.h"
# include "libft.h"
# include <unistd.h>
# include <stdint.h>
# include <stdbool.h>

typedef struct s_cell	t_cell;
typedef struct s_vm		t_vm;

struct					s_cell
{
	uint8_t		data;
	uint8_t		owner;
};

struct					s_vm
{
	t_cell		mem[MEM_SIZE];
	t_player	pls[MAX_PLAYERS];
	uint8_t		pls_size;
	t_player	*last_alive; // Why?
	t_list		*cursors;
	size_t		live_execs;
	size_t		curr_cycle;
	ssize_t		cycles_to_die;
	size_t		after_check_cycle;
	uint8_t		checks_num;
};


t_vm	*init_vm(t_acav acav);
bool	add_cursor(t_vm *vm, t_cursor *c);
void	clear_cursors(t_vm *vm); // Think about replacing this function with macro


#endif
