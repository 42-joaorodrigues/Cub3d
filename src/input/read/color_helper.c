/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_helper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 14:21:30 by fsilva-p          #+#    #+#             */
/*   Updated: 2025/12/27 17:18:38 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "lft_conversion.h"
#include "lft_error.h"
#include "lft_gnl.h"
#include "lft_memory.h"
#include "lft_string.h"
#include "mlx.h"
#include "read_int.h"

int	ft_colour_helper(char **split, int *colour)
{
	int	col[3];
	int	valid;

	valid = 1;
	col[0] = ft_atoll_valid(split[0], 0, 255, &valid);
	col[1] = ft_atoll_valid(split[1], 0, 255, &valid);
	col[2] = ft_atoll_valid(split[2], 0, 255, &valid);
	if (!valid)
		return (1);
	*colour = (col[0] << 16) | (col[1] << 8) | col[2];
	return (0);
}
