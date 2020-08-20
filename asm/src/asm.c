#include "asm.h"

static void		execute(char *file)
{
	t_parse	parser;

	ft_bzero(&parser, sizeof(t_parse));
	if (!(parser.fdin = open(file, O_RDONLY)))
		ft_printf("File open error\n");
	parse(&parser);
	get_op_htable(&parser);
	get_label_htable(&parser);
	collection(&parser);
	if (!(parser.fdout = open(new_filename(file, ".cor"), O_CREAT | O_WRONLY | O_RDONLY)))
		ft_printf("File create error\n");
	translate(&parser);
	// show_tokens(&parser);
}

int				main(int ac, char **av)
{
	if (ac == 2 && isrighttype(av[1]))
		execute(av[1]);
	else
		ft_printf("Wrong file type\n");
	return (0);
}
