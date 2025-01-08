/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlima-de <tlima-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 14:59:00 by tlima-de          #+#    #+#             */
/*   Updated: 2025/01/08 13:49:32 by tlima-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Funções e estruturas relacionadas ao mapa
#if !defined(MAP_H)
#define MAP_H

#include "map.h"
#include "render.h" // Para usar draw_square



//funções
char **get_map(void);
void draw_map(t_game *game);
void free_map(char **map);



#endif // MAP_H
