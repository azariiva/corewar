/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_getopt.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 20:47:27 by blinnea           #+#    #+#             */
/*   Updated: 2020/07/30 14:51:16 by blinnea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_GETOPT_H

# define LIBFT_GETOPT_H

extern char		*g_optarg;
extern int		g_optopt;
extern int		g_optind;
extern int		g_optreset;

typedef struct	s_option
{
	const char	*name;
	int			has_arg;
	int			*flag;
	int			val;
}				t_option;

typedef struct	s_acav
{
	int			argc;
	char*const	*argv;
}				t_acav;

int				ft_getopt(const t_acav acav, const char *optstring);
int				ft_getopt_long(const t_acav acav, const char *shortopts,
const t_option *longopts, int *indexptr);

#endif
