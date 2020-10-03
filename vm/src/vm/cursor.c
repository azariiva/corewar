/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 16:31:14 by blinnea           #+#    #+#             */
/*   Updated: 2020/10/03 16:37:10 by blinnea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cursor.h"
#include "libft.h"

t_cursor	*init_cursor(uint32_t player_id, uint32_t pc)
{
	t_cursor			*new;
	static uint32_t		id;

	if (!(new = ft_memalloc(sizeof(*new))))
		return (NULL);
	new->id = ++id;
	new->pc = pc;
	cursor->reg[0] = (uint32_t)(-player_id);
	return (cursor);
}
