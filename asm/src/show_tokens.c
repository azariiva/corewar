#include "asm.h"

void	show_tokens(t_parse *parser)
{
	t_list	*token;

	token = parser->tokens->head;
	while (token)
	{
		ft_printf("[TOKEN][%d:%d] %s %s\n", ((t_token *)token->content)->row,
		((t_token *)token->content)->column,
		TSTR(((t_token *)token->content)->type),
		((t_token *)token->content)->content);
		token = token->next;
	}
}
