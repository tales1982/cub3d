/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlima-de <tlima-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 14:59:00 by tlima-de          #+#    #+#             */
/*   Updated: 2025/01/13 12:42:47 by tlima-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Funções e estruturas relacionadas ao mapa
#if !defined(MAP_H)
#define MAP_H

#include "render.h" // Para usar draw_square
#include "libft.h" // Certifique-se de incluir isso
#include <fcntl.h>    // Para open()
#include <unistd.h>   // Para read() e close()
#include <stdlib.h>   // Para malloc()
#include <stdio.h>    // Para perror()


#define MAP_HEIGHT 15
#define MAP_WIDTH  30 // Ajuste conforme a largura do seu mapa


//funções
void draw_map(t_game *game);
void load_map(const char *file_path, t_game *game);
void free_map(char **map);

#endif // MAP_H
