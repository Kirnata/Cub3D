/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpono <bpono@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 16:58:53 by ptopping          #+#    #+#             */
/*   Updated: 2022/10/13 17:52:35 by bpono            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ray_culc(t_raycast *raycast, int x, t_player *player)
{
	raycast->camera.x = 2 * x / (double)WIDTH - 1;
	raycast->ray_dir.x = raycast->dir.x + raycast->plane.x * raycast->camera.x;
	raycast->ray_dir.y = raycast->dir.y + raycast->plane.y * raycast->camera.y;
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

void	perp_culc(t_raycast *raycast)
{
	if (raycast->side == 0)
	{
		if (raycast->side_dist.x == raycast->delta_dist.x)
			raycast->perp_walldst = 0.9;
		else
			raycast->perp_walldst = raycast->side_dist.x
				- raycast->delta_dist.x + 0.15;
	}
	else
	{
		if (raycast->side_dist.y == raycast->delta_dist.y)
			raycast->perp_walldst = 0.9;
		else
			raycast->perp_walldst = raycast->side_dist.y
				- raycast->delta_dist.y + 0.15;
	}
}

void	dda(t_data *data)
{
	int	hit;

	hit = 0;
	while (hit == 0)
	{
		if (data->raycast->side_dist.x < data->raycast->side_dist.y)
		{
			data->raycast->side_dist.x += data->raycast->delta_dist.x;
			data->raycast->map_x += data->raycast->step_x;
			data->raycast->side = 0;
		}
		else
		{
			data->raycast->side_dist.y += data->raycast->delta_dist.y;
			data->raycast->map_y += data->raycast->step_y;
			data->raycast->side = 1;
		}
		//> '0' не баг, а фича
		if (data->map[data->raycast->map_x][data->raycast->map_y] == '1')
			hit = 1;
	}
	perp_culc(data->raycast);
}

void	culc_txt(t_raycast *raycast, t_player *player)
{
	if (raycast->side == 0)
		raycast->wall_x = player->y + raycast->perp_walldst
			* raycast->ray_dir.y;
	else
		raycast->wall_x = player->x + raycast->perp_walldst
			* raycast->ray_dir.x;
	raycast->wall_x -= floorf(raycast->wall_x);
	raycast->tex_x = (int)(raycast->wall_x * (double)(TEXWIDTH));
	if (raycast->side == 0 && raycast->ray_dir.x > 0)
		raycast->tex_x = TEXWIDTH - raycast->tex_x - 1;
	if (raycast->side == 1 && raycast->ray_dir.y < 0)
		raycast->tex_x = TEXWIDTH - raycast->tex_x - 1;
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
