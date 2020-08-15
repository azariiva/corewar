/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu_corewar.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhitmonc <lhitmonc@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 19:31:12 by lhitmonc          #+#    #+#             */
/*   Updated: 2020/08/08 22:27:00 by lhitmonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISU_COREWAR_H

# define VISU_COREWAR_H

#include "SDL.h"
#include "SDL_ttf.h"
#include "libft.h"

# define	BACK_PATH		"./textures/background.bmp"
# define	MEMORY_BLOCK	"./textures/memory_block.bmp"
# define	ERR				-1
# define	HEIGHT			1920
# define	WIDTH			1080

typedef struct	s_window
{
	SDL_Event		event;
	SDL_Window		*screen;
	SDL_Renderer	*renderer;
}				t_window;

/*
**	load.c
*/

SDL_Texture	*load_texture_BMP(t_window *window, char *path);

/*
**	init_quit.c
*/

void		init(t_window *window);
int			quit(t_window *window);

/*
**	show_corewar.c
*/

void		put_texture(int x, int y, SDL_Texture *tex, SDL_Renderer *rend);
void		make_background(t_window *window);
void		show_corewar(t_window *window);

/*
**	text.c
*/

SDL_Texture* make_text(const char *text, char *font_path, SDL_Color color, int font_size,
						t_window *window);
#endif
