/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tales <tales@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 22:00:26 by tales             #+#    #+#             */
/*   Updated: 2025/01/07 22:23:11 by tales            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "cub3d.h"
#include "cub3d.h"   // Para a estrutura t_game e definições gerais
#include "player.h"  // Para a função init_player
#include "map.h"     // Para a função get_map



void init_game(t_game *game)
{
    init_player(&game->player);
    game->map = get_map();
    game->mlx = mlx_init();
    game->win = mlx_new_window(game->mlx, WIDTH, HEIGHT, "Game");
    game->img = mlx_new_image(game->mlx, WIDTH, HEIGHT);
    game->data = mlx_get_data_addr(game->img, &game->bpp, &game->size_line, &game->endian);
    mlx_put_image_to_window(game->mlx, game->win, game->img, 0, 0);
}