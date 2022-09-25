/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_render.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptopping <ptopping@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 17:28:09 by ptopping          #+#    #+#             */
/*   Updated: 2022/09/24 17:38:39 by ptopping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int line_render(t_data *data)
{
    int   y;

    y = 0;
	while (y < HEIGHT)
	{
		if (y < data->draw_limits->drawStart)
			my_mlx_pixel_put(data->draw_limits->, x, y, 0x00CC9966);//blue
		else if (y >= data->draw_limits->drawStart && y < data->draw_limits->drawEnd)
			my_mlx_pixel_put(data->image, x, y, 0x00FF9999);//забор
		else if (y < HEIGHT)
			my_mlx_pixel_put(data->image, x, y, 0x0066CCFF);//земля
		y++;
	}
	return (0);
}  
}