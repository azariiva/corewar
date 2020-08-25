#include "asm.h"

void	info_collect(t_parse *parser)
{
	if (GET_PTOKENS(parser, type, FT_QUEHEAD) == COMMAND_NAME)
	{
		if (ft_strlen(GET_PTOKENS(parser, content, FT_QUEHEAD)) >
		PROG_NAME_LENGTH)
			error(ERR_NAME_LEN);
		ft_quepop(parser->tokens);
		ft_strcpy(parser->name,
		FT_LSTCONT(t_token, ft_quepop(parser->tokens))->content);
		ft_quepop(parser->tokens);
		info_collect(parser);
	}
	else if (GET_PTOKENS(parser, type, FT_QUEHEAD) == COMMAND_COMMENT)
	{
		ft_quepop(parser->tokens);
		ft_strcpy(parser->comment,
		FT_LSTCONT(t_token, ft_quepop(parser->tokens))->content);
		ft_quepop(parser->tokens);
		info_collect(parser);
	}
	else if (!*parser->name || !*parser->comment)
		error(ERR_NO_NAME_OR_COMMENT);
}

void	skip_new_line(t_list **tokens)
{
	while (*tokens && FT_LSTCONT(t_token, *tokens)->type == NEW_LINE)
		*tokens = (*tokens)->next;
}

int		get_arg_type(t_token *token)
{
	if (token->type == INDIRECT)
		return (T_IND);
	else if (token->type == REGISTER)
		return (T_REG);
	else if (token->type == DIRECT_LABEL || token->type == DIRECT)
		return (T_DIR);
	return (0);
}

void	instruction_collect(t_parse *parser, t_list **tokens)
{
	t_asop	*asop;
	t_asop	op_name;
	int		arg_num;
	int		type;

	ft_bzero(&op_name, sizeof(t_asop));
	op_name.name = FT_LSTCONT(t_token, *tokens)->content;
	if (!(asop = ft_htget(parser->op_htable, &op_name)))
		collection_error(ERR_INVALID_INSTRUCT, FT_LSTCONT(t_token, *tokens));
	parser->position++;
	if (asop->arg_types_code)
		parser->position++;
	arg_num = -1;
	while (++arg_num < asop->arg_num)
	{
		*tokens = (*tokens)->next;
		type = get_arg_type(FT_LSTCONT(t_token, *tokens));
		if (!(asop->arg_types[arg_num] & type))
			collection_error(ERR_INVALID_PARAMETP, FT_LSTCONT(t_token, *tokens));
		if (type & T_DIR)
			parser->position += asop->t_dir_size;
		else if (type & T_IND)
			parser->position += T_IND;
		else if (type & T_REG)
			parser->position += T_REG;
		*tokens = (*tokens)->next;
		if (FT_LSTCONT(t_token, *tokens)->type != SEPARATOR &&
		FT_LSTCONT(t_token, *tokens)->type != END_LINE)
			collection_error(ERR_SYNTAX, FT_LSTCONT(t_token, *tokens));
	}
}

void	collection(t_parse *parser)
{
	t_list		*tokens;
	t_lable		lable_name;

	info_collect(parser);
	tokens = parser->tokens->head;
	while (FT_LSTCONT(t_token, tokens)->type != END_FILE)
	{
		if (FT_LSTCONT(t_token, tokens)->type == LABEL)
		{
			ft_bzero(&lable_name, sizeof(t_lable));
			lable_name.name = FT_LSTCONT(t_token, tokens)->content;
			((t_lable *)ft_htget(parser->lables_htable, &lable_name))->lab_pos =
			parser->position;
			tokens = tokens->next;
			if (FT_LSTCONT(t_token, tokens)->type == END_LINE)
				tokens = tokens->next;
		}
		skip_new_line(&tokens);
		if (FT_LSTCONT(t_token, tokens)->type == INSTRUCTION)
			instruction_collect(parser, &tokens);
		else
			collection_error(parser, FT_LSTCONT(t_token, tokens));
		tokens = tokens->next;
	}
}
