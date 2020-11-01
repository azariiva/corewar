#include "asm.h"

static void		del(void *content, size_t cs)
{
	if (cs && content)
		ft_memdel(&content);
}

void			queue_del(t_parse *parser)
{
	if (parser->tokens)
		ft_quedel(&(parser->tokens), del);
}
