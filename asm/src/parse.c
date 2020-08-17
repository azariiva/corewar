#include "asm.h"

void	string_parse(t_parse *parser, char *line)
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
	if (ft_strlen(line) > COMMENT_LENGTH)
		error(ERR_LEN_STRING);
	ft_strcpy(GET_PTOKENS(parser, content, FT_QUETAIL), line);
}

void	number_parse(t_parse *parser, char *line)
{
	int		len;

	len = parser->column + 1;
	if (line[len] == '-')
		len++;
	while (line[len] && ft_isdigit(line[len]))
		len++;
	if (line[len] && !ft_isspace(line[len]) && line[len] != '-' &&
	line[len] != SEPARATOR_CHAR)
		lex_error(parser->row, parser->column + len);
	ft_strncpy(GET_PTOKENS(parser, content, FT_QUETAIL),
	line + parser->column, len - parser->column);
	parser->column = len;
}

void	lable_parse(t_parse *parser, char *line)
{
	int		len;

	len = parser->column + 2;
	while (line[len] && (ft_isalpha(line[len]) || ft_isdigit(line[len])))
		len++;
	if (line[len] && !ft_isspace(line[len]) && line[len] != '-' &&
	line[len] != SEPARATOR_CHAR)
		lex_error(parser->row, parser->column + len);
	ft_strncpy(GET_PTOKENS(parser, content, FT_QUETAIL),
	line + parser->column, len - parser->column);
	parser->column = len;
}

int		register_len(t_parse *parser, char *line)
{
	int		len;

	len = parser->column + 1;
	while (line[len] && !ft_isspace(line[len]) &&
	ft_isdigit(line[len]))
	{
		len++;
	}
	if (len - parser->column == 2)
		return (len - parser->column + 1);
	return (0);
}

void	register_parse(t_parse *parser, char *line)
{
	int		len;

	len = register_len(parser, line) - 1;
	GET_PTOKENS(parser, type, FT_QUETAIL) = REGISTER;
	ft_strncpy(GET_PTOKENS(parser, content, FT_QUETAIL),
	line + parser->column, len);
	parser->column += len;
	return ;
}

void	other_parse(t_parse *parser, char *line)
{
	int		len;
	int		flag;

	flag = 0;
	len = parser->column - 1;
	while (line[++len] && (ft_isalpha(line[len]) || ft_isdigit(line[len])))
	{
		if (ft_isalpha(line[len]))
			flag = 1;
	}
	if (line[len] == ':')
	{
		GET_PTOKENS(parser, type, FT_QUETAIL) = LABEL;
		ft_strncpy(GET_PTOKENS(parser, content, FT_QUETAIL),
		line + parser->column, len + 1 - parser->column);
		parser->column += len + 1;
		return ;
	}
	if (line[len] && !ft_isspace(line[len]) && line[len] != '-' &&
	line[len] != SEPARATOR_CHAR)
		lex_error(parser->row, parser->column + len);
	if (flag)
		GET_PTOKENS(parser, type, FT_QUETAIL) = INSTRUCTION;
	ft_strncpy(GET_PTOKENS(parser, content, FT_QUETAIL),
	line + parser->column, len - parser->column);
	parser->column = len;
}

void	parse(t_parse *parser)
{
	char	*line;
	int		row;
	size_t	size;

	while (++parser->row && (size = get_next_line(parser->fd, &line)) == OK)
	{
		row = parser->row;
		parser->column = 0;
		if (!line[parser->column] && !(parser->tokens &&
		FT_QUETAIL(t_token, parser->tokens)->type == NEW_LINE))
			add_token(parser, NEW_LINE);
		while (row == parser->row && line[parser->column])
		{
			pr_skip_space(parser, line);
			pr_skip_comment(parser, line);
			if (line[parser->column])
				pr_gettoken(parser, line);
		}
		if (GET_PTOKENS(parser, type, FT_QUETAIL) != NEW_LINE)
			add_token(parser, END_LINE);
		ft_strdel(&line);
	}
	if ((int)size == ERR)
		error(ERR_READ_FILE);
	if (size == END)
		add_token(parser, END_FILE);
}
