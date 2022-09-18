/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptopping <ptopping@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 17:51:37 by ptopping          #+#    #+#             */
/*   Updated: 2022/09/18 20:18:08 by ptopping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int draw_line(int start, int end)


int draw_lines(t_data *data)
{
    //пересчитать какую то хуйню и отрисовать draw_line
}

int ft_steps(t_data *data)
{
    if (data->game->rayDir.x < 0)
      {
        data->game->step.x = -1;
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
}

int dda(t_data *data, int x)
{
    data->game->camera.x = 2 * x / double(WIDTH) - 1; //x-coordinate in camera space
    data->game->rayDir.x = data->game->dir.x + data->game->plane.x * data->game->camera.x;
    data->game->rayDir.y = data->game->dir.y + data->game->plane.y * data->game->camera.x;
}

int draw_image(t_data *data)
{
    int x;

    x = 0;
    data->image->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->image->addr = mlx_get_data_addr(data->image->img, &data->image->bits_per_pixel, &data->image->line_length,
								&data->image->endian);//достаем адрес изображения
    
    while (x < WIDTH)
    {
        ft_steps(data);
        dda(data, x);
        x++;
    }
    //внутри dda рассчитывается необходимое и внутри же вызывается draw_lines
    mlx_put_image_to_window(vars->mlx, vars->win, vars->data->img, 0, 0);
}

int render(t_data *data)
{
    //удалить->пересчитать->очистить заново
    draw_image(data);
}