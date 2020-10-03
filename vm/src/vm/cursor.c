/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 16:31:14 by blinnea           #+#    #+#             */
/*   Updated: 2020/10/03 17:05:11 by blinnea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cursor.h"
#include "libft.h"

void	dup_cursor(t_cursor *c, t_cursor *oc, uint32_t offset)
{

	INIT_CURSOR(c, oc->regs[0], c->pc + offset);
	ft_memcpy(c->regs + 1, oc->regs + 1, REG_SIZE * (REG_NUMBER - 1));
	c->carry = oc->carry;
	c->last_report = oc->last_report;
}

void	init_cursor(t_cursor *c, uint32_t pid, uint32_t pc)
{
	static uint32_t		id;

	ft_bzero(c, sizeof(*c));
	c->id = ++id;
	c->pc = pc;
	c->reg[0] = (uint32_t)(-pid);
}
