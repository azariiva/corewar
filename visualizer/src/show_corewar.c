/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_corewar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhitmonc <lhitmonc@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 18:33:38 by lhitmonc          #+#    #+#             */
/*   Updated: 2020/08/08 22:43:52 by lhitmonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu_corewar.h"
#include <math.h>

void	put_texture(int x, int y, SDL_Texture *texture, SDL_Renderer *renderer)
{
	SDL_Rect pos;
	pos.x = x;
	pos.y = y;
	SDL_QueryTexture(texture, NULL, NULL, &pos.w, &pos.h);
	SDL_RenderCopy(renderer, texture, NULL, &pos);
}

void	make_background(t_window *window)
{
	SDL_Texture	*texture;
	int			i;
	int			size_h;
	int			size_w;

	/* Фон */
	texture = load_texture_BMP(window, BACK_PATH);
	SDL_QueryTexture(texture, NULL, NULL, &size_w, &size_h);

	int xTiles = ceil(1080. / size_h);
	int yTiles = ceil(1920. / size_w);

	i = 0;
	while (i < xTiles * yTiles)
	{
		int x = i / xTiles;
		int y = i % xTiles;
		put_texture(x * size_h, y * size_w, texture, window->renderer);
		++i;
	}
	SDL_DestroyTexture(texture);

	/* Панель с памятью */
	texture = load_texture_BMP(window, MEMORY_BLOCK);
	SDL_QueryTexture(texture, NULL, NULL, &size_w, &size_h);
	put_texture(100, 100, texture, window->renderer);
	SDL_DestroyTexture(texture);

	/* Текст */
	SDL_Color color = { 255, 255, 255, 255 };
	texture = make_text("Debil", "./font.ttf", color, 64, window);
	SDL_QueryTexture(texture, NULL, NULL, &size_w, &size_h);
	put_texture(100, 100, texture, window->renderer);
	SDL_DestroyTexture(texture);

	/* Панель с доп параметрами 1 */
	// texture = load_texture_BMP(window, MEMORY_BLOCK);
	// SDL_QueryTexture(texture, NULL, NULL, &size_w, &size_h);
	// put_texture(100, 100, texture, window->renderer);
	// SDL_DestroyTexture(texture);

	/* Панель с доп параметрами 2 */
	// texture = load_texture_BMP(window, MEMORY_BLOCK);
	// SDL_QueryTexture(texture, NULL, NULL, &size_w, &size_h);
	// put_texture(100, 100, texture, window->renderer);
	// SDL_DestroyTexture(texture);

	SDL_RenderPresent(window->renderer);
}

void	show_corewar(t_window *window)
{
	int	flag;

	flag = 1;
	while (flag)
	{
		while (SDL_PollEvent(&(window->event)))
		{
			if (window->event.key.keysym.sym == SDLK_SPACE)
			{
				//pause
			}
			else if (window->event.key.keysym.sym == SDLK_RIGHT)
			{
				//next
			}
			else if (window->event.key.keysym.sym == SDLK_q)
			{
				flag = 0;
			}
			else if (window->event.key.keysym.sym == SDLK_f)
			{
				SDL_SetWindowFullscreen(window->screen, SDL_WINDOW_FULLSCREEN_DESKTOP);
			}
			else if (window->event.key.keysym.sym == SDLK_ESCAPE)
			{
				SDL_SetWindowFullscreen(window->screen, 0);
			}
		}
		SDL_RenderPresent(window->renderer);
	}
}
