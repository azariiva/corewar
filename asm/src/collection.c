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

void	test_htable(void)
{
	t_token		test;
	t_htable	*op_htable;
	t_asop		*asop;


	op_htable = get_op_htable();
	ft_bzero(&test, sizeof(t_token));

	const char	*sti = "sti";
	ft_strcpy(test.content, (char *)sti);
	asop = ft_htget(op_htable, &test);
}

void	collection(t_parse *parser)
{
	t_list		*tokens;

	// вот тест htable
	test_htable();

	// не стирай то, что ниже, мне это надо
	info_collect(parser);
	tokens = parser->tokens->head;
	while (FT_LSTCONT(t_token, tokens)->type != END_FILE)
	{
		if (FT_LSTCONT(t_token, tokens)->type == INSTRUCTION)

		tokens = tokens->next;
	}
}
