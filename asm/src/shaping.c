/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shaping.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhilary <fhilary@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/28 14:17:55 by fhilary           #+#    #+#             */
/*   Updated: 2020/09/01 15:17:32 by fhilary          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include <unistd.h>
#include <limits.h>

int		get_arg_type_code(t_parse *parser)
{
	t_list		*tokens;
	int			x;
	int			i;

	x = 0;
	tokens = parser->tokens->head;
	i = 3;
	while (FT_LSTCONT(t_token, tokens)->type != END_LINE)
	{
		if (get_arg_type(tokens) & T_DIR)
			x |= (1 << (i-- * 2 + 1));
		else if (get_arg_type(tokens) & T_REG)
			x |= (1 << (i-- * 2));
		else if (get_arg_type(tokens) & T_IND)
		{
			x |= (1 << (i * 2));
			x |= (1 << (i-- * 2 + 1));
		}
		tokens = tokens->next;
	}
	return (x);
}

void	wwrite(t_parse *parser, int n, int size)
{
	short	n1;

	if (size == 2)
	{
		n1 = (short)n;
		n1 = REV_2(n1);
		write(parser->fdout, &n1, size);
		return ;
	}
	if (size == 4)
		n = REV_4(n);
	write(parser->fdout, &n, size);
}

void	dir_shape(t_parse *parser, t_token *token, t_asop *asop)
{
	t_lable	*lable;
	t_lable	lable_name;

	if (token->type == DIRECT_LABEL)
	{
		ft_bzero(&lable_name, sizeof(t_lable));
		ft_strcat(lable_name.name, token->content + 2);
		lable = ft_htget(parser->lables, &lable_name);
		wwrite(parser, lable->lab_pos - lable->mentions[lable->m_position++],
		asop->t_dir_size);
	}
	else
		wwrite(parser, ft_atoi(&token->content[1]), asop->t_dir_size);
}

void	ind_shape(t_parse *parser, t_token *token)
{
	t_lable	*lable;
	t_lable	lable_name;

	if (token->type == INDIRECT_LABLE)
	{
		ft_bzero(&lable_name, sizeof(t_lable));
		ft_strcat(lable_name.name, token->content + 1);
		lable = ft_htget(parser->lables, &lable_name);
		wwrite(parser, lable->lab_pos - lable->mentions[lable->m_position++],
		2);
	}
	else
		wwrite(parser, ft_atoi(token->content), 2);
}

void	instruct_shape(t_parse *parser, t_list *token)
{
	t_asop	*asop;
	t_asop	op_name;

	ft_bzero(&op_name, sizeof(t_asop));
	op_name.name = FT_LSTCONT(t_token, token)->content;
	asop = ft_htget(parser->op_htable, &op_name);
	wwrite(parser, asop->bytecode, 1);
	if (asop->arg_types_code)
		wwrite(parser, get_arg_type_code(parser), 1);
	while (FT_LSTCONT(t_token, (token = ft_quepop(parser->tokens)))->type !=
	END_LINE)
	{
		if (get_arg_type(token) & T_REG)
			wwrite(parser, ft_atoi(&FT_LSTCONT(t_token, token)->content[1]), 1);
		else if (get_arg_type(token) & T_DIR)
			dir_shape(parser, FT_LSTCONT(t_token, token), asop);
		else if (get_arg_type(token) & T_IND)
			ind_shape(parser, FT_LSTCONT(t_token, token));
	}
}

void	shaping(t_parse *parser)
{
	t_list	*token;

	wwrite(parser, COREWAR_EXEC_MAGIC, 4);
	write(parser->fdout, parser->name, sizeof(parser->name));
	wwrite(parser, 0, 4);
	wwrite(parser, parser->position, 4);
	write(parser->fdout, parser->comment, sizeof(parser->comment));
	wwrite(parser, 0, 4);
	while (FT_LSTCONT(t_token, token = ft_quepop(parser->tokens))->type !=
	END_FILE)
	{
		if (FT_LSTCONT(t_token, token)->type == INSTRUCTION)
			instruct_shape(parser, token);
	}
}
