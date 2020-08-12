#include "asm.h"
#include <fcntl.h>

int	isrighttype(char *name)
{
	if (!ft_strcmp(name + (ft_strlen(name) - 2), ".s"))
		return (1);
	return (0);
}

void	assemble(char *file)
{
	int		fd;

	if (!(fd = open(file, O_RDONLY)))
		ft_printf("File open error\n");

	ft_printf("OK\n");
}
