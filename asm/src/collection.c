/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhilary <fhilary@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 14:49:13 by fhilary           #+#    #+#             */
/*   Updated: 2020/11/05 21:57:12 by fhilary          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void champ_info_collect(t_parse *parser)
{
	int		name;
	int		comment;
	t_token	*token;
	t_token	*string;

	coll_skip_tokens(parser);
	name = 0;
	comment = 0;
	while (!name || !comment)
	{
		token = FT_LSTCONT(t_token, ft_quepop(parser->tokens));
		if (token->type == COMMAND_NAME)
		{
			name = 1;
			if ((string = FT_LSTCONT(t_token, ft_quepop(parser->tokens)))->type
			!= STRING)
				error(ERR_NO_NAME_OR_COMMENT, parser);
			if (ft_strlen(string->content) > PROG_NAME_LENGTH)
				error(ERR_NAME_LEN, parser);
			ft_strcpy(parser->name, string->content);
		}
		else if (token->type == COMMAND_COMMENT)
		{
			comment = 1;
			if ((string = FT_LSTCONT(t_token, ft_quepop(parser->tokens)))->type
			!= STRING)
				error(ERR_NO_NAME_OR_COMMENT, parser);
			ft_strcpy(parser->comment, string->content);
		}
		else if (token->type != END_LINE && token->type != NEW_LINE)
			error(ERR_NO_NAME_OR_COMMENT, parser);
	}
}

static void	mention_collect(t_parse *parser, t_list *token, int pos, int size)
{
	t_lable	*lable;
	t_lable	lable_name;

	parser->position += size;
	if (!(FT_LSTCONT(t_token, token)->type == DIRECT_LABEL ||
	FT_LSTCONT(t_token, token)->type == INDIRECT_LABLE))
		return ;
	ft_bzero(&lable_name, sizeof(t_lable));
	if (FT_LSTCONT(t_token, token)->type == DIRECT_LABEL)
		ft_strcat(lable_name.name, token->content + 2);
	else
		ft_strcat(lable_name.name, token->content + 1);
	if (!(lable = ft_htget(parser->lables, &lable_name)))
		collection_error(ERR_INV_LABLE, FT_LSTCONT(t_token, token), parser);
	lable->mentions[lable->size++] = pos;
}

void		instruction_collect(t_parse *parser, t_list **tokens)
{
	t_asop	*asop;
	t_asop	op_name;
	int		arg_num;
	int		pos;

	ft_bzero(&op_name, sizeof(t_asop));
	op_name.name = FT_LSTCONT(t_token, *tokens)->content;
	if (!(asop = ft_htget(parser->op_htable, &op_name)))
		collection_error(ERR_INV_INST, FT_LSTCONT(t_token, *tokens), parser);
	pos = parser->position++;
	parser->position += (asop->arg_types_code) ? 1 : 0;
	arg_num = -1;
	while (++arg_num < asop->arg_num)
	{
		*tokens = (*tokens)->next;
		if (!(asop->arg_types[arg_num] & get_arg_type(*tokens)))
			collection_error(ERR_INV_PRM, FT_LSTCONT(t_token, *tokens), parser);
		if (get_arg_type(*tokens) & T_DIR)
			mention_collect(parser, *tokens, pos, asop->t_dir_size);
		else if (get_arg_type(*tokens) & T_IND)
			mention_collect(parser, *tokens, pos, 2);
		else if (get_arg_type(*tokens) & T_REG)
			parser->position += 1;
		*tokens = (*tokens)->next;
		if (FT_LSTCONT(t_token, *tokens)->type != SEPARATOR &&
		FT_LSTCONT(t_token, *tokens)->type != END_LINE)
			collection_error(ERR_SYNTAX, FT_LSTCONT(t_token, *tokens), parser);
	}
	if (FT_LSTCONT(t_token, *tokens)->type != END_LINE)
		collection_error(ERR_SYNTAX, FT_LSTCONT(t_token, *tokens), parser);
}

void		collection(t_parse *parser)
{
	t_list		*tokens;
	t_lable		lable_name;

	champ_info_collect(parser);
	tokens = parser->tokens->head;
	while (tokens && FT_LSTCONT(t_token, tokens)->type != END_FILE)
	{
		if (FT_LSTCONT(t_token, tokens)->type == LABEL)
		{
			ft_bzero(&lable_name, sizeof(t_lable));
			ft_strncat(lable_name.name, FT_LSTCONT(t_token, tokens)->content,
			ft_strlen(FT_LSTCONT(t_token, tokens)->content) - 1);
			((t_lable *)ft_htget(parser->lables, &lable_name))->lab_pos =
			parser->position;
		}
		else if (FT_LSTCONT(t_token, tokens)->type == INSTRUCTION)
			instruction_collect(parser, &tokens);
		tokens = tokens->next;
	}
}
