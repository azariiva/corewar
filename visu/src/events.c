/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: torange <@student.42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 15:18:35 by torange           #+#    #+#             */
/*   Updated: 2020/08/20 12:57:04 by torange          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visio.h"

void ToggleFullscreen(SDL_Window* Window)
{
	Uint32 FullscreenFlag = SDL_WINDOW_FULLSCREEN;
	bool IsFullscreen = SDL_GetWindowFlags(Window) & FullscreenFlag;
	SDL_SetWindowFullscreen(Window, IsFullscreen ? 0 : FullscreenFlag);
}

void	keyboard_event()
{
	int		resizeDone = 0;

	switch (g_event.key.keysym.sym)
	{
		case SDLK_ESCAPE:
			g_close();
		case SDLK_KP_PLUS:
			if (g_fullscreen == false)
				resizeDone++;
			break;
		case SDLK_KP_MINUS:
			if (g_fullscreen == false)
				resizeDone--;
			break;
		case SDLK_f:
			ToggleFullscreen(g_Window);
			break;
		default:
			break;
	}
	if (resizeDone != 0)
		change_window_size(resizeDone);
}

void	catch_event()
{
	switch (g_event.type)
	{
		case SDL_KEYDOWN:
			keyboard_event();
			break;
		default:
			break;
	}
}
