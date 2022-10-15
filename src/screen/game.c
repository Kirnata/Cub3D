/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptopping <ptopping@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 16:33:15 by ptopping          #+#    #+#             */
/*   Updated: 2022/10/15 15:52:29 by ptopping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	structure_malloc(t_data *data)
{
	data->raycast = (t_raycast *)malloc(sizeof(t_raycast));
	if (!data->raycast)
		ft_error(ERR_MALLOC);
	data->image = (t_image *)malloc(sizeof(t_image));
	if (!data->image)
		ft_error(ERR_MALLOC);
	data->draw_limits = (t_draw_limits *)malloc(sizeof(t_draw_limits));
	if (!data->draw_limits)
		ft_error(ERR_MALLOC);
	data->minimap = (t_minimap *)malloc(sizeof(t_minimap));
	if (!data->minimap)
		ft_error(ERR_MALLOC);
	data->txts = (t_textures *)malloc(sizeof(t_textures));
	if (!data->txts)
		ft_error(ERR_MALLOC);
}

void	data_init(t_data *data)
{
	structure_malloc(data);
	data->mlx = NULL;
	data->win = NULL;
	data->mlx = mlx_init();
	if (!data->mlx)
		ft_error(ERR__MLX_INIT);
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "Cub3D");
	if (!data->win)
		ft_error(ERR_WIN_INIT);
	init_direction(&(data->raycast->dir), data->player->name);
	raycast_init(data->raycast);
	image_init(data->image);
	draw_limits_init(data->draw_limits);
	minimap_init(data->minimap);
	txt_init(data);
}

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
