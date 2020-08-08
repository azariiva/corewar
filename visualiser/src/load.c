/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhitmonc <lhitmonc@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 19:31:16 by lhitmonc          #+#    #+#             */
/*   Updated: 2020/08/08 22:23:51 by lhitmonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu_corewar.h"

SDL_Texture	*load_texture_BMP(t_window *window, char *path)
{
	SDL_Surface	*tmp;
	SDL_Texture *texture;

	if (!(tmp = SDL_LoadBMP(path)))
	{
		ft_printf( "Load image error: %s", SDL_GetError());
		quit(window);
		exit(ERR);
	}
	if(!(texture = SDL_CreateTextureFromSurface(window->renderer, tmp)))
	{
		ft_printf( "Create texture error: %s", SDL_GetError());
		quit(window);
		exit(ERR);
	}
	SDL_FreeSurface(tmp);
	return (texture);
}
