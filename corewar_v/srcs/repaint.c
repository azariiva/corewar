/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repaint.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: torange <@student.42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 13:48:07 by torange           #+#    #+#             */
/*   Updated: 2020/08/16 20:34:23 by torange          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visio.h"

void	change_window_size(int resize)
{
	if (resize > 0)
	{
			g_width += 1920 * 0.01;
			g_height += 1080 * 0.01;
	}
	else if (resize < 0)
	{
			g_width -= 1920 * 0.01;
			g_height -= 1080 * 0.01;
	}
	SDL_SetWindowSize(g_Window, g_width, g_height);
	SDL_SetWindowPosition(g_Window, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED);
}

void	paint_window()
{
	SDL_SetRenderDrawColor(g_Renderer, 250, 240, 190, 255);
	SDL_RenderClear(g_Renderer);

	SDL_SetRenderDrawColor(g_Renderer, 0xFF, 0x00, 0x00, 0xFF);
	SDL_Rect fillRect[64][64];
	for (int i = 0; i < 64; i++)
	{
		for (int j = 0; j < 64; j++)
		{
			fillRect[i][j].w = SCREEN_WIDTH / 100 * 0.5;
			fillRect[i][j].h = fillRect[i][j].w;
			fillRect[i][j].x = SCREEN_WIDTH / 10 + (i * 13);
			fillRect[i][j].y = SCREEN_HEIGHT / 10 + (j * 13);
			SDL_RenderFillRect(g_Renderer, &fillRect[i][j]);
		}
	}
	SDL_Rect outlineRect = {SCREEN_WIDTH / 100 * 9.9, SCREEN_HEIGHT / 100 * 9.9, SCREEN_WIDTH / 100 * 43.4, SCREEN_WIDTH / 100 * 43.4};
	SDL_SetRenderDrawColor(g_Renderer, 0x00, 0xFF, 0x00, 0xFF);
	SDL_RenderDrawRect(g_Renderer, &outlineRect);
	SDL_SetRenderDrawColor( g_Renderer, 0x00, 0x00, 0xFF, 0xFF );
	SDL_RenderDrawLine( g_Renderer, SCREEN_WIDTH * 0.75, 0, SCREEN_WIDTH * 0.75, SCREEN_HEIGHT + 1);
	SDL_RenderPresent(g_Renderer);
}
