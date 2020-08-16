/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: torange <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 19:21:50 by torange           #+#    #+#             */
/*   Updated: 2020/07/10 19:23:54 by torange          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int		ft_new_line(char **s, char **line, int fd, int a)
{
	char	*str;
	int		len;

	len = 0;
	while (s[fd][len] != '\n' && s[fd][len] != '\0')
		len++;
	if (s[fd][len] == '\n')
	{
		*line = ft_strsub(s[fd], 0, len);
		str = ft_strdup(s[fd] + len + 1);
		free(s[fd]);
		s[fd] = str;
		if (s[fd][0] == '\0')
			ft_strdel(&s[fd]);
	}
	else if (s[fd][len] == '\0')
	{
		if (a == BUFF_SIZE)
			return (get_next_line(fd, line));
		*line = ft_strdup(s[fd]);
		ft_strdel(&s[fd]);
	}
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	static char		*s[255];
	char			*str;
	int				a;
	char			buffer[BUFF_SIZE + 1];

	if (fd < 0 || line == NULL)
		return (-1);
	while ((a = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		buffer[a] = '\0';
		if (s[fd] == NULL)
			s[fd] = ft_strnew(1);
		str = ft_strjoin(s[fd], buffer);
		free(s[fd]);
		s[fd] = str;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	if (a < 0)
		return (-1);
	else if (a == 0 && (s[fd] == NULL || s[fd][0] == '\0'))
		return (0);
	return (ft_new_line(s, line, fd, a));
}
