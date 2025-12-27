/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 18:29:52 by joao-alm          #+#    #+#             */
/*   Updated: 2025/12/27 18:55:49 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIMAP_BONUS_H
# define MINIMAP_BONUS_H

// Settings
#define MINIMAP_RADIUS 7
#define MINIMAP_TILE_SIZE 15
#define MINIMAP_SIZE (MINIMAP_RADIUS * 2 * MINIMAP_TILE_SIZE)
#define MINIMAP_MARGIN 20
#define MINIMAP_WALL_COLOR 0x404040
#define MINIMAP_FLOOR_COLOR 0xC0C0C0
#define MINIMAP_PLAYER_COLOR 0xFF0000
#define MINIMAP_BG_COLOR 0x000000

typedef struct s_game t_game;  // forward declaration
void	draw_minimap(t_game *game);

#endif