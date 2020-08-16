/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaple <rmaple@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 18:07:15 by rmaple            #+#    #+#             */
/*   Updated: 2019/09/23 23:35:31 by rmaple           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memalloc(size_t size)
{
	void	*data;

	if (size == 0)
		return (NULL);
	data = malloc(size);
	if (data == NULL)
		return (NULL);
	ft_bzero(data, size);
	return (data);
}
