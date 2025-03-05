/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tales <tales@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 16:39:22 by sanweber          #+#    #+#             */
/*   Updated: 2025/03/05 12:13:46 by tales            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

void	error_system(char *str)
{
	perror(str);
	exit(EXIT_FAILURE);
}

void	remove_spaces(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] != ' ')
		{
			str[j] = str[i];
			j++;
		}
		i++;
	}
	str[j] = '\0';
}

int	test_view(char *view, int *flags)
{
	if ((view[0] == 'N' && view[1] == 'O') || (view[0] == 'S' && view[1] == 'O')
		|| (view[0] == 'W' && view[1] == 'E') || (view[0] == 'E'
			&& view[1] == 'A') || (view[0] == 'F') || (view[0] == 'C'))
	{
		if (view[0] == 'N')
			*flags += 1;
		else if (view[0] == 'S')
			*flags += 10;
		else if (view[0] == 'W')
			*flags += 100;
		else if (view[0] == 'E')
			*flags += 1000;
		else if (view[0] == 'F')
			*flags += 10000;
		else
			*flags += 100000;
		return (1);
	}
	return (0);
}

int	parse_map(int fd, char **map, int *map_lines)
{
	char	*line;
	int		flags;

	flags = 0;
	line = get_next_line(fd);
	while ((line) && (*map_lines < 6))
	{
		remove_spaces(line);
		if (test_view(line, &flags))
		{
			map[*map_lines] = malloc(sizeof(char) * (ft_strlen(line)));
			if (!map[*map_lines])
				error_system("Error allocating arguments for map line");
			ft_strlcpy(map[*map_lines], line, ft_strlen(line));
			(*map_lines)++;
		}
		else if (line[0] != '\0' && line[0] != '\n')
			(*map_lines)++;
		free(line);
		if (*map_lines < 6)
			line = get_next_line(fd);
	}
	if (flags == 111111)
		return (1);
	return (0);
}
