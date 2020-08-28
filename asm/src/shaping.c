/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shaping.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhilary <fhilary@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/28 14:17:55 by fhilary           #+#    #+#             */
/*   Updated: 2020/08/28 20:33:33 by fhilary          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include <unistd.h>
#include <limits.h>

int		get_arg_type_code(t_parse *parser)
{
	t_list		*tokens;
	int			type;
	int			x;
	int			i;

	x = 0;
	tokens = parser->tokens->head;
	i = 3;
	while (FT_LSTCONT(t_token, tokens)->type != END_LINE)
	{
		type = get_arg_type(FT_LSTCONT(t_token, tokens));
		if (type & T_DIR)
			x |= (1 << (i-- * 2 + 1));
		else if (type & T_REG)
			x |= (1 << (i-- * 2));
		else if (type & T_IND)
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
	else if (token->type == DIRECT)
		wwrite(parser, ft_atoi(&token->content[1]), asop->t_dir_size);
}

void	instruct_shape(t_parse *parser, t_token *token)
{
	t_asop	*asop;
	t_asop	op_name;
	int		type;
	int		x;

	ft_bzero(&op_name, sizeof(t_asop));
	op_name.name = token->content;
	asop = ft_htget(parser->op_htable, &op_name);
	write(parser->fdout, &asop->bytecode, 1);
	if (asop->arg_types_code)
	{
		x = get_arg_type_code(parser);
		write(parser->fdout, &x, 1);
	}
	while ((token = FT_LSTCONT(t_token, ft_quepop(parser->tokens)))->type !=
	END_LINE)
	{
		type = get_arg_type(token);
		if (type & T_REG)
			wwrite(parser, ft_atoi(&token->content[1]), 1);
		else if (type & T_DIR)
			dir_shape(parser, token, asop);
		else if (type & T_IND)
			wwrite(parser, ft_atoi(token->content), 2);
	}
}

void	shaping(t_parse *parser)
{
	t_token	*token;

	wwrite(parser, COREWAR_EXEC_MAGIC, 4);
	write(parser->fdout, parser->name, sizeof(parser->name));
	wwrite(parser, 0, 4);
	wwrite(parser, parser->position, 4);
	write(parser->fdout, parser->comment, sizeof(parser->comment));
	wwrite(parser, 0, 4);
	while ((token = FT_LSTCONT(t_token, ft_quepop(parser->tokens)))->type !=
	END_FILE)
	{
		if (token->type == INSTRUCTION)
			instruct_shape(parser, token);
	}
}
