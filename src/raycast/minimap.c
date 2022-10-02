/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptopping <ptopping@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 20:02:27 by ptopping          #+#    #+#             */
/*   Updated: 2022/10/02 23:58:43 by ptopping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void draw_mini_map(t_data *data)
{
    int x;
    int y;

    x = 0;
    y = 0;
    data->minimap->minimap_x = 0;
    data->minimap->minimap_y = 0;
    while (data->map[y] != NULL)
    {
        while (data->map[y][x] != '\0')
        {
            ft_scuare(data, data->map[y][x], x, y);
            data->minimap->minimap_x = x;
            x++;
        }
        y++;
        x = 0;
        data->minimap->minimap_y = data->minimap->minimap_scale * y;
        
    }
}

void ft_scuare(t_data *data, char c, int x, int y)
{
    if (c == '0')
        data->minimap->colour = 0x00FF6600;
    else if (c == '1')
        data->minimap->colour = 0x00FFFFFF;
    if ((int)data->player->x == x && (int)data->player->y == y)
        data->minimap->colour = 0x0033FF00;
    put_colour(data->minimap, data->image);
}

void    calc_map_scale(int *scale)
{
    if (WIDTH < 1200 && HEIGHT < 1000)
        *scale = 5;
    else 
        *scale = 10;
}

void put_colour(t_minimap *minimap, t_image *image)
{
    int i;
    int j;
    
    i = 0;
    j = 0;
    while (i <= minimap->minimap_scale)
    {
        while (j <= minimap->minimap_scale)
        {
            // if (minimap->colour != 0)
            //printf("%i->minimap->minimap_x + j, %i->minimap->minimap_y + i", minimap->minimap_x + j, minimap->minimap_y + i);
            my_mlx_pixel_put(image, minimap->minimap_x + i, minimap->minimap_y + j, minimap->colour);
            j++;
        }
        j = 0;
        i++;
    }
}