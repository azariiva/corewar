/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_htable.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 15:36:37 by fhilary           #+#    #+#             */
/*   Updated: 2020/11/01 14:41:43 by blinnea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int				cmp(const void *a, const void *b)
{
	t_asop	*ta;
	t_asop	*tb;

	ta = (t_asop *)a;
	tb = (t_asop *)b;
	return (ft_strcmp(ta->name, tb->name));
}

static unsigned long	hash(const void *tab, const size_t modulo)
{
	t_asop	*t;

	t = (t_asop *)tab;
	return (ft_strhash(t->name, modulo));
}

static void				del(void *content, size_t cs)
{
	t_asop	*t;

	if (cs && content)
	{
		t = content;
		ft_strdel(&(t->name));
		ft_memdel(&content);
	}
}

void					del_op_htable(t_parse *parser)
{
	if (parser->op_htable)
		ft_htdel(&(parser->op_htable), del);
}

void					get_op_htable(t_parse *parser)
{
	size_t		i;

	parser->op_htable = ft_htnew((sizeof(op_tab) / sizeof(*op_tab)), cmp, hash);
	i = -1;
	while (++i < (sizeof(op_tab) / sizeof(*op_tab)))
		ft_htadd(parser->op_htable, op_tab + i, sizeof(*op_tab));
}
