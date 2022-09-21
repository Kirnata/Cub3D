/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptopping <ptopping@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 17:51:37 by ptopping          #+#    #+#             */
/*   Updated: 2022/09/21 15:52:14 by ptopping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int draw_line(t_data *data, int x)
{
	int	y;

	y = 0;
	while (y < data->game->drawEnd)
	{
		my_mlx_pixel_put(data->img, x, y, 0x0066CCFF);//земля
		y++;
	}
	while (y >= data->game->drawEnd && y < data->game->drawStart)
	{
		my_mlx_pixel_put(data->img, x, y, 0x00FF9999);//забор
		y++;
	}
	while (y >= data->game->drawStart && y < HEIGHT)
	{
		my_mlx_pixel_put(data->img, x, y, 0x00CC9966);//blue
		y++;
	}
	printf("drawStart->%d\n", data->game->drawStart);
	printf("drawEnd->%d\n", data->game->drawEnd);
	return (0);
}

int create_line(t_data *data, int x)
{
    //пересчитать какую то хуйню и отрисовать draw_line
	//Calculate height of line to draw on screen
	data->game->lineHeight = (int)(HEIGHT / data->game->perpWallDist);

	//calculate lowest and highest pixel to fill in current stripe
	data->game->drawStart = -(data->game->lineHeight) / 2 + HEIGHT / 2;
	if (data->game->drawStart < 0)
		data->game->drawStart = 0;
	data->game->drawEnd = data->game->lineHeight / 2 + HEIGHT / 2;
	if (data->game->drawEnd >= HEIGHT)
		data->game->drawEnd = HEIGHT - 1;
	draw_line(data, x);
	return (0);
}

int ft_steps(t_data *data, int x)
{
	data->game->camera.x = 2.0 * x / WIDTH - 1.0; //x-coordinate in camera space
	data->game->rayDir.x = data->game->dir.x + data->game->plane.x * data->game->camera.x;
	data->game->rayDir.y = data->game->dir.y + data->game->plane.y * data->game->camera.x;
	data->game->mapX = data->game->pos.x;
	data->game->mapY = data->game->pos.y;
	data->game->deltaDist.x = fabs(1.0 / data->game->rayDir.x);
	data->game->deltaDist.y = fabs(1.0 / data->game->rayDir.y);
	//sleep(2);
	printf("x->%d\n", x);
	printf("data->game->rayDir.x  %f\n", data->game->rayDir.x);
	printf("data->game->rayDir.y  %f\n", data->game->rayDir.y);
	// printf("data->game->deltaDist.x  %f\n", data->game->deltaDist.x);
	// printf("data->game->deltaDist.y  %f\n", data->game->deltaDist.y);
	//return (0);
	//exit(0);
	data->game->stepX = 1;
	data->game->sideDist.x = (data->game->mapX + 1.0 - data->game->pos.x) * data->game->deltaDist.x;
	data->game->stepY = 1;
	data->game->sideDist.y = (data->game->mapY + 1.0 - data->game->pos.y) * data->game->deltaDist.y;
	if (data->game->rayDir.x < 0)
	{
		data->game->stepX = -1;
		data->game->sideDist.x = (data->game->pos.x - data->game->mapX) * data->game->deltaDist.x;
	}
	else
	{
		data->game->stepX = 1;
		data->game->sideDist.x = (data->game->mapX + 1.0 - data->game->pos.x) * data->game->deltaDist.x;
	}
	if (data->game->rayDir.y < 0)
	{
		data->game->stepY = -1;
		data->game->sideDist.y = (data->game->pos.y - data->game->mapY) * data->game->deltaDist.y;
	}
	else
	{
		data->game->stepY = 1;
		data->game->sideDist.y = (data->game->mapY + 1.0 - data->game->pos.y) * data->game->deltaDist.y;
	}
	return (0);
}

int dda(t_data *data)
{
	while (!data->game->hit)
    {
		//printf("hui\n");
		break;
        //jump to next map square, either in x-direction, or in y-direction
		if (data->game->sideDist.x < data->game->sideDist.y)
		{
			data->game->sideDist.x += data->game->deltaDist.x;
			data->game->mapX += data->game->stepX;
			data->game->side = 0;
			printf("hui\n");
		}
		else
		{
			data->game->sideDist.y += data->game->deltaDist.y;
			data->game->mapY += data->game->stepY;
			data->game->side = 1;
			printf("hui\n");
		}
		//Check if ray has hit a wall
		printf("data->game->mapX  %d\n", data->game->mapX);
		printf("data->game->mapY  %d\n", data->game->mapY);
		//return (0);
		// if (data->map[data->game->mapX][data->game->mapY] > 0)
		// 	data->game->hit = 1;
    }
	//return (0);
	if (data->game->side == 0)
		data->game->perpWallDist = (data->game->sideDist.x - data->game->deltaDist.x);
    else
		data->game->perpWallDist = (data->game->sideDist.y - data->game->deltaDist.y);
	//printf("data->game->sideDist.x  %f\n", data->game->sideDist.x);
	printf("data->game->deltaDist.x  %f\n", data->game->deltaDist.x);
	printf("data->game->perpWallDist  %f\n", data->game->perpWallDist);
	// exit(0);
	return (0);
}

int draw_image(t_data *data)
{
	int	x;

    x = 0;
    data->img->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
    data->img->addr = mlx_get_data_addr(data->img->img, &data->img->bits_per_pixel, &data->img->line_length,
								&data->img->endian);//достаем адрес изображения
    while (x < WIDTH)
    {
    	ft_steps(data, x);
        dda(data);
		create_line(data, x);
        x++;
    }
    //внутри dda рассчитывается необходимое и внутри же вызывается draw_lines
    mlx_put_image_to_window(data->mlx, data->win, data->img->img, 0, 0);
	return (0);
}

// int render(t_data *data)
// {
//     //удалить->пересчитать->очистить заново
//     draw_image(data);
// }
