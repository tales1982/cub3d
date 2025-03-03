/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tales <tales@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 11:18:19 by tlima-de          #+#    #+#             */
/*   Updated: 2025/03/03 16:44:57 by tales            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURES_H
# define TEXTURES_H

# include "cub3d.h" // Para a estrutura t_game
# include "libft.h"
# include "mlx.h"

void	load_textures(const char *line, t_textures *textures);
void	parse_colors(const char *line, t_game *game);
void	load_images(void *mlx, t_textures *textures);

#endif
