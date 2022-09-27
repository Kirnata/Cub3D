/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpono <bpono@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 16:28:09 by ptopping          #+#    #+#             */
/*   Updated: 2022/09/25 16:10:22 by bpono            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void image_init(t_image *image)
{
    image->addr = NULL;
    image->img = NULL;
    image->bits_per_pixel = 0;
    image->endian = 0;
    image->line_length = 0;
}

void draw_limits_init(t_draw_limits *draw_limits)
{
    draw_limits->lineHeight = 0;
    draw_limits->drawStart = 0;
    draw_limits->drawEnd = 0;
}

void raycast_init(t_raycast *raycast)
{
    raycast->dir.x = -1;//initial direction vector
    raycast->dir.y = 0;
    raycast->plane.x = 0;//the 2d raycaster version of camera plane
    raycast->plane.y = 0.66;
    raycast->camera.x = 0;
    raycast->camera.y = 0;
    raycast->rayDir.x = 0;
    raycast->deltaDist.x = 0;
    raycast->deltaDist.y = 0;
    raycast->mapX = 0;
    raycast->mapY = 0;
    raycast->sideDist.x = 0;
    raycast->sideDist.y = 0;
    raycast->perpWallDist = 0;
    raycast->stepX = 0;
    raycast->stepY = 0;
    raycast->side = 0;
    raycast->wall_x = 0;
    raycast->step = 0;
}
