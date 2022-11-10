/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaners.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptopping <ptopping@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 21:34:26 by ptopping          #+#    #+#             */
/*   Updated: 2022/10/18 19:43:38 by ptopping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	exit_cleaner(t_data *data)
{
	free(data->image);
	free(data->player);
	free(data->draw_limits);
	free(data->raycast);
	free(data->minimap);
	free(data->txts->txt_east);
	free(data->txts->txt_west);
	free(data->txts->txt_north);
	free(data->txts->txt_south);
	free(data->txts);
	exit(0);
	return (0);
}

void	cleaner(t_data *data, char **map, t_parser parser, char **cub_file)
{
	int	i;

	if (map)
	{
		i = 0;
		while (map[i])
		{
			free(map[i]);
			i++;
		}
		free (map);
	}
	free(parser.north);
	free(parser.south);
	free(parser.west);
	free(parser.east);
	i = 0;
	while (cub_file[i])
	{
		free(cub_file[i]);
		i++;
	}
	free (cub_file);
	exit_cleaner(data);
}
