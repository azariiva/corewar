#include "asm.h"

void	str_parse(t_parse *parser, char *line)
{
	char	*newline;

	line = line + parser->column;
	while (!ft_strchr(line + 1, '\"') &&
	get_next_line(parser->fd, &newline) == OK && ++parser->row)
	{
		line = ft_strjoin(line, "\n");
		line = ft_strjoin(line, newline);
		ft_strdel(&newline);
	}
	parser->column += ft_strlen(line) + 1;
	ft_strcpy(GET_PTOKENS(parser, content, FT_QUETAIL), line);
}

int		parse(t_parse *parser)
{
	char	*line;

	while (++parser->row && get_next_line(parser->fd, &line) == OK)
	{
		while (line[parser->column])
		{
			pr_skip_space(parser, line);
			pr_skip_comment(parser, line);
			if (line[parser->column])
				pr_gettoken(parser, line);
		}
		ft_strdel(&line);
	}
	return (OK);
}
