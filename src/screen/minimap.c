/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptopping <ptopping@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 20:02:27 by ptopping          #+#    #+#             */
/*   Updated: 2022/10/16 21:38:00 by ptopping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_mini_map(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	data->minimap->minimap_x = 0;
	data->minimap->minimap_y = 0;
	while (data->map[y] != NULL)
	{
		x = 0;
		data->minimap->minimap_x = 0;
		while (data->map[y][x] != '\n' && data->map[y][x] != '\0')
		{
			if (data->map[y][x] != ' ')
				ft_scuare(data, data->map[y][x], x, y);
			x++;
			data->minimap->minimap_x = x * data->minimap->minimap_scale;
		}
		y++;
		data->minimap->minimap_y = data->minimap->minimap_scale * y;
	}
}

void	ft_scuare(t_data *data, char c, int x, int y)
{
	if (c == '1')
		data->minimap->colour = COL_MINIMAP_WALL;
	else
		data->minimap->colour = COL_MINIMAP_SPACE;
	if ((int)data->player->x == y && (int)data->player->y == x)
		data->minimap->colour = COL_MINIMAP_PL;
	put_colour(data->minimap, data->image);
}

void	calc_map_scale(int *scale)
{
	if (WIDTH > HEIGHT)
		*scale = HEIGHT / 60;
	else
		*scale = WIDTH / 60;
}

void	put_colour(t_minimap *minimap, t_image *image)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i <= minimap->minimap_scale)
	{
		while (j <= minimap->minimap_scale)
		{
			my_mlx_pixel_put(image, minimap->minimap_x + i,
				minimap->minimap_y + j, minimap->colour);
			j++;
		}
		j = 0;
		i++;
	}
}
