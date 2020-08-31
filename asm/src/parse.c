#include "asm.h"

void	string_parse(t_parse *parser, char *line)
{
	char	*newline;

	line = line + parser->column + 1;
	while (!ft_strchr(line, '\"') &&
	get_next_line(parser->fdin, &newline) == OK && ++parser->row)
	{
		line = ft_strjoin(line, "\n");
		line = ft_strjoin(line, newline);
		ft_strdel(&newline);
	}
	parser->column += ft_strlen(line) + 1;
	if (ft_strlen(line) > COMMENT_LENGTH)
		error(ERR_LEN_STRING);
	ft_strncpy(GET_PTOKENS(parser, content, FT_QUETAIL), line, ft_strlen(line) - 1);
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

int		is_symbol(char c)
{
	return ((c >= 'a' && c <= 'z') || (c >= '0' && c <= '9') || (c == '_'));
}

void	lable_parse(t_parse *parser, char *line)
{
	int		len;

	len = parser->column + 2;
	while (line[len] && is_symbol(line[len]))
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
	int		curlen;

	curlen = 0;
	len = parser->column + 1;
	while (line[len] && ft_isdigit(line[len++]))
		curlen++;
	return ((curlen > 0 && curlen < 3) ? curlen : 0);
}

void	register_parse(t_parse *parser, char *line)
{
	int		len;

	len = register_len(parser, line);
	ft_strncpy(GET_PTOKENS(parser, content, FT_QUETAIL),
	line + parser->column, len);
	parser->column += len;
}

void	other_parse(t_parse *parser, char *line)
{
	int		len;
	int		flag;

	flag = 0;
	len = line[parser->column] == '-' ? parser->column + 1 : parser->column;
	while (line[len] && is_symbol(line[len]))
	{
		if (ft_isalpha(line[len]))
			flag = 1;
		len++;
	}
	if (line[len] == ':' && len > parser->column)
	{
		GET_PTOKENS(parser, type, FT_QUETAIL) = LABEL;
		parser->label_count++;
		ft_strncpy(GET_PTOKENS(parser, content, FT_QUETAIL),
		line + parser->column, len + 1 - parser->column);
		parser->column += len + 1;
		return ;
	}
	if (line[len] && !ft_isspace(line[len]) && line[len] != SEPARATOR_CHAR &&
	line[len] != DIRECT_CHAR)
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

	while (++parser->row && (size = get_next_line(parser->fdin, &line)) == OK)
	{
		row = parser->row;
		parser->column = 0;
		pr_skip_space(parser, line);
		pr_skip_comment(parser, line);
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
