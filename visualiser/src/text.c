/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhitmonc <lhitmonc@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 21:41:52 by lhitmonc          #+#    #+#             */
/*   Updated: 2020/08/08 22:48:35 by lhitmonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu_corewar.h"

SDL_Texture* make_text(const char *text, char *font_path, SDL_Color color, int font_size,
						t_window *window)
{
	TTF_Font		*font;
	SDL_Surface		*tmp;
	SDL_Texture		*texture;

	if (!(font = TTF_OpenFont(font_path, font_size)))
	{
		ft_printf( "Load font error: %s", SDL_GetError());
		quit(window);
		exit(ERR);
	}
	if (!(tmp = TTF_RenderText_Blended(font, text, color)))
	{
		ft_printf( "Load font error: %s", SDL_GetError());
		quit(window);
		exit(ERR);
	}
	if (!(texture = SDL_CreateTextureFromSurface(window->renderer, tmp)))
	{
		ft_printf( "Load font error: %s", SDL_GetError());
		quit(window);
		exit(ERR);
	}
	SDL_FreeSurface(tmp);
	TTF_CloseFont(font);
	return (texture);
}
