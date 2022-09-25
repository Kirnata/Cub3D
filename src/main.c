/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptopping <ptopping@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 15:56:36 by ptopping          #+#    #+#             */
/*   Updated: 2022/09/24 17:47:30 by ptopping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

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

int	main(int ac, char **av)
{
	char		**cub_file;
	t_parser	parser;
	t_data		*data;

	cub_file = NULL;
	if (ac < 2)
		ft_error("so stupid!!no cub file\n");
	else if (ac == 2 && is_cubfile(av[1]))
		cub_file = get_file(av[1]);
	data = (t_data *)malloc(sizeof(data));
	if (!data)
		exit(0);
	data->map = parsing(cub_file, &parser);
	game(data, &parser);
	free_parser(data->map, parser, data, cub_file);
	return (0);
}
