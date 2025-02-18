/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tales <tales@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 22:00:26 by tales             #+#    #+#             */
/*   Updated: 2025/02/18 14:26:26 by tales            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Inicializa o jogo
#include "cub3d.h"
#include "player.h"  // Para a função init_player
#include "map.h"     // Para a função load_map


void set_player_position(t_game *game)
{
    for (int y = 0; game->map[y] != NULL; y++)
    {
        for (int x = 0; game->map[y][x] != '\0'; x++)
        {
            char c = game->map[y][x];
            if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
            {
                // Define a posição do jogador no centro do bloco
                game->player.x = x * BLOCK + BLOCK / 2;
                game->player.y = y * BLOCK + BLOCK / 2;
                
                // Define o ângulo do jogador baseado na orientação
                if (c == 'N')
                    game->player.angle = PI / 2;
                else if (c == 'S')
                    game->player.angle = 3 * PI / 2;
                else if (c == 'E')
                    game->player.angle = 0;
                else if (c == 'W')
                    game->player.angle = PI;
                
                // Opcional: substitua o marcador por '0' para tratar como espaço vazio
                game->map[y][x] = '0';
                return; // Parar ao encontrar o primeiro marcador
            }
        }
    }
}


void init_game(t_game *game, char map[MAX_MAP_LINES][MAX_LINE])
{
    // Inicializa a MiniLibX
    game->mlx = mlx_init();
    if (!game->mlx)
    {
        fprintf(stderr, "Error: Failed to initialize MiniLibX.\n");
        exit(1);
    }

    // Inicializa o jogador (opcional, você pode definir alguns valores padrão aqui)
    init_player(&game->player);

    // Carrega o mapa e as texturas
    load_map(map, game);
    load_images(game->mlx, &game->textures);

    // Configura as texturas (depuração)
    debug_textures(&game->textures);

    // Após carregar o mapa, ajuste a posição do jogador baseado no marcador do mapa
    set_player_position(game);

    // Cria a janela e a imagem, etc...
    game->win = mlx_new_window(game->mlx, WIDTH, HEIGHT, "Game");
    if (!game->win)
    {
        fprintf(stderr, "Error: Failed to create a window.\n");
        exit(1);
    }

    game->img = mlx_new_image(game->mlx, WIDTH, HEIGHT);
    if (!game->img)
    {
        fprintf(stderr, "Error: Failed to create an image.\n");
        exit(1);
    }
    
    game->data = mlx_get_data_addr(game->img, &game->bpp, &game->size_line, &game->endian);
    if (!game->data)
    {
        fprintf(stderr, "Error: Failed to get image data address.\n");
        exit(1);
    }
}
