/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   label_htable.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhilary <fhilary@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 15:36:03 by fhilary           #+#    #+#             */
/*   Updated: 2020/09/01 15:37:06 by fhilary          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int				cmp(const void *a, const void *b)
{
	t_lable	*ta;
	t_lable	*tb;

	ta = (t_lable *)a;
	tb = (t_lable *)b;
	return (ft_strcmp(ta->name, tb->name));
}

static unsigned long	hash(const void *tab, const size_t modulo)
{
	t_lable	*t;

	t = (t_lable *)tab;
	return (ft_strhash(t->name, modulo));
}

static void				del(void *content, size_t cs)
{
	t_lable	*t;

	if (cs && content)
	{
		t = content;
		ft_memdel(&content);
	}
}

void					del_lable_htable(t_parse *parser)
{
	ft_htdel(&parser->lables, del);
}

void					get_label_htable(t_parse *parser)
{
	t_list		*tokens;
	t_lable		lable;

	parser->lables = ft_htnew(parser->label_count, cmp, hash);
	tokens = parser->tokens->head;
	while (tokens)
	{
		if (FT_LSTCONT(t_token, tokens)->type == LABEL)
		{
			ft_bzero(&lable, sizeof(lable));
			ft_strncat(lable.name, FT_LSTCONT(t_token, tokens)->content,
			ft_strlen(FT_LSTCONT(t_token, tokens)->content) - 1);
			lable.lab_pos = 0;
			lable.size = 0;
			lable.m_position = 0;
			ft_htadd(parser->lables, &lable, sizeof(lable));
		}
		tokens = tokens->next;
	}
}
