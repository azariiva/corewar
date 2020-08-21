#include "asm.h"

void	instruct_translate(t_parse *parser)
{
	
}

void	translate(t_parse *parser)
{
	t_token	*token;

	while ((token = FT_LSTCONT(t_token, ft_quepop(parser->tokens)))->type !=
	END_FILE)
	{
		if (token->type == INSTRUCTION)
			instruct_translate(parser);
	}
}
