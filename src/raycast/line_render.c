/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_render.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpono <bpono@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 17:28:09 by ptopping          #+#    #+#             */
/*   Updated: 2022/09/25 21:22:04 by bpono            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int line_render(t_data *data, int x)
{
    int   y;

    y = 0;
	// printf("%i - x\n", x);
	// printf("%i - drawStart\n", data->draw_limits->drawStart);
	// printf("%i - drawEnd\n", data->draw_limits->drawEnd);
	while (y < HEIGHT)
	{
		if (y < data->draw_limits->drawStart)
			my_mlx_pixel_put(data->mlx, x, y, 0x00CC9966);//blue
		else if (y >= data->draw_limits->drawStart && y < data->draw_limits->drawEnd)
			my_mlx_pixel_put(data->image, x, y, 0x00FF9999);//забор
		else if (y < HEIGHT)
			my_mlx_pixel_put(data->image, x, y, 0x0066CCFF);//земля
		y++;
		// printf("%i\n", y);
	}
	return (0);
}