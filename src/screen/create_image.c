/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptopping <ptopping@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 16:58:53 by ptopping          #+#    #+#             */
/*   Updated: 2022/10/18 18:25:59 by ptopping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ray_culc(t_raycast *raycast, int x, t_player *player)
{
	raycast->camera.x = 2 * x / (double)WIDTH - 1;
	raycast->ray_dir.x = raycast->dir.x + raycast->plane.x * raycast->camera.x;
	raycast->ray_dir.y = raycast->dir.y + raycast->plane.y * raycast->camera.x;
	raycast->map_x = (int)(player->x);
	raycast->map_y = (int)(player->y);
	if (raycast->ray_dir.x == 0)
		raycast->delta_dist.x = 1e30;
	else
		raycast->delta_dist.x = fabs(1 / raycast->ray_dir.x);
	if (raycast->ray_dir.y == 0)
		raycast->delta_dist.y = 1e30;
	else
		raycast->delta_dist.y = fabs(1 / raycast->ray_dir.y);
}

void	dirs_to_steps(t_raycast *raycast, t_player *player)
{
	if (raycast->ray_dir.x < 0)
	{
		raycast->step_x = -1;
		raycast->side_dist.x = (player->x - raycast->map_x)
			* raycast->delta_dist.x;
	}
	else
	{
		raycast->step_x = 1;
		raycast->side_dist.x = (raycast->map_x + 1.0 - player->x)
			* raycast->delta_dist.x;
	}
	if (raycast->ray_dir.y < 0)
	{
		raycast->step_y = -1;
		raycast->side_dist.y = (player->y - raycast->map_y)
			* raycast->delta_dist.y;
	}
	else
	{
		raycast->step_y = 1;
		raycast->side_dist.y = (raycast->map_y + 1.0 - player->y)
			* raycast->delta_dist.y;
	}
}

void	culc_draw_limits(t_data *data)
{
	data->draw_limits->line_height = (int)
		(HEIGHT / data->raycast->perp_walldst);
	data->draw_limits->draw_start = -data->draw_limits->line_height / 2
		+ HEIGHT / 2;
	if (data->draw_limits->draw_start < 0)
		data->draw_limits->draw_start = 0;
	data->draw_limits->draw_end = data->draw_limits->line_height / 2
		+ HEIGHT / 2;
	if (data->draw_limits->draw_end >= HEIGHT)
		data->draw_limits->draw_end = HEIGHT - 1;
}

void	create_image(t_data *data)
{
	int	x;

	x = 0;
	data->image->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->image->addr = mlx_get_data_addr(data->image->img, &data->image->bpp,
			&data->image->line_length, &data->image->endian);
	while (x < WIDTH)
	{
		ray_culc(data->raycast, x, data->player);
		dirs_to_steps(data->raycast, data->player);
		dda(data);
		culc_txt(data->raycast, data->player);
		culc_draw_limits(data);
		line_render(data, x);
		x++;
	}
	draw_mini_map(data);
	mlx_put_image_to_window(data->mlx, data->win, data->image->img, 0, 0);
}
