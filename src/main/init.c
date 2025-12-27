/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 15:25:18 by joao-alm          #+#    #+#             */
/*   Updated: 2025/12/27 17:20:20 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "game.h"
#include "lft_error.h"
#include "mlx.h"
#include <stddef.h>

int	ft_init(t_game *game)
{
	game->map.matrix = NULL;
	game->map.height = -1;
	game->map.width = -1;
	game->map.n_texture = NULL;
	game->map.e_texture = NULL;
	game->map.s_texture = NULL;
	game->map.w_texture = NULL;
	game->map.f_colour = -1;
	game->map.c_colour = -1;
	game->player.pos.x = -1;
	game->player.pos.y = -1;
	game->player.dir.x = -1;
	game->player.dir.y = -1;
	game->player.plane.x = -1;
	game->player.plane.y = -1;
	game->mlx = mlx_init();
	if (!game->mlx)
		return (put_error("Mlx failed to initialize", E_MLX_INIT));
	game->win.win = NULL;
	return (0);
}
