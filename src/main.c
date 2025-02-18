/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tales <tales@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 15:01:12 by tlima-de          #+#    #+#             */
/*   Updated: 2025/02/18 15:16:24 by tales            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "player.h"   /* Para key_press e key_release */
#include "render.h"   /* Para draw_loop */
#include "map.h"

/* Callback fechamento da janela e termino do programa so por aqui */
int exit_program(t_game *game)
{
    free_map(game->map);
    exit(0); 
    return (0);
}

int main(int argc, char *argv[]) 
{
    char    map[MAX_MAP_LINES][MAX_LINE];
    int     map_lines;
    int     fd;
    t_game  game;

    if (argc != 2)
	{
		printf("Use: %s <map file>\n", argv[0]);
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		perror("Error: invalid file");
		return (0);
	}
    if (!mapvalid(fd, map, &map_lines))
    {
        close(fd);
        return (0);
    }
    close(fd);
    game.MAP_HEIGHT = map_lines;
   
    printf("LInhas---%d\n", map_lines);
    for(int i = 0; i < map_lines; i++)
    {
        printf("LInhas---%s\n", map[i]);
    }
    game.MAP_WIDTH = 100;
    init_game(&game, map);
    mlx_hook(game.win, 17, 0, exit_program, &game); /*evento fechamento*/
    mlx_hook(game.win, 2, 1L << 0, key_press, &game.player); /*eventos teclado*/
    mlx_hook(game.win, 3, 1L << 1, key_release, &game.player);
    mlx_loop_hook(game.mlx, draw_loop, &game); /*loop principal*/
    mlx_loop(game.mlx);
    return (0);
}