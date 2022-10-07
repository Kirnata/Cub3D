/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_render.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptopping <ptopping@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 17:28:09 by ptopping          #+#    #+#             */
/*   Updated: 2022/10/07 22:23:20 by ptopping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_line(t_raycast *raycast, t_textures *txt, int y, int x)
{
	int	c;

	c = 0;
	raycast->step = (1.0f * TEXTURE_HEIGHT / raycast->line_height);
	raycast->tex_pos = (float)((raycast->draw_start - SCREEN_HEIGHT / 2
				+ raycast->line_height / 2) * raycast->step);
	while (c < raycast->draw_start)
	{
		pixel_put(raycast->pixel, x, c, raycast->main->ceilling);
		c++;
	}
	while (y <= raycast->draw_end)
	{
		raycast->tex_y = (int)raycast->tex_pos & (TEXTURE_HEIGHT - 1);
		raycast->tex_pos += raycast->step;
		pixel_put(raycast->pixel, x, y, get_pixel_color(txt,
				TEXTURE_WIDTH - raycast->tex_x - 1, raycast->tex_y));
		y++;
	}
	while (raycast->draw_end < SCREEN_HEIGHT)
	{
		pixel_put(raycast->pixel, x, raycast->draw_end, raycast->main->floor);
		raycast->draw_end++;
	}
}


int line_render(t_data *data, int y, int x)
{
    int   y;

    y = 0;
	printf("%i-%i, data->draw_limits->drawStart, data->draw_limits->drawEnd\n", data->draw_limits->drawStart, data->draw_limits->drawEnd);
	while (y < HEIGHT)
	{
		if (y < data->draw_limits->drawStart)
			my_mlx_pixel_put(data->image, x, y, 0x0066CCFF);//blue
		else if (y >= data->draw_limits->drawStart && y < data->draw_limits->drawEnd)
		{
			if (data->raycast->side == 0)
				my_mlx_pixel_put(data->image, x, y, 0x00FF9999);//забор
			if (data->raycast->side == 1)
				my_mlx_pixel_put(data->image, x, y, 0x00CC99FF);//забор					
		}
			
		else if (y < HEIGHT)
			my_mlx_pixel_put(data->image, x, y, 0x00CC9966);//земля
		y++;
		// printf("%i\n", y);
	}
	return (0);
}