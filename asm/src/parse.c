#include "asm.h"
#include "libft_get_next_line.h"

void	as_parse(t_parse *parser)
{
	size_t	size;
	char	*line;
	while ((size = get_next_line(parser->fd, &line)) > 0)
	{
		ft_printf("%s\n", line);
	}
}
