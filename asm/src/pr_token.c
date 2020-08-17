#include "asm.h"

void			add_token(t_parse *parser, t_type type)
{
	t_token token;

	ft_bzero(&token, sizeof(token));
	token.type = type;
	token.row = parser->row;
	token.column = parser->column + 1;
	if (!parser->tokens)
		parser->tokens = ft_quenew(&token, sizeof(t_token));
	else
		ft_quevadd(parser->tokens, &token, sizeof(t_token));
	if (type == SEPARATOR)
		parser->column++;
	else if (type == COMMAND_NAME)
		parser->column += 5;
	else if (type == COMMAND_COMMENT)
		parser->column += 8;
}

void			pr_gettoken(t_parse *parser, char *line)
{
	if (line[parser->column] == '\n' &&
	!(parser->tokens && FT_QUETAIL(t_token, parser->tokens)->type == NEW_LINE))
		add_token(parser, NEW_LINE);
	else if (line[parser->column] == SEPARATOR_CHAR)
		add_token(parser, SEPARATOR);
	else if (ft_strnstr(line, NAME_CMD_STRING, 5) &&
	!(parser->tokens && FT_QUETAIL(t_token, parser->tokens)->type == COMMAND_NAME))
		add_token(parser, COMMAND_NAME);
	else if (ft_strnstr(line, COMMENT_CMD_STRING, 8) &&
	!(parser->tokens && FT_QUETAIL(t_token, parser->tokens)->type == COMMAND_COMMENT))
		add_token(parser, COMMAND_COMMENT);
	else if (line[parser->column] == '\"')
	{
		add_token(parser, STRING);
		string_parse(parser, line);
	}
	else if (line[parser->column] == DIRECT_CHAR)
	{
		if (line[parser->column + 1] == LABEL_CHAR)
		{
			add_token(parser, DIRECT_LABEL);
			lable_parse(parser, line);
		}
		else
		{
			add_token(parser, DIRECT);
			number_parse(parser, line);
		}
	}
	else if (line[parser->column] == 'r' && register_len(parser, line))
	{
		add_token(parser, REGISTER);
		register_parse(parser, line);
	}
	else
	{
		add_token(parser, INDIRECT);
		other_parse(parser, line);
	}
}

