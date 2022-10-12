/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptopping <ptopping@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 16:58:53 by ptopping          #+#    #+#             */
/*   Updated: 2022/10/12 21:56:27 by ptopping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ray_culc(t_raycast *raycast, int x, t_player *player)
{
	raycast->camera.x = 2 * x / (double)WIDTH - 1;
	raycast->rayDir.x = raycast->dir.x + raycast->plane.x * raycast->camera.x;
	raycast->rayDir.y = raycast->dir.y + raycast->plane.y * raycast->camera.y;
	raycast->mapX = (int)(player->x);
	raycast->mapY = (int)(player->y);
	raycast->deltaDist.x = (raycast->rayDir.x == 0) ? 1e30 : fabs(1 / raycast->rayDir.x);
	raycast->deltaDist.y = (raycast->rayDir.y == 0) ? 1e30 : fabs(1 / raycast->rayDir.y);
}

void	dirs_to_steps(t_raycast *raycast, t_player *player)
{
    if(raycast->rayDir.x < 0)
    {
      raycast->stepX = -1;
      raycast->sideDist.x = (player->x - raycast->mapX) * raycast->deltaDist.x;
    }
    else
    {
      raycast->stepX = 1;
      raycast->sideDist.x = (raycast->mapX + 1.0 - player->x) * raycast->deltaDist.x;
    }
    if(raycast->rayDir.y < 0)
    {
      raycast->stepY = -1;
      raycast->sideDist.y = (player->y - raycast->mapY) * raycast->deltaDist.y;
    }
    else
    {
      raycast->stepY = 1;
      raycast->sideDist.y = (raycast->mapY + 1.0 - player->y) * raycast->deltaDist.y;
    }
}

void perp_culc(t_raycast *raycast)
{
    if (raycast->side == 0)
    {
		if (raycast->sideDist.x == raycast->deltaDist.x)
			raycast->perpWallDist= 0.9;
		else
			raycast->perpWallDist = raycast->sideDist.x - raycast->deltaDist.x + 0.15;
	}
	else
	{
		if (raycast->sideDist.y == raycast->deltaDist.y)
			raycast->perpWallDist = 0.9;
		else
      raycast->perpWallDist =  raycast->sideDist.y - raycast->deltaDist.y + 0.15;
	}
}

void	dda(t_data *data)
{
	int	hit;

	hit = 0;
	while(hit == 0)
	{
		if(data->raycast->sideDist.x < data->raycast->sideDist.y)
		{
			data->raycast->sideDist.x += data->raycast->deltaDist.x;
			data->raycast->mapX += data->raycast->stepX;
			data->raycast->side = 0;
		}
		else
		{
			data->raycast->sideDist.y += data->raycast->deltaDist.y;
			data->raycast->mapY += data->raycast->stepY;
			data->raycast->side = 1;
		}
		if (data->map[data->raycast->mapX][data->raycast->mapY] == '1')//> '0' не баг, а фича
			hit = 1;
	}
	perp_culc(data->raycast);
}

void	culc_txt(t_raycast *raycast, t_player *player)
{
	if (raycast->side == 0)
		raycast->wallX = player->y + raycast->perpWallDist * raycast->rayDir.y;
	else
		raycast->wallX = player->x + raycast->perpWallDist * raycast->rayDir.x;
	raycast->wallX -= floorf(raycast->wallX);
	raycast->texX = (int)(raycast->wallX * (double)(TEXWIDTH));
	if (raycast->side == 0 && raycast->rayDir.x > 0)
		raycast->texX = TEXWIDTH - raycast->texX - 1;
	if (raycast->side == 1 && raycast->rayDir.y < 0)
		raycast->texX = TEXWIDTH - raycast->texX - 1;
}

void	culc_draw_limits(t_data *data)
{
	data->draw_limits->lineHeight = (int)(HEIGHT / data->raycast->perpWallDist);
	data->draw_limits->drawStart = -data->draw_limits->lineHeight / 2 + HEIGHT / 2;
	if (data->draw_limits->drawStart < 0)
		data->draw_limits->drawStart = 0;
	data->draw_limits->drawEnd = data->draw_limits->lineHeight / 2 + HEIGHT / 2;
	if (data->draw_limits->drawEnd >= HEIGHT)
		data->draw_limits->drawEnd = HEIGHT - 1;
}

void	create_image(t_data *data)
{
	int	x;

	x = 0;
	data->image->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->image->addr = mlx_get_data_addr(data->image->img, &data->image->bits_per_pixel,
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
