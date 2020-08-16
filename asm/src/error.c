#include "asm.h"
#include "libft_printf.h"
#include "libft_string.h"
#include <unistd.h>

void	error(int row, int column, char *err)
{
	if (!ft_strcmp(err, LEXICAL_ERROR))
	{
		ft_printf_fd(STDERR_FILENO, "%s [%d %d]\n", err, row, column);
	}
	else
		ft_printf_fd(STDERR_FILENO, "%s\n", err);
	exit(1);
}
