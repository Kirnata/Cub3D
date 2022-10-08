/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_textures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptopping <ptopping@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 19:36:30 by ptopping          #+#    #+#             */
/*   Updated: 2022/10/08 18:00:28 by ptopping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void open_txt(void *mlx, t_image *txt, char *direction)
{

    int fd;
    
    fd = open(direction, O_RDONLY);
    if (fd == -1)
        ft_error("open error");
    close(fd); 
    txt->img_height = TEXHEIGHT;
    txt->img_weight = TEXWIDTH;
    printf("%s->dir\n", direction);
    //exit(0);
    txt->img = mlx_xpm_file_to_image(mlx, direction, &txt->img_height, &txt->img_weight);
    txt->addr = mlx_get_data_addr(txt->img, &txt->bits_per_pixel,
        &txt->line_length, &txt->endian);
}

void txt_loader(t_textures *txts, void *mlx, t_parser *xpms_path)
{
    open_txt(mlx, txts->txt_east, xpms_path->east);
    open_txt(mlx, txts->txt_west, xpms_path->west);
    open_txt(mlx, txts->txt_north, xpms_path->north);
    open_txt(mlx, txts->txt_south, xpms_path->south);
}

int txt_init(t_data *data)
{
    if (!(data->txts = (t_textures *)malloc(sizeof(t_textures))))
        exit(0);
    data->txts->txt_east = (t_image *)malloc(sizeof(t_image));
    data->txts->txt_west = (t_image *)malloc(sizeof(t_image));
    data->txts->txt_north = (t_image *)malloc(sizeof(t_image));
    data->txts->txt_south = (t_image *)malloc(sizeof(t_image));
    if (!data->txts->txt_east || !data->txts->txt_west || !data->txts->txt_north || !data->txts->txt_south)
        ft_error("malloc_error");
    txt_loader(data->txts, data->mlx, data->xpms_path);
    return (0);
}
