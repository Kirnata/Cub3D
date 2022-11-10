/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptopping <ptopping@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 15:56:36 by ptopping          #+#    #+#             */
/*   Updated: 2022/10/18 19:46:12 by ptopping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	create_data(t_data **data)
{
	*data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		ft_error(ERR_MALLOC);
	((*data)->player) = (t_player *)malloc(sizeof(t_player));
	if (!(*data)->player)
		ft_error(ERR_MALLOC);
}

int	main(int ac, char **av)
{
	char		**cub_file;
	t_parser	parser;
	t_data		*data;

	cub_file = NULL;
	if (ac < 2)
		ft_error(ERR_FEW_ARGS);
	else if (ac == 2 && is_cubfile(av[1]))
		cub_file = get_file(av[1]);
	create_data(&data);
	data->map = parsing(cub_file, &parser, data);
	data->xpms_path = &parser;
	game(data);
	cleaner(data, data->map, parser, cub_file);
	return (0);
}
