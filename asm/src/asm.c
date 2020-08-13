#include "asm.h"

static void		assemble(char *file)
{
	int		fd1;
	int		fd2;

	if (!(fd1 = open(file, O_RDONLY)))
		ft_printf("File open error\n");
	if (!(fd2 = open(new_filename(file, ".cor"), O_CREAT | O_WRONLY | O_RDONLY)))
		ft_printf("File open error\n");
	parse(fd1, fd2);
	ft_printf("OK\n");
}

int				main(int ac, char **av)
{
	if (ac == 2 && isrighttype(av[1]))
		assemble(av[1]);
	else
		ft_printf("Wrong file type\n");
	return (0);
}
