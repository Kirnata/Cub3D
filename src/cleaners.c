/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaners.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpono <bpono@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 21:34:26 by ptopping          #+#    #+#             */
/*   Updated: 2022/10/13 15:33:12 by bpono            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_parser(char **map, t_parser parser, t_data *data, char **cub_file)
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
	free(data);
	i = 0;
	while (cub_file[i])
	{
		free(cub_file[i]);
		i++;
	}
	free (cub_file);
}

int	exit_cleaner(t_data *data)
{
	printf("name of player -%c\n", data->player->name);
	printf("NEED A CLEANER\n");
	exit(0);
	return (0);
}
