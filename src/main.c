/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptopping <ptopping@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 15:56:36 by ptopping          #+#    #+#             */
/*   Updated: 2022/10/11 20:43:43 by ptopping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//close если не смогли открыть
//чекнуть направления
//миникарта

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
	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		exit(0);
	data->player = (t_player *)malloc(sizeof(t_player));
	if (!data->player)
		exit(0);
	data->map = parsing(cub_file, &parser, data);
	data->xpms_path = &parser;
	game(data);
	//free_parser(data->map, parser, data, cub_file);вот это засунуть в общий exit_cleaner
	return (0);
}
