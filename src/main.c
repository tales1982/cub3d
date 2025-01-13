/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlima-de <tlima-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 15:01:12 by tlima-de          #+#    #+#             */
/*   Updated: 2025/01/13 12:26:24 by tlima-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "player.h"   // Para key_press e key_release
#include "render.h"   // Para draw_loop
#include "map.h"      // Inclua este cabeçalho para acessar free_map


int main(void)
{
    t_game game;

    // Inicializar o jogo
    init_game(&game);

    // Configurar eventos de teclado
    mlx_hook(game.win, 2, 1L << 0, key_press, &game.player);
    mlx_hook(game.win, 3, 1L << 1, key_release, &game.player);

    // Loop principal
    mlx_loop_hook(game.mlx, draw_loop, &game);
    mlx_loop(game.mlx);

    // Liberar recursos antes de sair
    free_map(game.map);
    return 0;
}
