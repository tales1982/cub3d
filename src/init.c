/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlima-de <tlima-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 22:00:26 by tales             #+#    #+#             */
/*   Updated: 2025/01/13 12:40:45 by tlima-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Inicializa o jogo
#include "cub3d.h"
#include "player.h"  // Para a função init_player
#include "map.h"     // Para a função load_map

void init_game(t_game *game)
{
    init_player(&game->player);

    // Carregar o mapa do arquivo
    load_map("asserts/maps/level1.cub", game);

    // Inicializar outros elementos
    game->mlx = mlx_init();
    game->win = mlx_new_window(game->mlx, WIDTH, HEIGHT, "Game");
    game->img = mlx_new_image(game->mlx, WIDTH, HEIGHT);
    game->data = mlx_get_data_addr(game->img, &game->bpp, &game->size_line, &game->endian);
    mlx_put_image_to_window(game->mlx, game->win, game->img, 0, 0);
}
