/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptopping <ptopping@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 20:46:16 by ptopping          #+#    #+#             */
/*   Updated: 2022/09/15 20:59:51 by ptopping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int start_game(t_data *data)
{
    if (!(data->game = (t_game *)malloc(sizeof(t_game))))
        ft_error("fatal error: malloc\n");
    if (!(data->image = (t_img *)malloc(sizeof(t_image))))
        ft_error("fatal error: malloc\n");
	
}