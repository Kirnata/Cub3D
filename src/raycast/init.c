/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptopping <ptopping@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 16:28:09 by ptopping          #+#    #+#             */
/*   Updated: 2022/09/24 17:33:22 by ptopping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int image_init(t_image *image)
{
    image->addr = NULL;
    image->img = NULL;
    image->bits_per_pixel = 0;
    image->endian = 0;
    image->line_length = 0;
}

int draw_limits_init(t_draw_limits *draw_limits)
{
    draw_limits->lineHeight = 0;
    draw_limits->drawStart = 0;
    draw_limits->drawEnd = 0;
}

int raycast_init(t_raycast *raycast)
{
    data->game->dir.x = -1;//initial direction vector
    data->game->dir.y = 0;
    data->game->plane.x = 0;//the 2d raycaster version of camera plane
    data->game->plane.y = 0.66;
    data->game->camera.x = 0;
    data->game->camera.y = 0;
    data->game->rayDir.x = 0;
    data->game->deltaDist.x = 0;
    data->game->deltaDist.y = 0;
    data->game->mapX = data->game->pos.x;
    data->game->mapY = data->game->pos.x;
    data->game->sideDist.x = 0;
    data->game->sideDist.y = 0;
    data->game->perpWallDist = 0;
    data->game->stepX = 0;
    data->game->stepY = 0;
    data->game->side = 0;
    data->game->wall_x = 0;
    data->game->step = 0;
}

