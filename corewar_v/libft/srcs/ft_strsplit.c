/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaple <rmaple@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 20:39:30 by rmaple            #+#    #+#             */
/*   Updated: 2019/09/23 21:38:31 by rmaple           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static size_t	ft_count_words(const char *str, char c)
{
	size_t	word;
	int		i;

	i = 0;
	word = 0;
	if (str == NULL)
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] == c && str[i + 1] != c)
			word++;
		i++;
	}
	if (str[0] != '\0')
		word++;
	return (word);
}

static char		*ft_word(const char *str, char c, int *i)
{
	char	*s;
	int		k;

	if (!(s = (char *)malloc(sizeof(s) * (ft_strlen(str)))))
		return (NULL);
	k = 0;
	while (str[*i] != c && str[*i])
	{
		s[k] = str[*i];
		k++;
		*i += 1;
	}
	s[k] = '\0';
	while (str[*i] == c && str[*i])
		*i += 1;
	return (s);
}

static void		ft_free(char **str, int i)
{
	while (i)
	{
		free(str[i]);
		i--;
	}
	free(*str);
}

char			**ft_strsplit(const char *str, char c)
{
	int		i;
	int		j;
	int		word;
	char	**s;

	i = 0;
	j = 0;
	if (str == NULL)
		return (NULL);
	word = ft_count_words(str, c);
	s = (char **)malloc(sizeof(s) * (ft_count_words(str, c) + 2));
	if (s == NULL)
		return (NULL);
	while (str[i] == c && str[i] != '\0')
		i++;
	while (j < word && str[i] != '\0')
	{
		if (!(s[j] = ft_word(str, c, &i)))
			ft_free(s, j);
		j++;
	}
	s[j] = NULL;
	return (s);
}
