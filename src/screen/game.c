/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpono <bpono@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 16:33:15 by ptopping          #+#    #+#             */
/*   Updated: 2022/10/13 15:59:33 by bpono            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	game(t_data *data)
{
	data_init(data);
	create_image(data);
	mlx_hook(data->win, 2, 0, key_press, data);
	mlx_hook(data->win, 3, 0, key_release, data);
	mlx_hook(data->win, ON_DESTROY, 0, exit_cleaner, data);
	mlx_loop_hook(data->mlx, render_after_move, data);
	mlx_loop(data->mlx);
	return (0);
}
