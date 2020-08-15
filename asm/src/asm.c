#include "asm.h"

static int		assemble(char *file)
{
	int		fdin;
	t_parse	*parser;

	if (!(fdin = open(file, O_RDONLY)))
		ft_printf("File open error\n");
	parser = (t_parse *)malloc(sizeof(t_parse));
	parser->row = 0;
	parser->column = 0;
	parser->fd = fdin;
	parser->tokens = NULL;
	if (!(parser->name = ft_memalloc(sizeof(char) * PROG_NAME_LENGTH)) ||
	!(parser->comment = ft_memalloc(sizeof(char) * COMMENT_LENGTH)))
		return (ERR);
	parse(parser);
	ft_printf("OK\n");
	return (OK);
}

int				main(int ac, char **av)
{
	if (ac == 2 && isrighttype(av[1]))
		assemble(av[1]);
	else
		ft_printf("Wrong file type\n");
	return (0);
}
