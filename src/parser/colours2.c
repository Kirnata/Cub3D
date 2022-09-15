/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colours2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpono <bpono@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 18:11:06 by bpono             #+#    #+#             */
/*   Updated: 2022/08/15 20:38:59 by bpono            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// 4 из 5 
int	count_separators(char *line)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (line[i])
	{
		if (line[i] == ',')
			k++;
		i++;
	}
	return (k);
}

int	check_numbers(t_colour *colour)
{
	if (colour->r >= 0 && colour->r <= 255 \
	&& colour->g >= 0 && colour->g <= 255 \
	&& colour->b >= 0 && colour->b <= 255)
		return (0);
	else
		return (1);
}

int	get_hex_color(int r, int g, int b)
{
	int	rgb;

	rgb = (r << 16) + (g << 8) + b;
	return (rgb);
}

void	put_numbers(t_colour *colour, t_parser *parser, char name)
{
	if (name == 'F')
		parser->floor = get_hex_color(colour->r, colour->g, colour->b);
	else
		parser->ceilling = get_hex_color(colour->r, colour->g, colour->b);
}
