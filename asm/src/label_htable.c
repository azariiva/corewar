#include "asm.h"

static int				cmp(const void *a, const void *b)
{
	t_lable	*ta;
	t_lable	*tb;

	ta = (t_lable *)a;
	tb = (t_lable *)b;
	return (ft_strcmp(ta->name, tb->name));
}

static unsigned long	hash(const void *tab, const size_t modulo)
{
	t_lable	*t;

	t = (t_lable *)tab;
	return (ft_strhash(t->name, modulo));
}

void					get_label_htable(t_parse *parser)
{
	t_list		*tokens;
	t_lable		lable;

	parser->lables_htable = ft_htnew(parser->label_count, cmp, hash);
	tokens = parser->tokens->head;
	while (tokens)
	{
		if (FT_LSTCONT(t_token, tokens)->type == LABEL)
		{
			lable.name = FT_LSTCONT(t_token, tokens)->content;
			lable.lab_pos = 0;
			ft_htadd(parser->lables_htable, &lable, sizeof(lable));
		}
		tokens = tokens->next;
	}
}
