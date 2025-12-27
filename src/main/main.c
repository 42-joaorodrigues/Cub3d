/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 15:50:38 by fsilva-p          #+#    #+#             */
/*   Updated: 2025/12/27 17:20:20 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "keyhook.h"
#include "error.h"
#include "game.h"
#include "graphic.h"
#include "input.h"
#include "lft_error.h"
#include "mlx.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		return (put_error("Usage: ./cub3D <map_path>", E_ARGS));
	if (ft_init(&game) != 0)
		return (*ft_exit_code());
	if (ft_input(argv[1], &game) != 0)
		return (ft_free_game(&game), *ft_exit_code());
	game.win.height = WIN_HEIGHT;
	game.win.width = WIN_HEIGHT * WIN_RATIO;
	game.win.win = mlx_new_window(game.mlx, game.win.width, game.win.height,
			"cub3D");
	ft_draw(&game);
	handle_input(&game);
	mlx_loop(game.mlx);
	ft_free_game(&game);
	return (0);
}
