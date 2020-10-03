/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 15:55:37 by blinnea           #+#    #+#             */
/*   Updated: 2020/10/03 17:05:11 by blinnea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURSOR_H

# define CURSOR_H

# include "op.h"
# include <unistd.h>
# include <stdint.h>

# define CORR_PC(pc)((unsigned)(((int)(pc) + MEM_SIZE) % MEM_SIZE))

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

void						init_cursor(t_cursor *c, uint32_t pid, uint32_t pc);

# define INIT_CURSOR(c, pid, pc) (init_cursor(c, pid, CORR_PC(pc)))

void						dup_cursor(t_cursor *c, t_cursor *oc, uint32_t offset);

#endif
