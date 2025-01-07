/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tales <tales@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 15:00:49 by tlima-de          #+#    #+#             */
/*   Updated: 2025/01/07 22:22:14 by tales            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Funções utilitárias

#if !defined(UTILS_H)
#define UTILS_H

#include "cub3d.h"
#include <stdbool.h>

//funções de distância
float distance(float x, float y);
float fixed_dist(float x1, float y1, float x2, float y2, t_game *game);
bool touch(float px, float py, t_game *game);



#endif// UTILS_H