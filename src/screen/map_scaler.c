/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_scaler.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptopping <ptopping@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 19:54:49 by ptopping          #+#    #+#             */
/*   Updated: 2022/10/16 20:09:09 by ptopping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    map_scaler(t_minimap *minimap, int *move_key)
{	
    if (*move_key == MAP_MINUS)
        minimap->minimap_scale -= 0.2;
    else if (*move_key == MAP_PLUS)
        minimap->minimap_scale += 0.2;
    *move_key = -1;
}