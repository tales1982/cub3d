/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tales <tales@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 15:00:34 by tlima-de          #+#    #+#             */
/*   Updated: 2025/03/04 10:21:30 by tales            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# include "cub3d.h"
# include "map.h"
# include "player.h"
# include "point.h"
# include "utils.h"
# include <math.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>

/* Estruturas de renderização */
typedef struct s_ray
{
	float	x;
	float	y;
	int		direction;
}			t_ray;

typedef struct s_draw_data
{
	float	dist;
	float	height;
	int		wall_start;
	int		wall_end;
	int		texture_x;
	int		texture_width;
	int		texture_height;
	void	*texture;
}			t_draw_data;

/* Funções de manipulação de pixels e imagem */
void		put_pixel(int x, int y, int color, t_game *game);
void		draw_s(t_point pos, int size, int color, t_game *game);
int			get_texture_color(void *img, int x, int y);
void		clear_image(t_game *game);

/* Funções de desenho de raios e loop de renderização */
void		draw_line(t_player *player, t_game *game, float angle, int col);
int			draw_loop(t_game *game);

/* Funções auxiliares para renderização */
void		compute_ray(t_player *player, t_game *game, float angle,
				t_ray *ray);
void		select_texture(t_game *game, t_ray *ray, t_draw_data *data);

void		compute_wall_bounds(t_game *game, t_player *player, t_ray *ray,
				t_draw_data *data);
void		compute_texture_index(t_ray *ray, t_draw_data *data);
void		compute_draw_data(t_game *game, t_player *player, t_ray *ray,
				t_draw_data *data);

#endif // RENDER_H
