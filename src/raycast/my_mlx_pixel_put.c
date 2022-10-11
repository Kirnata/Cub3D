/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_mlx_pixel_put.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptopping <ptopping@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 21:44:17 by ptopping          #+#    #+#             */
/*   Updated: 2022/10/11 20:53:53 by ptopping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "types.h"
#include "libft.h"

int	get_pixel_color(t_image *txt, int x, int y)
{
	int	color;

	if (txt == NULL)
	{
		color = 61242140;
		printf("LOL %p\n", txt);
		return (color);
	}
	color = *(unsigned int *)(txt->addr + (y * txt->line_length + x * (txt->bits_per_pixel / 8)));
	// printf("color -> %d\n", color);
	return (color);
}

void	my_mlx_pixel_put(t_image *image, int x, int y, int color)
{
	char	*dst;

	dst = image->addr + (y * image->line_length + x * (image->bits_per_pixel / 8));
	*(unsigned int *)dst = color;

}