#include "asm.h"

static void		assemble(char *file)
{
	int		fdin;
	t_parse	parser;

	if (!(fdin = open(file, O_RDONLY)))
		ft_printf("File open error\n");
	ft_bzero(&parser, sizeof(t_parse));
	parser.fd = fdin;
	parse(&parser);
}

int				main(int ac, char **av)
{
	if (ac == 2 && isrighttype(av[1]))
		assemble(av[1]);
	else
		ft_printf("Wrong file type\n");
	return (0);
}
