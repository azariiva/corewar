/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 17:48:41 by blinnea           #+#    #+#             */
/*   Updated: 2020/08/17 19:21:31 by blinnea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

typedef struct			s_test
{
	char				*label;
	unsigned short		memloc;
}						t_test;

static int				cmp(const void *a, const void *b)
{
	t_test	*ta;
	t_test	*tb;

	ta = (t_test *)a;
	tb = (t_test *)b;
	return (ft_strcmp(ta->label, tb->label));
}

static void				del(void *content, size_t cs)
{
	t_test	*t;

	if (cs && content)
	{
		t = content;
		ft_strdel(&(t->label));
		ft_memdel(&content);
	}
}

static unsigned long	hash(const void *tab, const size_t modulo)
{
	t_test	*t;

	t = (t_test *)tab;
	return (ft_strhash(t->label, modulo));
}

int			main(void)
{
	t_test		test;
	char		*stab[] = {
		"a", "b", "c", "d", "e",
		"aa", "ab", "ac", "ad", "ae",
		"ba", "bb", "bc", "bd", "be",
		"ca", "cb", "cc", "cd", "ce",
		"da", "db", "dc", "dd", "de",
		"ea", "eb", "ec", "ed", "ee"
	};

	t_htable	*ht = ft_htnew(sizeof(stab) / sizeof(char *), cmp, hash);
	for (int i = 0; i < (sizeof(stab) / sizeof(char *)); i++)
	{
		test.label = stab[i];
		test.memloc = i;
		ft_htadd(ht, &test, sizeof(test));
	}

	const char	*tof = "ab";
	t_test		*tp;
	test.label = (char *)tof;
	if ((tp = ft_htget(ht, &test)))
	{
		ft_printf("%hu\n", tp->memloc);
		ft_printf("%s\n", stab[(int)tp->memloc]);
	}
	ft_htdel(&ht, del);
	return (0);
}
