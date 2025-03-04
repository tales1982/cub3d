/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tales <tales@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 16:19:01 by tales             #+#    #+#             */
/*   Updated: 2025/03/04 10:20:52 by tales            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

void	compute_ray(t_player *player, t_game *game, float angle, t_ray *ray)
{
	float	cos_a;
	float	sin_a;

	cos_a = cos(angle);
	sin_a = sin(angle);
	ray->x = player->x;
	ray->y = player->y;
	while (!touch(ray->x, ray->y, game))
	{
		ray->x += cos_a;
		ray->y += sin_a;
	}
	ray->direction = touch(ray->x, ray->y, game);
}

void	select_texture(t_game *game, t_ray *ray, t_draw_data *data)
{
	if (ray->direction == NORTH)
		data->texture = game->textures.north;
	else if (ray->direction == SOUTH)
		data->texture = game->textures.south;
	else if (ray->direction == WEST)
		data->texture = game->textures.west;
	else if (ray->direction == EAST)
		data->texture = game->textures.east;
	else
		data->texture = NULL;
}

void	compute_wall_bounds(t_game *game, t_player *player, t_ray *ray,
		t_draw_data *data)
{
	(void)game;
	data->dist = fixed_dist((t_point){player->x, player->y}, (t_point){ray->x,
			ray->y}, player->angle);
	if (data->dist < 0.1)
		data->dist = 0.1;
	data->height = (BLOCK / data->dist) * ((float)WIDTH / (2 * tan(PI / 6)));
	data->wall_start = (int)((HEIGHT - data->height) / 2);
	data->wall_end = data->wall_start + (int)data->height;
	if (data->wall_start < 0)
		data->wall_start = 0;
	if (data->wall_end >= HEIGHT)
		data->wall_end = HEIGHT - 1;
	data->texture_width = 64;
	data->texture_height = 64;
}

void	compute_texture_index(t_ray *ray, t_draw_data *data)
{
	if (ray->direction == NORTH || ray->direction == SOUTH)
		data->texture_x = (int)(((ray->x - floor(ray->x / BLOCK) * BLOCK)
					* data->texture_width) / BLOCK);
	else
		data->texture_x = (int)(((ray->y - floor(ray->y / BLOCK) * BLOCK)
					* data->texture_width) / BLOCK);
	if (data->texture_x < 0)
		data->texture_x = 0;
	if (data->texture_x >= data->texture_width)
		data->texture_x = data->texture_width - 1;
}

void	compute_draw_data(t_game *game, t_player *player, t_ray *ray,
		t_draw_data *data)
{
	select_texture(game, ray, data);
	if (!data->texture)
		return ;
	compute_wall_bounds(game, player, ray, data);
	compute_texture_index(ray, data);
}
