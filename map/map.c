/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlima-de <tlima-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 15:02:16 by tlima-de          #+#    #+#             */
/*   Updated: 2025/01/13 12:46:10 by tlima-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"


void draw_map(t_game *game)
{
    char **map = game->map;
    int color = 0x0000FF;
    for (int y = 0; map[y]; y++)
        for (int x = 0; map[y][x]; x++)
            if (map[y][x] == '1')
                draw_square(x * BLOCK, y * BLOCK, BLOCK, color, game);
}

void free_map(char **map)
{
    int i = 0;
    while (map[i])
        free(map[i++]);
    free(map);
}

void load_map(const char *file_path, t_game *game)
{
    int fd = open(file_path, O_RDONLY);
    if (fd < 0)
    {
        perror("Error opening map file");
        exit(EXIT_FAILURE);
    }

    char *line = NULL;
    int row = 0;

    // Alocar memória para o mapa
    game->map = malloc(sizeof(char *) * MAP_HEIGHT);

    if (!game->map)
    {
        perror("Error allocating memory for map");
        exit(EXIT_FAILURE);
    }

    // Ler o arquivo linha por linha usando get_next_line
    while ((line = get_next_line(fd)) != NULL)
    {
        game->map[row] = line; // Aloca automaticamente a linha
        row++;
    }
    game->map[row] = NULL; // Finaliza o array
    close(fd);
}
