/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlima-de <tlima-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 15:00:34 by tlima-de          #+#    #+#             */
/*   Updated: 2025/01/07 14:46:54 by tlima-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


//funções e estruturas relacionadas à renderização

#if !defined(RENDER_H)
#define RENDER_H

#include <unistd.h>
#include "libft.h"
#include "mlx.h"



void render_minimap(void *mlx, void *win, char **map, int player_x, int player_y);


#endif // RENDER_H