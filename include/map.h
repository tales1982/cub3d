/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlima-de <tlima-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 14:59:00 by tlima-de          #+#    #+#             */
/*   Updated: 2025/01/07 15:37:20 by tlima-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Funções e estruturas relacionadas ao mapa
#if !defined(MAP_H)
#define MAP_H

#include <unistd.h>
#include "libft.h"
#include "mlx.h"


// Estrutura para armazenar o mapa
typedef struct s_map
{
    char **map;          // O mapa 2D
    int player_x;        // Coordenada X do jogador
    int player_y;        // Coordenada Y do jogador
    char player_dir;     // Direção inicial do jogador (N, S, E, W)
} t_map;

// Funções
int parse_map(const char *file_path, t_map *map_info);
char **read_file(const char *file_path);
int find_map_start(char **lines);
int validate_map_chars(char **map, t_map *map_info);
int is_surrounded(char **map, int x, int y);
// Declaração da função print_map
void print_map(char **map);


#endif // MAP_H
