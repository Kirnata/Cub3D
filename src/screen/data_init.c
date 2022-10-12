/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptopping <ptopping@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 16:28:09 by ptopping          #+#    #+#             */
/*   Updated: 2022/10/12 22:00:30 by ptopping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	image_init(t_image *image)
{
	image->addr = NULL;
	image->img = NULL;
	image->bits_per_pixel = 0;
	image->endian = 0;
	image->line_length = 0;
	image->img_height = 0;
	image->img_weight = 0;
}

void	draw_limits_init(t_draw_limits *draw_limits)
{
	draw_limits->lineHeight = 0;
	draw_limits->drawStart = 0;
	draw_limits->drawEnd = 0;
}

void	raycast_init(t_raycast *raycast)
{
	raycast->plane.x = -raycast->dir.y * 0.66;//the 2d raycaster version of camera plane
	raycast->plane.y = -raycast->dir.x * 0.66;
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
	raycast->step = 0;
	raycast->wallX = 0;
	raycast->texX = 0;
	raycast->texY = 0;
	raycast->texPos = 0;
}

void	init_direction(t_point *dir, char name)
{
	if (name == 'W')
	{
		dir->x = -1;
		dir->y = 0;
	}
	else if (name == 'E')
	{
		dir->x = 1;
		dir->y = 0;
	}
	if (name == 'N')
	{
		dir->x = 0;
		dir->y = -1;
	}
	if (name == 'S')
	{
		dir->x = 0;
		dir->y = 1;
	}		
}

void	minimap_init(t_minimap *minimap)
{
	minimap->minimap_x = 0;
	minimap->minimap_y = 0;
	minimap->colour = 0x0066CCFF;
	calc_map_scale(&(minimap->minimap_scale));
}

void	data_init(t_data *data)
{
	if (!(data->raycast = (t_raycast *)malloc(sizeof(t_raycast))))
		ft_error("fatal error: malloc\n");
	if (!(data->image = (t_image *)malloc(sizeof(t_image))))
		ft_error("fatal error: malloc\n"); 
	if (!(data->draw_limits = (t_draw_limits *)malloc(sizeof(t_draw_limits))))
		ft_error("fatal error: malloc\n");
	if (!(data->minimap = (t_minimap *)malloc(sizeof(t_minimap))))
		ft_error("fatal error: malloc\n");
	if (!(data->txts = (t_textures *)malloc(sizeof(t_textures))))
		ft_error("fatal error: malloc\n");
	data->mlx = NULL;
	data->win = NULL;
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "Cub3D");
	init_direction(&(data->raycast->dir), data->player->name);
	raycast_init(data->raycast);
	image_init(data->image);
	draw_limits_init(data->draw_limits);
	minimap_init(data->minimap);
	txt_init(data);
}
