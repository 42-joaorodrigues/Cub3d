/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 00:00:00 by joao-alm          #+#    #+#             */
/*   Updated: 2025/12/27 18:56:26 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphic.h"
#include "minimap_bonus.h"
#include <math.h>

static int	is_inside_circle(int x, int y, int center, int radius)
{
	int	dx;
	int	dy;

	dx = x - center;
	dy = y - center;
	return (dx * dx + dy * dy <= radius * radius);
}

static void	put_pixel_minimap(t_game *game, int x, int y, int color)
{
	int	screen_x;
	int	screen_y;

	screen_x = MINIMAP_MARGIN + x;
	screen_y = MINIMAP_MARGIN + y;
	if (screen_x >= 0 && screen_x < game->win.width
		&& screen_y >= 0 && screen_y < game->win.height)
	{
		((unsigned int *)game->ray.addr)[screen_y * (game->ray.line_len / 4)
			+ screen_x] = color;
	}
}

static int	get_map_tile(t_game *game, double map_x, double map_y)
{
	int	mx;
	int	my;

	mx = (int)map_x;
	my = (int)map_y;
	if (mx < 0 || mx >= game->map.width || my < 0 || my >= game->map.height)
		return ('1');
	return (game->map.matrix[my][mx]);
}

static void	draw_rotated_tile(t_game *game, int sx, int sy, t_vector *rot)
{
	double	rel_x;
	double	rel_y;
	double	world_x;
	double	world_y;
	double	map_x;
	double	map_y;
	int		tile;
	int		color;

	rel_x = (sx - MINIMAP_SIZE / 2) / (double)MINIMAP_TILE_SIZE;
	rel_y = (sy - MINIMAP_SIZE / 2) / (double)MINIMAP_TILE_SIZE;
	world_x = rel_x * rot[0].x + rel_y * rot[0].y;
	world_y = rel_x * rot[1].x + rel_y * rot[1].y;
	map_x = game->player.pos.x + world_x;
	map_y = game->player.pos.y + world_y;
	tile = get_map_tile(game, map_x, map_y);
	if (tile == '1')
		color = MINIMAP_WALL_COLOR;
	else
		color = MINIMAP_FLOOR_COLOR;
	put_pixel_minimap(game, sx, sy, color);
}

static void	draw_player_indicator(t_game *game)
{
	int	center;
	int	px;
	int	py;
	int	size;

	center = MINIMAP_SIZE / 2;
	size = MINIMAP_TILE_SIZE / 3;
	py = -size;
	while (py <= size)
	{
		px = -size;
		while (px <= size)
		{
			if (px * px + py * py <= size * size)
				put_pixel_minimap(game, center + px, center + py,
					MINIMAP_PLAYER_COLOR);
			px++;
		}
		py++;
	}
}

void	draw_minimap(t_game *game)
{
	int			x;
	int			y;
	int			center;
	int			radius;
	t_vector	rotation[2];

	center = MINIMAP_SIZE / 2;
	radius = MINIMAP_SIZE / 2;
	rotation[0].x = game->player.dir.y;
	rotation[0].y = -game->player.dir.x;
	rotation[1].x = -game->player.dir.x;
	rotation[1].y = -game->player.dir.y;
	y = 0;
	while (y < MINIMAP_SIZE)
	{
		x = 0;
		while (x < MINIMAP_SIZE)
		{
			if (is_inside_circle(x, y, center, radius))
				draw_rotated_tile(game, x, y, rotation);
			// else
			// 	put_pixel_minimap(game, x, y, MINIMAP_BG_COLOR);
			x++;
		}
		y++;
	}
	draw_player_indicator(game);
}
