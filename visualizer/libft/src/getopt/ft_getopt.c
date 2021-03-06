/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getopt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 21:10:03 by blinnea           #+#    #+#             */
/*   Updated: 2020/07/25 22:00:23 by blinnea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_getopt.h"
#include "libft_string.h"

char		*g_optarg = NULL;
int			g_optopt = 0;
int			g_optind = 1;
int			g_optreset = 1;

static int	helper(const t_acav acav, const char *opstring,
const char **ptr)
{
	char	*op;

	if (!(op = ft_strchr(opstring, *(*ptr)++)))
	{
		(**ptr ? 0 : (*ptr = acav.argv[++g_optind]));
		return ('?');
	}
	if (op[1] != ':')
		(**ptr ? 0 : (*ptr = acav.argv[++g_optind]));
	else if (**ptr && (g_optarg = (char *)*ptr))
		*ptr = acav.argv[++g_optind];
	else
	{
		if (++g_optind == acav.argc)
			return (*opstring == ':' ? ':' : '?');
		g_optarg = (char *)acav.argv[g_optind];
		*ptr = acav.argv[++g_optind];
	}
	return (*op);
}

static void	getoptreset(void)
{
	g_optarg = NULL;
	g_optopt = 0;
	g_optind = 1;
	g_optreset = 0;
}

int			ft_getopt(const t_acav acav, const char *optstring)
{
	const char	*ptr;

	if (g_optreset)
		getoptreset();
	ptr = acav.argv[g_optind];
	if (g_optind >= acav.argc || (ptr == acav.argv[g_optind] &&
	*ptr++ != '-'))
		return (-1);
	if (!ft_strcmp(ptr, "-"))
	{
		ptr = acav.argv[++g_optind];
		return (-1);
	}
	g_optopt = *ptr;
	return (helper(acav, optstring, &ptr));
}
