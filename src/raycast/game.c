/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptopping <ptopping@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 16:33:15 by ptopping          #+#    #+#             */
/*   Updated: 2022/09/25 14:18:21 by ptopping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int game(t_data *data, t_parser *parser)
{
    t_raycast *raycast;
    if (!(raycast = (t_raycast *)malloc(sizeof(t_raycast))))
        ft_error("fatal error: malloc\n");
    if (!(data->image = (t_image *)malloc(sizeof(t_image))))
        ft_error("fatal error: malloc\n");
    if (!(data->draw_limits = (t_draw_limits *)malloc(sizeof(t_draw_limits))))
        ft_error("fatal error: malloc\n");
    if (!(data->player = (t_player *)malloc(sizeof(t_player))))
        ft_error("fatal error: malloc\n");
    int x = parser->player.x;
    int y = parser->player.y;
    x = data->player.x;
    y = data->player.y;
    data->mlx = NULL;
	data->win = NULL;
    image_init(data->image);   
    data->mlx = mlx_init();//указатель который дальше запихивается в разные функции
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "Cub3D");
    draw_limits_init(data->draw_limits);
    raycast_init(raycast);
    create_image(data, raycast);
    mlx_loop(data->mlx);
    return (0);
}