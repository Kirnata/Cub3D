/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_render.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptopping <ptopping@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 17:28:09 by ptopping          #+#    #+#             */
/*   Updated: 2022/10/08 17:02:07 by ptopping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_image *choose_txt(t_raycast *raycast, t_player *player, t_textures *txts)
{
	t_image *txt;
	if (raycast->side == 0 && raycast->mapX < player->x)
		txt = txts->txt_west;
	else if (raycast->side == 0 && raycast->mapX >= player->x)
		txt = txts->txt_west;
	else if (raycast->side == 1 && raycast->mapY < player->y)
		txt = txts->txt_west;
	else if (raycast->side == 0 && raycast->mapY >= player->y)
		txt = txts->txt_west;
	else
		return (NULL);
	return (txt);
}

/*

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
*/


int line_render(t_data *data, int x)
{
    int   y;
	t_image *txt;

	txt = choose_txt(data->raycast, data->player, data->txts);
    y = 0;
	printf("%i-%i, data->draw_limits->drawStart, data->draw_limits->drawEnd\n", data->draw_limits->drawStart, data->draw_limits->drawEnd);
	data->raycast->step = (1.0f * TEXHEIGHT / data->draw_limits->lineHeight);
	data->raycast->texPos = (float)((data->draw_limits->drawStart - HEIGHT / 2
				+ data->draw_limits->lineHeight / 2) * data->raycast->step);
	while (y < data->draw_limits->drawStart)
	{
		my_mlx_pixel_put(data->image, x, y, 0x0066CCFF);//blue)
		y++;
	}
	while (y <= data->draw_limits->drawEnd)
	{
		//вот это вообще непонятно
		data->raycast->texY = (int)data->raycast->texPos & (TEXHEIGHT - 1);
		data->raycast->texPos += data->raycast->step;
		my_mlx_pixel_put(data->image, x, y, get_pixel_color(txt,
				TEXWIDTH - data->raycast->texX - 1, data->raycast->texY));
	}
	while (y < HEIGHT)
	{
		my_mlx_pixel_put(data->image, x, y, 0x00CC9966);//земля
		y++;
	}
	return (0);
}