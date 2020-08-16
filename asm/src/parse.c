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
		error(parser->row, parser->column + len, LEXICAL_ERROR);
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
		error(parser->row, parser->column + len, LEXICAL_ERROR);
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
		error(parser->row, parser->column + len, LEXICAL_ERROR);
	if (flag)
		GET_PTOKENS(parser, type, FT_QUETAIL) = INSTRUCTION;
	ft_strncpy(GET_PTOKENS(parser, content, FT_QUETAIL),
	line + parser->column, len - parser->column);
	parser->column = len;
}

void	show_tokens(t_parse *parser)
{
	t_queue	*tokens;

	tokens = parser->tokens;
	while (tokens->head)
	{
		ft_printf("[TOKEN][%d:%d] %s %s\n", ((t_token *)tokens->head->content)->row,
		((t_token *)tokens->head->content)->column,
		TSTR(((t_token *)tokens->head->content)->type),
		((t_token *)tokens->head->content)->content);
		tokens->head = tokens->head->next;
	}
}

int		parse(t_parse *parser)
{
	char	*line;
	int		row;

	while (++parser->row && get_next_line(parser->fd, &line) == OK)
	{
		row = parser->row;
		parser->column = 0;
		if (!line[parser->column] && !(parser->tokens &&
		FT_QUETAIL(t_token, parser->tokens)->type == END_LINE))
			add_token(parser, END_LINE);
		while (row == parser->row && line[parser->column])
		{
			pr_skip_space(parser, line);
			pr_skip_comment(parser, line);
			if (line[parser->column])
				pr_gettoken(parser, line);
		}
		ft_strdel(&line);
	}
	show_tokens(parser);
	return (OK);
}
