#include "asm.h"

static void		del(void *content, size_t cs)
{
	t_token	*t;

	if (cs && content)
	{
		t = content;
		ft_memdel(&content);
	}
}

void			queue_del(t_parse *parser)
{
	ft_quedel(&parser->tokens, del);
}
