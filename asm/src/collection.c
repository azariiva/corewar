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

void	skip_new_line(t_list *tokens)
{
	while (tokens && FT_LSTCONT(t_token, tokens)->type == NEW_LINE)
		tokens = tokens->next;
}

void	lable_collect(t_parse *parser, t_list *tokens)
{
	t_token		*command;
	t_htable	op_htable;
	// int			args;

	get_op_htable(&op_htable);
	if (!ft_strcmp(FT_LSTCONT(t_token, tokens)->content, ft_htget(&op_htable, "sti")))
	{
		ft_printf("OK");
	}

	
	command = FT_LSTCONT(t_token, ft_quepop(parser->tokens));
	// if (command->type == END_LINE)
	// {
	// 	ft_quepop(parser->tokens);
	// 	skip_new_line(parser);
	// }
	// if (command->type != INSTRUCTION)
	// 	syntax_error(parser);
	// while (GET_PTOKENS(parser, type, FT_QUEHEAD) != END_LINE)
	// {
	// 	if (token)
	// 	{

	// 	}
	// 	command = FT_LSTCONT(t_token, ft_quepop(parser->tokens));
	// }
}


void	collection(t_parse *parser)
{
	t_list		*tokens;

	info_collect(parser);
	tokens = parser->tokens->head;
	while (FT_LSTCONT(t_token, tokens)->type != END_FILE)
	{
		if (FT_LSTCONT(t_token, tokens)->type == INSTRUCTION)
			lable_collect(parser, tokens);

		tokens = tokens->next;
	}
}
