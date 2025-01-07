/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tales <tales@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 15:01:12 by tlima-de          #+#    #+#             */
/*   Updated: 2025/01/07 22:24:07 by tales            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "cub3d.h"    // Estrutura geral e definições
#include "player.h"   // Para key_press e key_release
#include "render.h"   // Para draw_loop





int main(void)
{
    t_game game;
    // init
    init_game(&game);
    // hooks
    mlx_hook(game.win, 2, 1L<<0, key_press, &game.player);
    mlx_hook(game.win, 3, 1L<<1, key_release, &game.player);
    // draw loop
    mlx_loop_hook(game.mlx, draw_loop, &game);

    mlx_loop(game.mlx);
    return 0;
}