#include "asm.h"



int		get_arg_type_code(t_parse *parser)
{
	t_list		*tokens;
	int			type;
	int			x;
	int			i;

	x = 0;
	tokens = parser->tokens->head;
	i = 3;
	while (FT_LSTCONT(t_token, tokens)->type != END_LINE)
	{
		type = get_arg_type(FT_LSTCONT(t_token, tokens));
		if (type & T_DIR)
			x |= (1 << (i-- * 2 + 1));
		else if (type & T_REG)
			x |= (1 << (i-- * 2));
		else if (type & T_IND)
		{
			x |= (1 << (i * 2));
			x |= (1 << (i-- * 2 + 1));
		}
		tokens = tokens->next;
	}
	return (x);
}

void	add_elem(t_parse *parser, int elem)
{
	parser->code->content[parser->code->position++] = elem;
}

void	dir_shape(t_parse *parser, t_token *token)
{
	t_lable	*lable;
	t_lable	lable_name;

	if (token->type == DIRECT_LABEL)
	{
		ft_bzero(&lable_name, sizeof(t_lable));
		ft_strcat(lable_name.name, token->content + 2);
		if (!(lable = ft_htget(parser->lables, &lable_name)))
			collection_error(ERR_INVALID_LABLE, token);
		add_elem(parser, lable->lab_pos - lable->mentions[lable->m_position++]);
	}
	else if (token->type == DIRECT)
		add_elem(parser, ft_atoi(&token->content[1]));
}

void	instruct_shape(t_parse *parser, t_token *token)
{
	t_asop	*asop;
	t_asop	op_name;
	int		type;
	int		x;

	ft_bzero(&op_name, sizeof(t_asop));
	op_name.name = token->content;
	asop = ft_htget(parser->op_htable, &op_name);
	add_elem(parser, asop->bytecode);
	if (asop->arg_types_code)
		add_elem(parser, get_arg_type_code(parser));
	while ((token = FT_LSTCONT(t_token, ft_quepop(parser->tokens)))->type !=
	END_LINE)
	{
		type = get_arg_type(token);
		if (type & T_REG)
		{
			x = ft_atoi(&token->content[1]);
			x &= 0xff;
			add_elem(parser, x);
		}
		else if (type & T_DIR)
			dir_shape(parser, token);
		else if (type & T_IND)
			add_elem(parser, ft_atoi(token->content));
	}
}

void	shaping(t_parse *parser)
{
	t_token	*token;

	parser->code = ft_memalloc(sizeof(t_code));
	ft_bzero(parser->code, sizeof(t_code));
	while ((token = FT_LSTCONT(t_token, ft_quepop(parser->tokens)))->type !=
	END_FILE)
	{
		if (token->type == INSTRUCTION)
			instruct_shape(parser, token);
	}
}
