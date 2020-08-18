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

t_htable				*get_op_htable(void)
{
	size_t		i;
	t_htable	*op_htable;

	op_htable = ft_htnew((sizeof(op_tab) / sizeof(*op_tab)), cmp, hash);
	i = -1;
	while (++i < (sizeof(op_tab) / sizeof(*op_tab)))
		ft_htadd(op_htable, op_tab + i, sizeof(*op_tab));
	return (op_htable);
}