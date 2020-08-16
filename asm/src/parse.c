#include "asm.h"

void	str_parse(t_parse *parser, char *line)
{
	char	*newline;
	size_t	size;

	line = line + parser->column;
	while (!ft_strchr(line + 1, '\"') &&
	(size = get_next_line(parser->fd, &newline)) > 0 && ++parser->row)
	{
		line = ft_strjoin(line, "\n");
		line = ft_strjoin(line, newline);
	}
	
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
