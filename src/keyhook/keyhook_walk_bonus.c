/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook_walk_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 13:53:30 by fsilva-p          #+#    #+#             */
/*   Updated: 2025/12/27 18:47:51 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "keyhook.h"

static void	move_player(t_game *game, double dx, double dy)
{
	t_vector	new;
	double		margin;

	new.y = game->player.pos.y;
	new.x = game->player.pos.x;
	margin = 0.2;
	if (dx != 0)
	{
		new.x = game->player.pos.x + dx * MOVE_SPEED;
		if (game->map.matrix[(int)(new.y + margin)][(int)(new.x + margin)] != '1'
			&& game->map.matrix[(int)(new.y + margin)][(int)(new.x - margin)] != '1'
			&& game->map.matrix[(int)(new.y - margin)][(int)(new.x + margin)] != '1'
			&& game->map.matrix[(int)(new.y - margin)][(int)(new.x - margin)] != '1')
			game->player.pos.x = new.x;
	}
	if (dy != 0)
	{
		new.y = game->player.pos.y + dy * MOVE_SPEED;
		new.x = game->player.pos.x;
		if (game->map.matrix[(int)(new.y + margin)][(int)(new.x + margin)] != '1'
			&& game->map.matrix[(int)(new.y + margin)][(int)(new.x - margin)] != '1'
			&& game->map.matrix[(int)(new.y - margin)][(int)(new.x + margin)] != '1'
			&& game->map.matrix[(int)(new.y - margin)][(int)(new.x - margin)] != '1')
			game->player.pos.y = new.y;
	}
}

void	walk_w(int keycode, t_game *game)
{
	if (keycode == KEY_W)
		move_player(game, game->player.dir.x, game->player.dir.y);
}

void	walk_s(int keycode, t_game *game)
{
	if (keycode == KEY_S)
		move_player(game, -game->player.dir.x, -game->player.dir.y);
}

void	walk_a(int keycode, t_game *game)
{
	if (keycode == KEY_A)
		move_player(game, -game->player.plane.x, -game->player.plane.y);
}

void	walk_d(int keycode, t_game *game)
{
	if (keycode == KEY_D)
		move_player(game, game->player.plane.x, game->player.plane.y);
}
