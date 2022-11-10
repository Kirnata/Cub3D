/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptopping <ptopping@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 20:22:32 by bpono             #+#    #+#             */
/*   Updated: 2022/10/18 19:31:59 by ptopping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	dda(t_data *data)
{
	int	hit;

	hit = 0;
	while (hit == 0)
	{
		if (data->raycast->side_dist.x < data->raycast->side_dist.y)
		{
			data->raycast->side_dist.x += data->raycast->delta_dist.x;
			data->raycast->map_x += data->raycast->step_x;
			data->raycast->side = 0;
		}
		else
		{
			data->raycast->side_dist.y += data->raycast->delta_dist.y;
			data->raycast->map_y += data->raycast->step_y;
			data->raycast->side = 1;
		}
		if (data->map[data->raycast->map_x][data->raycast->map_y] == '1')
			hit = 1;
	}
	perp_culc(data->raycast);
}

void	perp_culc(t_raycast *raycast)
{
	if (raycast->side == 0)
	{
		if (raycast->side_dist.x == raycast->delta_dist.x)
			raycast->perp_walldst = 0.9;
		else
			raycast->perp_walldst = raycast->side_dist.x
				- raycast->delta_dist.x + 0.05;
	}
	else
	{
		if (raycast->side_dist.y == raycast->delta_dist.y)
			raycast->perp_walldst = 0.9;
		else
			raycast->perp_walldst = raycast->side_dist.y
				- raycast->delta_dist.y + 0.05;
	}
}
