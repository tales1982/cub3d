/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlima-de <tlima-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 15:01:12 by tlima-de          #+#    #+#             */
/*   Updated: 2025/01/06 16:09:00 by tlima-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Função principal

#include "mlx.h"
#include <stdio.h>
#include <stdlib.h>

#define WIN_WIDTH 800
#define WIN_HEIGHT 600
#define SQUARE_SIZE 50
#define MOVE_SPEED 5

typedef struct s_data
{
    void *mlx_ptr;
    void *win_ptr;
    void *img_ptr;
    char *img_data;
    int bpp;
    int size_line;
    int endian;
    int square_x;
    int square_y;
    int direction_x;
    int direction_y;
} t_data;

void put_pixel_to_image(t_data *data, int x, int y, int color)
{
    int pixel;

    if (x < 0 || x >= WIN_WIDTH || y < 0 || y >= WIN_HEIGHT)
        return;
    pixel = (y * data->size_line) + (x * (data->bpp / 8));
    *(int *)(data->img_data + pixel) = color;
}

void draw_square(t_data *data, int x, int y, int size, int color)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            put_pixel_to_image(data, x + i, y + j, color);
        }
    }
}

void clear_image(t_data *data)
{
    for (int y = 0; y < WIN_HEIGHT; y++)
    {
        for (int x = 0; x < WIN_WIDTH; x++)
        {
            put_pixel_to_image(data, x, y, 0x000000); // Preenche com preto
        }
    }
}

int update(t_data *data)
{
    // Atualiza posição do quadrado
    data->square_x += data->direction_x * MOVE_SPEED;
    data->square_y += data->direction_y * MOVE_SPEED;

    // Verifica colisões com as bordas da janela
    if (data->square_x <= 0 || data->square_x + SQUARE_SIZE >= WIN_WIDTH)
        data->direction_x *= -1;
    if (data->square_y <= 0 || data->square_y + SQUARE_SIZE >= WIN_HEIGHT)
        data->direction_y *= -1;

    // Limpa a imagem
    clear_image(data);

    // Desenha o quadrado atualizado
    draw_square(data, data->square_x, data->square_y, SQUARE_SIZE, 0xFF0000); // Vermelho

    // Atualiza a janela
    mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, 0, 0);

    return (0);
}

int handle_close(void *param)
{
    t_data *data = (t_data *)param;
    mlx_destroy_window(data->mlx_ptr, data->win_ptr);
    exit(0);
    return (0);
}

int main()
{
    t_data data;

    data.mlx_ptr = mlx_init();
    if (!data.mlx_ptr)
    {
        fprintf(stderr, "Erro ao inicializar MiniLibX.\n");
        return (1);
    }

    data.win_ptr = mlx_new_window(data.mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "Cub3D Animation");
    if (!data.win_ptr)
    {
        fprintf(stderr, "Erro ao criar a janela.\n");
        return (1);
    }

    data.img_ptr = mlx_new_image(data.mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
    data.img_data = mlx_get_data_addr(data.img_ptr, &data.bpp, &data.size_line, &data.endian);

    // Inicializa posição do quadrado e direção
    data.square_x = WIN_WIDTH / 2 - SQUARE_SIZE / 2;
    data.square_y = WIN_HEIGHT / 2 - SQUARE_SIZE / 2;
    data.direction_x = 1;
    data.direction_y = 1;

    // Registre a função de fechamento
    mlx_hook(data.win_ptr, 17, 0, handle_close, &data);

    // Atualize a animação continuamente
    mlx_loop_hook(data.mlx_ptr, update, &data);

    // Inicia o loop da MiniLibX
    mlx_loop(data.mlx_ptr);

    return (0);
}
