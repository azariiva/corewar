/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: torange <@student.42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 15:18:35 by torange           #+#    #+#             */
/*   Updated: 2020/08/16 20:10:17 by torange          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visio.h"

double CreateRectanglesX()
{
    double x; double x_max = 640; double x_min = 20;
    x = rand() / (x_max - x_min) / (double)RAND_MAX + x_min;
    return x;
}

double CreateRectanglesY()
{
    double y; double y_max = 480; double y_min = 20;
    y = rand() / (y_max - y_min) / (double)RAND_MAX + y_min;
    return y;
}

int main(int argc, char* args[])
{
	bool		is_running = true;
	bool		repaint = true;
	uint32_t	windowID;
	int			resizeDone = 0;
	g_width = SCREEN_WIDTH;
	g_height = SCREEN_HEIGHT;

	if(init())
	{
		if(loadMedia())
		{
			paint_window();
			windowID = SDL_GetWindowID(g_Window);
			while (is_running)
			{
				while (SDL_PollEvent(&g_event) != 0)
				{
					switch (g_event.type)
					{
						case SDL_QUIT:
							is_running = false;
							break;
						case SDL_KEYDOWN:
						{
							switch (g_event.key.keysym.sym)
							{
								case SDLK_ESCAPE:
									is_running = false;
									break;
								case SDLK_KP_PLUS:
									resizeDone++;
									break;
								case SDLK_KP_MINUS:
									resizeDone--;
									break;
								default:
									break;
							}
							break;
						}
						case SDL_WINDOWEVENT:
							switch(g_event.window.event)
							{
								case SDL_WINDOWEVENT_RESIZED:

									break;
								default:
									break;
							}
							break;
						default:
							break;
					}

				}
				change_window_size(resizeDone);
				resizeDone = 0;
			}
		}
		else
			printf( "Failed to load media!\n" );
	}
	else
		printf( "Failed to initialize!\n" );
	g_close();
	return 0;
}


// printf("%f %f\n", currentsize.c_width, currentsize.c_height);
								// double width = g_event.window.data1;
								// double height = g_event.window.data2;
								// if (width > 2337 || height > 1314)
								// {
								// 	width = 2337;
								// 	height = 1314;
								// }
								// else if (height > currentsize.c_height && width == currentsize.c_width)
								// 	width = height * 1.77777778;
								// else if (width > currentsize.c_width && height == currentsize.c_height)
								// 	height = width / 1.77777778;
								// if (width / height != PROPORTION)
								// {
								// if (width / height > PROPORTION)
								// 	height = width * (1.f / PROPORTION);
								// else if (width / height < PROPORTION)
								// 	width = height * PROPORTION;
								// currentsize.c_width = width;
								// // currentsize.c_height = height;
								// SDL_SetWindowSize(g_Window, width, width * PROPORTION);
								// currentsize.c_height = height;
								// currentsize.c_width = width;
