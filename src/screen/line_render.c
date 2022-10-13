/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_render.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpono <bpono@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 17:28:09 by ptopping          #+#    #+#             */
/*   Updated: 2022/10/13 17:57:49 by bpono            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_image	*choose_txt(t_raycast *raycast, t_player *player, t_textures *txts)
{
	t_image	*txt;

	if (raycast->side == 0 && raycast->map_x < player->x)
		txt = txts->txt_west;
	else if (raycast->side == 0 && raycast->map_x >= player->x)
		txt = txts->txt_east;
	else if (raycast->side == 1 && raycast->map_y < player->y)
		txt = txts->txt_north;
	else if (raycast->side == 1 && raycast->map_y >= player->y)
		txt = txts->txt_south;
	else
	{
		//printf("Alarm! Close the door");
		exit(0);
	}
	return (txt);
}

int	line_render(t_data *data, int x)
{
	int		y;
	t_image	*txt;

	txt = choose_txt(data->raycast, data->player, data->txts);
	y = 0;
	data->raycast->step = (1.0f * TEXHEIGHT / data->draw_limits->line_height);
	data->raycast->tex_pos = (double)((data->draw_limits->draw_start \
		- HEIGHT / 2 + data->draw_limits->line_height / 2)
			* data->raycast->step);
	while (y < data->draw_limits->draw_start)
	{
		my_mlx_pixel_put(data->image, x, y, 0x0066CCFF);//blue)
		y++;
	}
	while (y <= data->draw_limits->draw_end)
	{
		//вот это вообще непонятно
		data->raycast->tex_y = (int)data->raycast->tex_pos & (TEXHEIGHT - 1);
		data->raycast->tex_pos += data->raycast->step;
		my_mlx_pixel_put(data->image, x, y, get_pixel_color(txt,
				TEXWIDTH - data->raycast->tex_x - 1, data->raycast->tex_y));
		y++;
	}
	while (y < HEIGHT)
	{
		my_mlx_pixel_put(data->image, x, y, 0x00CC9966);//земля
		y++;
	}
	return (0);
}
