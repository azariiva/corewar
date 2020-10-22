/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repaint.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: torange <@student.42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 13:48:07 by torange           #+#    #+#             */
/*   Updated: 2020/08/25 13:05:09 by torange          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visio.h"

void	render_figure_color(SDL_Rect figure, int r, int g, int b, int a, size_t type)
{
	SDL_SetRenderDrawColor(g_Renderer, r, g , b, a);
	if (type == 1)
		SDL_RenderDrawRect(g_Renderer, &figure);
	else if (type == 2)
		SDL_RenderFillRect(g_Renderer, &figure);
}

int		change_window_size(int resize)
{
	if (resize > 0)
	{
			g_width += 1920 * 0.009;
			g_height += 1080 * 0.009;
	}
	else if (resize < 0)
	{
			g_width -= 1920 * 0.009;
			g_height -= 1080 * 0.009;
	}
	SDL_SetWindowSize(g_Window, g_width, g_height);
	SDL_SetWindowPosition(g_Window, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED);
	return 0;
}

void	paint_window()
{
	SDL_SetRenderDrawColor(g_Renderer, RIGHT);
	SDL_RenderClear(g_Renderer);

	SDL_SetRenderDrawColor(g_Renderer, MEMORY_3);
	SDL_Rect fillRect[64][64];
	for (int i = 0; i < 64; i++)
	{
		for (int j = 0; j < 64; j++)
		{
			fillRect[i][j].w = SCREEN_WIDTH / 100 * 0.5;
			fillRect[i][j].h = fillRect[i][j].w;
			fillRect[i][j].x = SCREEN_WIDTH * 0.164 + (i * 13);
			fillRect[i][j].y = SCREEN_HEIGHT * 0.1165 + (j * 13);
			if (j < 16)
				render_figure_color(fillRect[i][j], MEMORY_1, FULL);
			else if (j < 32)
				render_figure_color(fillRect[i][j], MEMORY_2, FULL);
			else if (j < 48)
				render_figure_color(fillRect[i][j], MEMORY_3, FULL);
			else if (j < 64)
				render_figure_color(fillRect[i][j], MEMORY_4, FULL);
		}
	}
	SDL_Rect outlineRect = {SCREEN_WIDTH * 0.163, SCREEN_HEIGHT * 0.1143, SCREEN_WIDTH / 100 * 43.38, SCREEN_WIDTH / 100 * 43.38};
	render_figure_color(outlineRect, OUTLINE_RECT, EMPTY);

	SDL_Rect line = {SCREEN_WIDTH * 0.75, 0, SCREEN_WIDTH * 0.25, SCREEN_HEIGHT};
	render_figure_color(line, LEFT, FULL);

	SDL_Rect menu_rect = {SCREEN_WIDTH * 0.76, SCREEN_HEIGHT * 0.7, SCREEN_WIDTH * 0.23, SCREEN_WIDTH * 0.1595};
	render_figure_color(menu_rect, OUTLINE_RECT, EMPTY);

	SDL_Rect info_rect = {SCREEN_WIDTH * 0.76, SCREEN_HEIGHT * 0.018, SCREEN_WIDTH * 0.23, SCREEN_WIDTH * 0.373};
	render_figure_color(info_rect, OUTLINE_RECT, EMPTY);
	loadText();
	SDL_RenderPresent(g_Renderer);
}
