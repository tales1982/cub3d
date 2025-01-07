/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlima-de <tlima-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 14:59:12 by tlima-de          #+#    #+#             */
/*   Updated: 2025/01/07 14:46:59 by tlima-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Funções e estruturas do jogador

#if !defined(PLAYER_H)
#define PLAYER_H

#include <unistd.h>
#include "libft.h"
#include "mlx.h"



void move_player(int keycode, char **map, int *player_x, int *player_y);


#endif // PLAYER_H

