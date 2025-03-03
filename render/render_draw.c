/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_draw.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tales <tales@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 15:49:28 by tales             #+#    #+#             */
/*   Updated: 2025/03/03 17:01:11 by tales            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"


static void	draw_vertical_stripe(t_game *game, int col, t_draw_data *data)
{
	int	y;
	int	texture_y;
	int	color;

	y = data->wall_start;
	while (y < data->wall_end)
	{
		texture_y = (y - data->wall_start) * data->texture_height
			/ (data->wall_end - data->wall_start);
		if (texture_y < 0)
			texture_y = 0;
		if (texture_y >= data->texture_height)
			texture_y = data->texture_height - 1;
		color = get_texture_color(data->texture, data->texture_x, texture_y);
		put_pixel(col, y, color, game);
		y++;
	}
	y = -1;
	while (++y < data->wall_start)
		put_pixel(col, y, game->ceiling_color, game);
	y = data->wall_end;
	y--;
	while (++y < HEIGHT)
		put_pixel(col, y, game->floor_color, game);
}

void	draw_line(t_player *player, t_game *game, float angle, int col)
{
	t_draw_data	data;
	t_ray		ray;

	/* As funções compute_ray e compute_draw_data foram movidas para render_utils.c */
	compute_ray(player, game, angle, &ray);
	compute_draw_data(game, player, &ray, &data);
	if (!data.texture)
		return ;
	draw_vertical_stripe(game, col, &data);
}

int	draw_loop(t_game *game)
{
	t_player	*player;
	float		fraction;
	float		start_angle;
	int			i;

	player = &game->player;
	if (player->key_esc)
		exit_program(game);
	move_player(player, game);
	clear_image(game);
	if (DEBUG)
	{
		draw_square((t_point){(int)player->x, (int)player->y}, 10, 0x00FF00,
			game);
		draw_map(game);
	}
	fraction = PI / 3 / WIDTH;
	start_angle = player->angle - PI / 6;
	i = -1;
	while (++i < WIDTH)
	{
		draw_line(player, game, start_angle, i);
		start_angle += fraction;
	}
	mlx_put_image_to_window(game->mlx, game->win, game->img, 0, 0);
	return (0);
}
