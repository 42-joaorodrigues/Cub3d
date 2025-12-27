/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filename.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 15:41:56 by joao-alm          #+#    #+#             */
/*   Updated: 2025/12/27 17:20:20 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "input_int.h"
#include "lft_error.h"
#include "lft_string.h"

int	ft_filename(const char *path)
{
	int	len;

	if (!*path)
		return (put_error("Map path can't be empty", E_PATH_EMPTY));
	len = ft_strlen(path);
	if (len < 4 || ft_strcmp(path + len - 4, ".cub") != 0)
		return (put_error("Wrong map file extension. Only '.cub' allowed",
				E_PATH_EXT));
	return (0);
}
