/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlima-de <tlima-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 15:01:12 by tlima-de          #+#    #+#             */
/*   Updated: 2025/01/07 16:21:47 by tlima-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Função principal
#include "map.h"
#include "player.h"
#include "render.h"
#include "mlx.h"
#include "map.h"
#include <stdio.h> // Para perror()


int main()
{
    void *mlx;
    void *window;
    void *image;
    int img_width, img_height;
    int win_width = 800;
    int win_height = 600;
    int x, y;

    // Inicialize MiniLibX
    mlx = mlx_init();
    if (!mlx)
        return (1);

    // Crie uma janela
    window = mlx_new_window(mlx, win_width, win_height, "Cub3D");
    if (!window)
        return (1);

    // Carregar a imagem XPM
    image = mlx_xpm_file_to_image(mlx, "./asserts/textures/3.xpm", &img_width, &img_height);
    if (!image)
    {
        perror("Error loading XPM file");
        return (1);
    }

    // Preencher a janela com a imagem
    y = 0;
    while (y < win_height)
    {
        x = 0;
        while (x < win_width)
        {
            mlx_put_image_to_window(mlx, window, image, x, y);
            x += img_width; // Move horizontalmente pelo tamanho da imagem
        }
        y += img_height; // Move verticalmente pelo tamanho da imagem
    }

    // Loop para manter a janela aberta
    mlx_loop(mlx);

    return (0);
}



