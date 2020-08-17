#include "asm.h"

static int				cmp(const void *a, const void *b)
{
	t_asop	*ta;
	t_asop	*tb;

	ta = (t_asop *)a;
	tb = (t_asop *)b;
	return (ft_strcmp(ta->name, tb->name));
}

static unsigned long	hash(const void *tab, const size_t modulo)
{
	t_asop	*t;

	t = (t_asop *)tab;
	return (ft_strhash(t->name, modulo));
}

void					get_op_htable(t_htable *op_htable)
{
	int			i;

	op_htable = ft_htnew(sizeof(t_op), cmp, hash);
	i = -1;
	while (++i < 16)
		ft_htadd(op_htable, &op_tab[i], sizeof(op_tab[i]));
}
