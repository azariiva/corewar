/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: torange <@student.42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 15:18:35 by torange           #+#    #+#             */
/*   Updated: 2020/08/19 20:41:11 by torange          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visio.h"

bool init()
{
	bool success = true;

	if(!(SDL_Init(SDL_INIT_VIDEO) < 0))
	{
		g_Window = SDL_CreateWindow("Corewar", \
									SDL_WINDOWPOS_CENTERED, \
									SDL_WINDOWPOS_CENTERED, \
									SCREEN_WIDTH, \
									SCREEN_HEIGHT, \
									SDL_WINDOW_SHOWN | SDL_WINDOW_BORDERLESS);
		if(g_Window != NULL)
		{
			g_Renderer = SDL_CreateRenderer(g_Window, -1, SDL_RENDERER_ACCELERATED);
			if(g_Renderer != NULL)
				IMG_Init(IMG_INIT_PNG);
		}
	}
	else {
		printf("ERROR %s\n", SDL_GetError());
		success = false;
	}
	return success;
}

bool loadMedia()
{
	bool success = true;
	paint_window();
	return success;
}

void loadText()
{
	TTF_Init();

	/* COREWAR INFO */
	load_string("Corewar Info", 100, SCREEN_WIDTH * 0.789, SCREEN_HEIGHT * 0.015, COREWAR_TEXT);
	/* MENU GUIDE */
	load_string("Menu Guide", 70, SCREEN_WIDTH * 0.827, SCREEN_HEIGHT * 0.71, COREWAR_TEXT);
	/* BATTLE FIELD */
	load_string("Battle Field", 100, SCREEN_WIDTH * 0.31, SCREEN_HEIGHT * 0.01, COREWAR_TEXT);

	/* +/- info */
	load_string("To resize window use +/-", 35, SCREEN_WIDTH * 0.827, SCREEN_HEIGHT *  0.86, COREWAR_TEXT);
	/* Exit info */
	load_string("Press Esc to exit.", 35, SCREEN_WIDTH * 0.845, SCREEN_HEIGHT * 0.94, COREWAR_TEXT);
	/* Fullscreen usage info */
	load_string("Press F for Fullscreen.", 35, SCREEN_WIDTH * 0.835, SCREEN_HEIGHT * 0.9, COREWAR_TEXT);

	/* Champions */
	load_string("Champions:", 40, SCREEN_WIDTH * 0.789, SCREEN_HEIGHT * 0.15, COREWAR_TEXT);
	/*Prod. by */
	load_string("Prod. by: Blinnea & Torange & Fhilary & Lhitmonc", 30, SCREEN_WIDTH * 0.545, SCREEN_HEIGHT * 0.968, COREWAR_TEXT);
}

void	load_string(char *str, size_t font_size, int x, int y, int r, int g , int b, int a)
{
	int texW = 0;
	int texH = 0;
	SDL_Texture *texture;
	SDL_Rect dstrect;
	SDL_Color color = {r, g , b, a};

	g_Font = TTF_OpenFont("font.ttf", font_size);
	texture = SDL_CreateTextureFromSurface(g_Renderer, TTF_RenderText_Solid(g_Font, str, color));
	SDL_QueryTexture(texture, NULL, NULL, &texW, &texH);
	dstrect.x = x; dstrect.y = y; dstrect.w = texW; dstrect.h = texH;
	SDL_RenderCopy(g_Renderer, texture, NULL, &dstrect);
}

void g_close()
{
	SDL_DestroyRenderer(g_Renderer);
	SDL_DestroyWindow(g_Window);
	TTF_CloseFont(g_Font);
	g_Font = NULL;
	g_Window = NULL;
	TTF_Quit();
	SDL_Quit();
	exit(0);
}
