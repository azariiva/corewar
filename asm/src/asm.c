#include "asm.h"
#include <unistd.h>

void	show_tokens(t_parse *parser)
{
	t_list	*token;

	token = parser->tokens->head;
	while (token)
	{
		ft_printf("[TOKEN][%d:%d] %s %s\n", ((t_token *)token->content)->row,
		((t_token *)token->content)->column,
		TSTR(((t_token *)token->content)->type),
		((t_token *)token->content)->content);
		token = token->next;
	}
}

static void		execute(char *file)
{
	t_parse	parser;

	ft_bzero(&parser, sizeof(t_parse));
	if (!(parser.fdin = open(file, O_RDONLY)))
		error(ERR_OPEN_FILE);
	parse(&parser);
	// show_tokens(&parser);
	get_op_htable(&parser);
	get_label_htable(&parser);
	collection(&parser);
	if (!(parser.fdout = open(new_filename(file, ".cor"), O_CREAT | O_TRUNC | O_WRONLY, 0644)))
		error(ERR_CREATE_FILE);
	if (parser.position > CHAMP_MAX_SIZE)
		error(ERR_INVALID_CODE_SIZE);
	shaping(&parser);
	ft_printf("Writing output program to %s\n", new_filename(file, ".cor"));
	close(parser.fdin);
	close(parser.fdout);
}

int				main(int ac, char **av)
{
	if (ac == 2 && isrighttype(av[1]))
		execute(av[1]);
	else
		ft_printf("Wrong file type\n");
	return (0);
}
