/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_quit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhitmonc <lhitmonc@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 19:31:19 by lhitmonc          #+#    #+#             */
/*   Updated: 2020/08/08 22:29:30 by lhitmonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu_corewar.h"

void	init(t_window *window)
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		ft_printf( "SDL init error: %s", SDL_GetError());
		quit(window);
		exit(ERR);
	}
	if (!(window->screen = SDL_CreateWindow("Coreawar", SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED, HEIGHT, WIDTH, SDL_WINDOW_OPENGL)))
	{
		ft_printf("Create window error: %s", SDL_GetError());
		quit(window);
		exit(ERR);
	}
	if (!(window->renderer = SDL_CreateRenderer(window->screen, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC)))
	{
		ft_printf("Create renderer error: %s", SDL_GetError());
		quit(window);
		exit(ERR);
	}
	if (TTF_Init() < 0)
	{
		ft_printf("TTF init error error: %s", SDL_GetError());
		quit(window);
		exit(ERR);
	}
}

int		quit(t_window *window)
{
	SDL_DestroyRenderer(window->renderer);
    SDL_DestroyWindow(window->screen);
    SDL_Quit();
	return (0);
}
