/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tales <tales@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 15:04:37 by tlima-de          #+#    #+#             */
/*   Updated: 2025/01/07 22:41:56 by tales            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"


// função que calcula a distância entre dois pontos
float distance(float x, float y){
    return sqrt(x * x + y * y);
}

// função que calcula a distância fixa entre dois pontos
float fixed_dist(float x1, float y1, float x2, float y2, t_game *game)
{
    float delta_x = x2 - x1;
    float delta_y = y2 - y1;
    float angle = atan2(delta_y, delta_x) - game->player.angle;
    float fix_dist = distance(delta_x, delta_y) * cos(angle);
    return fix_dist;
}

// função que verifica se um ponto toca em uma parede
bool touch(float px, float py, t_game *game)
{
    int x = px / BLOCK;
    int y = py / BLOCK;
    if(game->map[y][x] == '1')
        return true;
    return false;
}