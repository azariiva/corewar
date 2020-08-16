/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visio.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: torange <@student.42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 15:18:44 by torange           #+#    #+#             */
/*   Updated: 2020/08/16 20:10:44 by torange          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISIO_H
# define VISIO_H

# include "libft.h"
# include "libftprintf.h"
# include <stdio.h>
# include "glfw3.h"
# include "SDL_image.h"
# include "SDL_ttf.h"
# include "SDL.h"


# define SCREEN_WIDTH (double)1920
# define SCREEN_HEIGHT (double)1080
# define PROPORTION 16.f / 9.f
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

//The image we will load and show on the screen
SDL_Surface *g_HelloWorld;
SDL_Event g_event;

//Loads individual image
SDL_Surface* loadSurface(const char *path);

//The surface contained by the window
SDL_Surface* g_ScreenSurface;

//The images that correspond to a keypress
SDL_Surface* g_KeyPressSurfaces[KEY_PRESS_SURFACE_TOTAL];

//Current displayed image
SDL_Surface* g_CurrentSurface;

//The window renderer
SDL_Renderer* g_Renderer;

//Current displayed texture
SDL_Texture* g_Texture;

SDL_Texture* loadTexture(char *path );
SDL_Rect		g_LeftViewport;
SDL_Rect		g_RightViewport;

//Starts up SDL and creates window
bool	init();
void	paint_window();
void	change_window_size(int resize);
bool	loadMedia();

void	g_close();

#endif
