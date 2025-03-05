/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tales <tales@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 14:59:00 by tlima-de          #+#    #+#             */
/*   Updated: 2025/03/05 12:09:28 by tales            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Funções e estruturas relacionadas ao mapa
#if !defined(MAP_H)
# define MAP_H

# include "libft.h"
# include "render.h"
# include "textures.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# define MAX_LINE 256
# define MAX_MAP_LINES 100

# define WIDTH 1280
# define HEIGHT 720

void	draw_map(t_game *game);
void	load_map(char **map, t_game *game);
void	free_map(char **map);
int		exit_program(t_game *game);
//int		mapvalid(int fd, char **map, int *map_lines, int *map_width);
void	init_game(t_game *game, char **map);
void	error_system(char *str);
void	charge_map(int fd, char **map, int *map_lines, int *map_width);
bool	is_texture_or_color(char *line);
void	process_line(char *line, bool *map_started, t_game *game);
void	remove_spaces(char *str);
int		test_view(char *view, int *flags);
int		parse_map(int fd, char **map, int *map_lines);
int		is_valid_char(char c, int *flag);
int		is_valid_map_line(const char *line, int *flag);
int		is_map_closed(char **map, int map_lines);
int		load_map2(int fd, char **map, int *map_lines, int *map_width);
int		validate_map(char **map, int map_lines);
int		mapvalid(int fd, char **map, int *map_lines, int *map_width);

#endif
