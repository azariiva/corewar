#include "asm.h"
#include "libft_printf.h"

int			main(int ac, char **av)
{
	if (ac == 2 && isrighttype(av[1]))
		assemble(av[1]);
	else
		ft_printf("Wrong file type\n");
	return (0);
}
