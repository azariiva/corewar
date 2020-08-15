#include "asm.h"

void	pr_skip_space(t_parse *parser, char *line)
{
	while (ft_isspace(line[parser->column]))
		parser->column++;
}

void	pr_skip_comment(t_parse *parser, char *line)
{
	if (line[parser->column] == COMMENT_CHAR ||
	line[parser->column] == ALT_COMMENT_CHAR)
	{
		while (line[parser->column])
			parser->column++;
	}
}
