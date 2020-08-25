#include "asm.h"

char	*ft_itoa_base(int value, int base)
{
	char	*s;
	long	n;
	int		sign;
	int		i;

	n = (value < 0) ? -(long)value : value;
	sign = (value < 0 && base == 10) ? -1 : 0;
	i = (sign == -1) ? 2 : 1;
	while ((n /= base) >= 1)
		i++;
	s = (char*)malloc(sizeof(char) * (i + 1));
	s[i] = '\0';
	n = (value < 0) ? -(long)value : value;
	while (i-- + sign)
	{
		s[i] = (n % base < 10) ? n % base + '0' : n % base + 'A' - 10;
		n /= base;
	}
	(i == 0) ? s[i] = '-' : 0;
	return (s);
}

char	*bin2hex(unsigned char num)
{
	int		i;
	int		result;

	i = -1;
	while (++i < 8)
	{
		if (num & (1 << i))
			result += (2 << i);
	}
	return (ft_itoa_base(result, 16));
}

char	*get_arg_type_code(t_parse *parser, t_asop *asop)
{
	t_list			*tokens;
	char			*code;
	int				type;
	unsigned char	x;
	int				n;

	code = NULL;
	x = asop->arg_types;
	tokens = parser->tokens->head;
	while (FT_LSTCONT(t_token, tokens)->type != END_LINE)
	{
		type = get_arg_type(FT_LSTCONT(t_token, tokens));
		if (type & T_IND || type & T_DIR)
			x |= (1 << (x * 2 + 1));
		else if (type & T_REG)
			x |= (1 << (x * 2));
		tokens = tokens->next;
	}
	return (bin2hex(x));
}

void	instruct_translate(t_parse *parser, t_token *token)
{
	t_asop	*asop;
	t_asop	op_name;
	int		type;

	ft_bzero(&op_name, sizeof(t_asop));
	op_name.name = token->content;
	asop = ft_htget(parser->op_htable, &op_name);
	ft_strcat(parser->code, asop->bytecode);
	if (asop->arg_types_code)
		ft_strcat(parser->code, get_arg_type_code(parser, asop));
	while ((token = FT_LSTCONT(t_token, ft_quepop(parser->tokens)))->type !=
	END_LINE)
	{
		type = get_arg_type(token);
		if (type & T_REG)
			ft_strcat(parser->code, ft_itoa_base(ft_atoi(token->content[1]), 16));
		
	}

}

void	translate(t_parse *parser)
{
	t_token	*token;

	while ((token = FT_LSTCONT(t_token, ft_quepop(parser->tokens)))->type !=
	END_FILE)
	{
		if (token->type == INSTRUCTION)
			instruct_translate(parser, token);
	}
}
