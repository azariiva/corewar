/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 15:55:37 by blinnea           #+#    #+#             */
/*   Updated: 2020/10/03 16:42:06 by blinnea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURSOR_H

# define CURSOR_H

# include "op.h"
# include <unistd.h>
# include <stdint.h>

# define CORR_PC(pc)(((int)(pc) + MEM_SIZE) % MEM_SIZE)

typedef struct s_cursor		t_cursor;

struct						s_cursor
{
	uint32_t	id;
	bool		carry;
	uint8_t		op_code;
	size_t		last_report;
	uint8_t		to_exec;
	uint32_t	pc;
	uint32_t	regs[REG_NUMBER];
};

t_cursor					*init_cursor(uint32_t player_id, uint32_t pc);

#endif
