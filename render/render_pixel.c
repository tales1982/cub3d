/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_pixel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tales <tales@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 15:25:56 by tales             #+#    #+#             */
/*   Updated: 2025/03/03 22:27:25 by tales            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

void	put_pixel(int x, int y, int color, t_game *game)
{
	int	index;

	if (x >= WIDTH || y >= HEIGHT || x < 0 || y < 0)
		return ;
	index = y * game->size_line + x * game->bpp / 8;
	game->data[index] = color & 0xFF;
	game->data[index + 1] = (color >> 8) & 0xFF;
	game->data[index + 2] = (color >> 16) & 0xFF;
}

void	draw_s(t_point pos, int size, int color, t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			put_pixel(pos.x + i, pos.y + j, color, game);
			j++;
		}
		i++;
	}
}

int	get_texture_color(void *img, int x, int y)
{
	int		bpp;
	int		size_line;
	int		endian;
	char	*data;
	int		index;

	data = mlx_get_data_addr(img, &bpp, &size_line, &endian);
	if (!data)
	{
		fprintf(stderr, "Error: Invalid texture data\n");
		exit(EXIT_FAILURE);
	}
	index = y * size_line + x * (bpp / 8);
	return (*(int *)(data + index));
}

void	clear_image(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			put_pixel(x, y, 0, game);
			x++;
		}
		y++;
	}
}
