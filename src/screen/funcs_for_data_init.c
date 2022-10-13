/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funcs_for_data_init.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpono <bpono@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 16:28:09 by ptopping          #+#    #+#             */
/*   Updated: 2022/10/13 20:53:19 by bpono            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	image_init(t_image *image)
{
	image->addr = NULL;
	image->img = NULL;
	image->bpp = 0;
	image->endian = 0;
	image->line_length = 0;
	image->img_height = 0;
	image->img_weight = 0;
}

void	draw_limits_init(t_draw_limits *draw_limits)
{
	draw_limits->line_height = 0;
	draw_limits->draw_start = 0;
	draw_limits->draw_end = 0;
}

void	raycast_init(t_raycast *raycast)
{
	raycast->plane.x = -raycast->dir.y * 0.66;
	raycast->plane.y = -raycast->dir.x * 0.66;
	raycast->camera.x = 0;
	raycast->camera.y = 0;
	raycast->ray_dir.x = 0;
	raycast->delta_dist.x = 0;
	raycast->delta_dist.y = 0;
	raycast->map_x = 0;
	raycast->map_y = 0;
	raycast->side_dist.x = 0;
	raycast->side_dist.y = 0;
	raycast->perp_walldst = 0;
	raycast->step_x = 0;
	raycast->step_y = 0;
	raycast->side = 0;
	raycast->step = 0;
	raycast->wall_x = 0;
	raycast->tex_x = 0;
	raycast->tex_y = 0;
	raycast->tex_pos = 0;
}

void	init_direction(t_point *dir, char name)
{
	if (name == 'N')
	{
		dir->x = -1;
		dir->y = 0;
	}
	else if (name == 'S')
	{
		dir->x = 1;
		dir->y = 0;
	}
	if (name == 'W')
	{
		dir->x = 0;
		dir->y = -1;
	}
	if (name == 'E')
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
