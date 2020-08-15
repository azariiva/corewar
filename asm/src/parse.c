#include "asm.h"

void	str_parse(t_parse *parser, char *line)
{
	char	*newline;
	size_t	size;

	while (!ft_strchr(line + 1, '\"') &&
	(size = get_next_line(parser->fd, &newline)) > 0 && ++parser->row)
		line = ft_strjoin(line, newline);
	ft_printf("big line:%s\n", line);
}

int		parse(t_parse *parser)
{
	size_t	size;
	char	*line;

	while (++parser->row && (size = get_next_line(parser->fd, &line)) > 0)
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
