/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_textures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptopping <ptopping@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 19:36:30 by ptopping          #+#    #+#             */
/*   Updated: 2022/10/07 21:58:38 by ptopping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_image new_textures(void *mlx, char *direction, char dir_char)
{
    t_image tecture_info;
    
    tecture_info.img_height = TEXHEIGHT;
    tecture_info.img_weight = TEXWIDTH;
    tecture_info.img = mlx_xpm_file_to_image(mlx, direction, &tecture_info.img_height, &tecture_info.img_weight);
    tecture_info.addr = mlx_get_data_addr(tecture_info.img, &tecture_info.bits_per_pixel,
        &tecture_info.line_length, &tecture_info.endian);
    tecture_info.dir_fl = dir_char;
    return (tecture_info);
}

int create_textures(t_data *data)
{
    data->textures[0] = new_textures(data->mlx, data->xpms_info->west, 'W');
    data->textures[1] = new_textures(data->mlx, data->xpms_info->east, 'E');
    data->textures[2] = new_textures(data->mlx, data->xpms_info->south, 'S');
    data->textures[3] = new_textures(data->mlx, data->xpms_info->north, 'N');
    return (0);
}