/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tales <tales@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 15:02:16 by tlima-de          #+#    #+#             */
/*   Updated: 2025/02/18 15:34:12 by tales            ###   ########.fr       */
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
    if (!map)
        return;

    for (int i = 0; map[i]; i++)
    {
        free(map[i]);
        map[i] = NULL;
    }

    free(map);
    map = NULL;
}

//void load_map(const char *file_path, t_game *game)
void load_map(char map[MAX_MAP_LINES][MAX_LINE], t_game *game)
{
    int i = 0;
    int row = 0;
    bool map_started = false;

    game->map = malloc(sizeof(char *) * (game->MAP_HEIGHT + 1  - 6));
    if (!game->map)
    {
        perror("Error allocating memory for map");
        exit(EXIT_FAILURE);
    }

    while (i < game->MAP_HEIGHT)
    {
        // Em vez de usar um buffer local, duplica a linha
        char *line = ft_strdup(map[i]);
        if (!line)
        {
            perror("Error duplicating map line");
            exit(EXIT_FAILURE);
        }

        //printf("DEBUG[%ld]\n", ft_strlen(line));

        if (!map_started)
        {
            if (ft_strncmp(line, "NO", 2) == 0 || ft_strncmp(line, "WE", 2) == 0 ||
                ft_strncmp(line, "SO", 2) == 0 || ft_strncmp(line, "EA", 2) == 0)
            {
                load_textures(line, &game->textures);
            }
            else if (ft_strncmp(line, "F", 1) == 0 || ft_strncmp(line, "C", 1) == 0)
            {
                parse_colors(line, game);
            }
            else
                map_started = true;
        }

        if (map_started)
        {
            if (row >= game->MAP_HEIGHT)
            {
                fprintf(stderr, "Error: Map exceeds defined height\n");
                free_map(game->map);
                exit(EXIT_FAILURE);
            }
            game->map[row++] = line;  // Armazena a string duplicada
        }
        else
        {
            free(line);  // Se não for parte do mapa, libera a linha
        }
        i++;
    }

    game->map[row] = NULL;
    /* Opcional: atualize game->MAP_HEIGHT com o número real de linhas lidas */
    game->MAP_HEIGHT = row;
}
