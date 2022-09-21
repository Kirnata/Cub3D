/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptopping <ptopping@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 15:56:36 by ptopping          #+#    #+#             */
/*   Updated: 2022/09/21 18:59:24 by ptopping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"
// void free_parser(char **new_map)
// {
	
// }

int	main(int ac, char **av)
{
	char		**cub_file;
	t_parser	parser;
	t_data		*data;
	int			i;

	cub_file = NULL;
	i = 0;
	if (ac < 2)
		ft_error("so stupid!!no cub file\n");
	else if (ac == 2 && is_cubfile(av[1]))
		cub_file = get_file(av[1]);
	if (!(data = (t_data *)malloc(sizeof(data))))
		exit(0);	
	data->map = parsing(cub_file, &parser);
	printf("%c\n", parser.player.name);
	start_game(data);
	printf("hui");
	if (data->map)
	{
		i = 0;
		while (data->map[i])
		{
			free(data->map[i]);
			i++;
		}
		free (data->map);
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
	return (0);
}
