/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptopping <ptopping@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 16:58:53 by ptopping          #+#    #+#             */
/*   Updated: 2022/09/24 18:04:58 by ptopping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void ray_culc(t_raycast *raycast, int x)
{
  int w = WIDTH;
   raycast->camera.x = 2 * x / (double) w - 1;//x-coordinate in camera space
   raycast->rayDir.x = raycast->dir.x + raycast->plane.x * raycast->camera.x;
   raycast->rayDir.y = raycast->dir.y + raycast->plane.y * raycast->camera.y;
   //which box of the map we're in
    raycast->mapX = (int)(raycast->pos.x);
    raycast->mapY = (int)(raycast->pos.y);

    raycast->deltaDist.x = (raycast->rayDir.x == 0) ? 1e30 : fabs(1 / raycast->rayDir.x);
    raycast->deltaDist.y = (raycast->rayDir.y == 0) ? 1e30 : fabs(1 / raycast->rayDir.y);  
}

void    dirs_to_steps(t_raycast *raycast)
{
    //what direction to step in x or y-direction (either +1 or -1)
    if(raycast->rayDir.x < 0)
    {
      raycast->stepX = -1;
      raycast->sideDist.x = (raycast->pos.x - raycast->mapX) * raycast->deltaDist.x;
    }
    else
    {
      raycast->stepX = 1;
      raycast->sideDist.x = (raycast->mapX + 1.0 - raycast->pos.x) * raycast->deltaDist.x;
    }
    if(raycast->rayDir.y < 0)
    {
      raycast->stepY = -1;
      raycast->sideDist.y = (raycast->pos.y - raycast->mapY) * raycast->deltaDist.y;
    }
    else
    {
      raycast->stepY = 1;
      raycast->sideDist.y = (raycast->mapY + 1.0 - raycast->pos.y) * raycast->deltaDist.y;
    }
}

void perp_culc(t_raycast *raycast)
{
    if (raycast->side == 0)
        raycast->perpWallDist = (raycast->sideDist.x - raycast->deltaDist.x);
    else
        raycast->perpWallDist = (raycast->sideDist.y - raycast->deltaDist.y);
}

void    dda(t_data *data, t_raycast *raycast)
{
    int hit;

    hit = 0;
    while(hit == 0)
    {
        //jump to next map square, either in x-direction, or in y-direction
        if(raycast->sideDist.x < raycast->sideDist.y)
        {
            raycast->sideDist.x += raycast->deltaDist.x;
            raycast->mapX += raycast->stepX;
            raycast->side = 0;
        }
        else
        {
            raycast->sideDist.y += raycast->deltaDist.y;
            raycast->mapY += raycast->stepY;
            raycast->side = 1;
        }
        //Check if ray has hit a wall
        if (data->map[raycast->mapX][raycast->mapY] > '0')
        hit = 1;
    }
    perp_culc(raycast);
}

void    culc_draw_limits(t_data *data, t_raycast *raycast)
{
	int h = HEIGHT;
    data->draw_limits->lineHeight = (int)(h / raycast->perpWallDist);
    //calculate lowest and highest pixel to fill in current stripe
    data->draw_limits->drawStart = -data->draw_limits->lineHeight / 2 + h / 2;
    if(data->draw_limits->drawStart < 0)
		data->draw_limits->drawStart = 0;
    data->draw_limits->drawEnd = data->draw_limits->lineHeight / 2 + h / 2;
    if(data->draw_limits->drawEnd >= h)
		data->draw_limits->drawEnd = h - 1;
}

int create_image(t_data *data, t_raycast *raycast)
{
	int	x;

    x = 0;
    data->image->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
    data->image->addr = mlx_get_data_addr(data->image->img, &data->image->bits_per_pixel, &data->image->line_length,
								&data->image->endian);//достаем адрес изображения
    while (x < WIDTH)
    {
      ray_culc(raycast, x);
      dirs_to_steps(raycast);
      dda(data, raycast);
      culc_draw_limits(data, raycast);
      line_render(data);
      x++;
    }
    //внутри dda рассчитывается необходимое и внутри же вызывается draw_lines
    mlx_put_image_to_window(data->mlx, data->win, data->image->img, 0, 0);
	return (0);
}