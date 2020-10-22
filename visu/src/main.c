/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: torange <@student.42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 15:18:35 by torange           #+#    #+#             */
/*   Updated: 2020/08/19 19:35:15 by torange          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visio.h"

int main(int argc, char* args[])
{
	bool		is_running = true;
	bool		repaint = true;
	int			resizeDone = 0;
	g_width = SCREEN_WIDTH;
	g_height = SCREEN_HEIGHT;
	g_fullscreen = false;

	if(init())
	{
		if(loadMedia())
			while (1)
				if (SDL_PollEvent(&g_event) != 0)
					catch_event();
	}
	else
		printf( "Failed to initialize!\n" );
	return 0;
}
