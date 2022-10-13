/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpono <bpono@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 19:56:09 by bpono             #+#    #+#             */
/*   Updated: 2022/10/13 20:34:57 by bpono            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_w(t_data *data)
{
	if (data->map[(int)(data->player->x + data->raycast->dir.x \
		* MOVE_SPEED)][(int)(data->player->y)] == '0')
		data->player->x += data->raycast->dir.x * MOVE_SPEED;
	if (data->map[(int)(data->player->x)][(int)(data->player->y
		+ data->raycast->dir.y * MOVE_SPEED)] == '0')
		data->player->y += data->raycast->dir.y * MOVE_SPEED;
}

void	move_s(t_data *data)
{
	if (data->map[(int)(data->player->x - data->raycast->dir.x \
		* MOVE_SPEED)][(int)(data->player->y)] == '0')
		data->player->x -= data->raycast->dir.x * MOVE_SPEED;
	if (data->map[(int)(data->player->x)][(int)(data->player->y
		- data->raycast->dir.y * MOVE_SPEED)] == '0')
		data->player->y -= data->raycast->dir.y * MOVE_SPEED;
}

void	move_a(t_data *data)
{
	if (data->map[(int)(data->player->x - data->raycast->plane.x \
		* MOVE_SPEED)][(int)(data->player->y)] == '0')
		data->player->x -= data->raycast->plane.x * MOVE_SPEED;
	if (data->map[(int)(data->player->x)][(int)(data->player->y
		- data->raycast->plane.y * MOVE_SPEED)] == '0')
		data->player->y -= data->raycast->plane.y * MOVE_SPEED;
}

void	move_d(t_data *data)
{
	if (data->map[(int)(data->player->x + data->raycast->plane.x \
		* MOVE_SPEED)][(int)(data->player->y)] == '0')
		data->player->x += data->raycast->plane.x * MOVE_SPEED;
	if (data->map[(int)(data->player->x)][(int)(data->player->y
		+ data->raycast->plane.y * MOVE_SPEED)] == '0')
		data->player->y += data->raycast->plane.y * MOVE_SPEED;
}

void	check_move(t_data *data)
{
	if (data->player->move_key == KEY_W)
		move_w(data);
	else if (data->player->move_key == KEY_S)
		move_s(data);
	else if (data->player->move_key == KEY_A)
		move_a(data);
	else if (data->player->move_key == KEY_D)
		move_d(data);
	create_image(data);
}
