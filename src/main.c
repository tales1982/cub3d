/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tales <tales@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 15:01:12 by tlima-de          #+#    #+#             */
/*   Updated: 2025/01/06 22:10:02 by tales            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Função principal

#include "mlx.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    void *mlx;
    void *win;
    
    mlx = mlx_init();//inicializa a conexão com o servidor gráfico
    win = mlx_new_window(mlx, 800, 600, "Cub3d");//tamanho da janela mais o título
    mlx_pixel_put(mlx, win, 400, 300, 0x00FF0000);//posição do pixel x, y, cor
    mlx_loop(mlx);//loop para manter a janela aberta

    return (0);
}
