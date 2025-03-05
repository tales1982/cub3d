/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tales <tales@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 16:39:22 by sanweber          #+#    #+#             */
/*   Updated: 2025/03/05 11:50:13 by tales            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

int	is_valid_char(char c, int *flag)
{
	if (c == ' ' || c == '0' || c == '1' || c == 'N' || c == 'S' || c == 'E'
		|| c == 'W')
	{
		if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
			(*flag)++;
		return (1);
	}
	else
		return (0);
}

int	is_valid_map_line(const char *line, int *flag)
{
	int	i;
	int	inside_block;

	i = 0;
	inside_block = 0;
	while (line[i] != '\0')
	{
		if (line[i] == '1')
			inside_block = 1;
		else if (line[i] == ' ')
		{
			if (inside_block)
			{
				while (line[i] == ' ')
					i++;
				if (line[i] != '1' && line[i] != '\0')
					return (0);
				i--;
			}
		}
		if (!is_valid_char(line[i], flag))
			return (0);
		i++;
	}
	return (1);
}

void	charge_map(int fd, char **map, int *map_lines, int *map_width)
{
	char	*line;
	int		line_width;

	line = get_next_line(fd);
	while ((line) && (line[0] == '\n'))
	{
		free(line);
		line = get_next_line(fd);
	}
	*map_width = 0;
	while (line)
	{
		line_width = ft_strlen(line);
		map[*map_lines] = malloc(sizeof(char) * (line_width));
		if (!map[*map_lines])
			error_system("Error allocating memory for map line");
		ft_strlcpy(map[*map_lines], line, line_width);
		(*map_lines)++;
		if ((line_width - 1) > *map_width)
			*map_width = (line_width - 1);
		free(line);
		line = get_next_line(fd);
	}
}

static int	is_map_border_closed(char **map, int map_lines)
{
	int	i;
	int	j;
	int	len;

	i = 6;
	while (i < map_lines)
	{
		j = 0;
		len = (int)strlen(map[i]);
		while (map[i][j] == ' ')
			j++;
		if (map[i][j] != '1')
			return (0);
		while (len > 0 && map[i][len - 1] == ' ')
			len--;
		if (len > 0 && map[i][len - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	is_map_closed(char **map, int map_lines)
{
	int	i;
	int	j;

	if (!is_map_border_closed(map, map_lines))
		return (0);
	i = 6;
	while (i < map_lines - 1)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] == '0' && ((i > 0 && j >= (int)strlen(map[i - 1]))
					|| (i < map_lines - 1 && j >= (int)strlen(map[i + 1]))
					|| (i > 0 && (map[i - 1][j] == ' ' || map[i
							- 1][j] == '\0')) || (i < map_lines - 1 && (map[i
							+ 1][j] == ' ' || map[i + 1][j] == '\0')) || (j > 0
						&& map[i][j - 1] == ' ') || (map[i][j + 1] != '\0'
						&& map[i][j + 1] == ' ')))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
