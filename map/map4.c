/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map4.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tales <tales@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 12:05:57 by tales             #+#    #+#             */
/*   Updated: 2025/03/05 12:11:55 by tales            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

int	load_map2(int fd, char **map, int *map_lines, int *map_width)
{
	*map_lines = 0;
	if (!parse_map(fd, map, map_lines))
	{
		printf("Error: Invalid Textures or Colors\n");
		return (0);
	}
	charge_map(fd, map, map_lines, map_width);
	return (1);
}

int	validate_map(char **map, int map_lines)
{
	int	i;
	int	flag;

	flag = 0;
	i = 6;
	while (i < map_lines)
	{
		if (!is_valid_map_line(map[i], &flag))
		{
			printf("Error: Map Line %d Invalid\n", ((i - 6) + 1));
			return (0);
		}
		i++;
	}
	if (flag != 1)
	{
		printf("Error: One player position is required\n");
		return (0);
	}
	if (!is_map_closed(map, map_lines))
	{
		printf("Error: Map is not Closed\n");
		return (0);
	}
	return (1);
}

/* Função original refatorada para utilizar as duas novas funções */
int	mapvalid(int fd, char **map, int *map_lines, int *map_width)
{
	if (!load_map2(fd, map, map_lines, map_width))
		return (0);
	if (!validate_map(map, *map_lines))
		return (0);
	return (1);
}
