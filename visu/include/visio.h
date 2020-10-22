/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visio.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 15:18:44 by torange           #+#    #+#             */
/*   Updated: 2020/10/22 16:32:41 by blinnea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISIO_H
# define VISIO_H

# include "libft.h"
# include <stdbool.h>
# include <stdio.h>
# include "SDL_image.h"
# include "SDL_ttf.h"
# include "SDL.h"


# define SCREEN_WIDTH (double)1920
# define SCREEN_HEIGHT (double)1080
# define PROPORTION 16.f / 9.f
# define EMPTY			1
# define FULL			2

		/****** COLORS ******/

# define MEMORY_1		25, 25, 25, 1
# define MEMORY_2		223, 226, 219, 1
# define MEMORY_3		104, 131, 86, 1
# define MEMORY_4		197, 74, 42, 1
# define EMPTY_MEMORY	0, 0, 0
# define COREWAR_TEXT	0, 0, 0, 255
# define RIGHT			42, 65, 80, 1
# define LEFT			91, 125, 134, 1
# define OUTLINE_RECT	77, 99, 86, 1

# define UKRAINE_BLUE	0, 91, 187, 1
# define UKRAINE_YELLOW	255, 213, 0, 1


typedef struct	s_currentsize
{
	double c_height;
	double c_width;
}				t_currentsize;

static const float ASPECT_RATIO = 16.f/9.f;

enum KeyPressSurfaces
{
	KEY_PRESS_SURFACE_DEFAULT,
	KEY_PRESS_SURFACE_UP,
	KEY_PRESS_SURFACE_DOWN,
	KEY_PRESS_SURFACE_LEFT,
	KEY_PRESS_SURFACE_RIGHT,
	KEY_PRESS_SURFACE_TOTAL
};


double g_width;
double g_height;
//The window we'll be rendering to
SDL_Window *g_Window;

//The surface contained by the window
SDL_Surface *g_ScreenSurface;

SDL_Event g_event;

//The surface contained by the window
SDL_Surface* g_ScreenSurface;

//Current displayed image
SDL_Surface* g_CurrentSurface;

//The window renderer
SDL_Renderer* g_Renderer;

//Current displayed texture
SDL_Texture* g_Texture;
TTF_Font *g_Font;
bool	g_fullscreen;

void	load_string(char *str, size_t font_size, int x, int y, int r, int g , int b, int a);
bool	init();
void	paint_window();
int		change_window_size(int resize);
void	catch_event();
bool	loadMedia();
void	loadText();
void	g_close();

#endif
