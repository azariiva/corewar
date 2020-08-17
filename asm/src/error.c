#include "asm.h"
#include "libft_printf.h"
#include "libft_string.h"
#include <unistd.h>

void	syntax_error(t_parse *parser)
{
	ft_printf_fd(STDERR_FILENO,
	"Syntax error at token [TOKEN][%d:%d] %s \"%s\"",
	parser->row, parser->column,
	TSTR(FT_LSTCONT(t_token, parser->tokens->tail)->type),
	GET_PTOKENS(parser, content, FT_QUETAIL));
	exit(1);
}

void	lex_error(int row, int column)
{
	ft_printf_fd(STDERR_FILENO, "%Lexical error at [%d %d]\n", row, column);
	exit(1);
}

void	error(char *err)
{
	ft_printf_fd(STDERR_FILENO, "%s\n", err);
	exit(1);
}
