/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptopping <ptopping@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 16:58:53 by ptopping          #+#    #+#             */
/*   Updated: 2022/09/27 21:03:05 by ptopping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void ray_culc(t_raycast *raycast, int x, t_player *player)
{
	int w = WIDTH;
	raycast->camera.x = 2 * x / (double) w - 1;//x-coordinate in camera space
	raycast->rayDir.x = raycast->dir.x + raycast->plane.x * raycast->camera.x;
	raycast->rayDir.y = raycast->dir.y + raycast->plane.y * raycast->camera.y;
	//which box of the map we're in

	raycast->mapX = (int)(player->x);
	raycast->mapY = (int)(player->y);
	// printf("%i-%i- mapa in rayculc\n", raycast->mapX, raycast->mapY);
	// printf("%i-%i - x and y in player in ray_culc\n", player->x, player->y);
	raycast->deltaDist.x = (raycast->rayDir.x == 0) ? 1e30 : fabs(1 / raycast->rayDir.x);
	raycast->deltaDist.y = (raycast->rayDir.y == 0) ? 1e30 : fabs(1 / raycast->rayDir.y);
}

void    dirs_to_steps(t_raycast *raycast, t_player *player)
{
    //what direction to step in x or y-direction (either +1 or -1)
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
    //printf("%f -  perpWallDist \n", raycast->perpWallDist);
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
        printf("%i-%i raycast->mapX, raycast->mapY in dda\n", raycast->mapX, raycast->mapY);
        if (data->map[raycast->mapX][raycast->mapY] > '0')
          hit = 1;
    }
    perp_culc(raycast);
}

void    culc_draw_limits(t_data *data, t_raycast *raycast)
{
	int h = HEIGHT;
	printf("%f -  perpWallDist \n", raycast->perpWallDist);
    data->draw_limits->lineHeight = (int)(h / raycast->perpWallDist);
    //calculate lowest and highest pixel to fill in current stripe
	//   	printf("%i - drawStart\n", data->draw_limits->drawStart);
	// printf("%i - drawEnd\n", data->draw_limits->drawEnd);
	// int u;
	// u = (int)1080/0.0;
	// printf("%d\n",u);
  	printf("%i -  lineHeight\n", data->draw_limits->lineHeight);
    data->draw_limits->drawStart = -data->draw_limits->lineHeight / 2 + h / 2;
    if(data->draw_limits->drawStart < 0)
		data->draw_limits->drawStart = 0;
    data->draw_limits->drawEnd = data->draw_limits->lineHeight / 2 + h / 2;
    if(data->draw_limits->drawEnd >= h)
		data->draw_limits->drawEnd = h - 1;
	printf("%i-%i, data->draw_limits->drawStart, data->draw_limits->drawEnd", data->draw_limits->drawStart, data->draw_limits->drawEnd);
	// printf("%i - drawStart\n", data->draw_limits->drawStart);
	// printf("%i - drawEnd\n", data->draw_limits->drawEnd);
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
      ray_culc(raycast, x, data->player);
      dirs_to_steps(raycast, data->player);
      dda(data, raycast);
      culc_draw_limits(data, raycast);
      line_render(data, x);
      x++;
    }
    //внутри dda рассчитывается необходимое и внутри же вызывается draw_lines
    mlx_put_image_to_window(data->mlx, data->win, data->image->img, 0, 0);
	return (0);
}