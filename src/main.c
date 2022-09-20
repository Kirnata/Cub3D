/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpono <bpono@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 15:56:36 by ptopping          #+#    #+#             */
/*   Updated: 2022/09/20 15:16:41 by bpono            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"
// void free_parser(char **new_map)
// {
	
// }

int	main(int ac, char **av)
{
	char		**cub_file;
	char		**new_map;
	t_parser	parser;
	int			i;

	cub_file = NULL;
	i = 0;
	if (ac < 2)
		ft_error("so stupid!!no cub file\n");
	else if (ac == 2 && is_cubfile(av[1]))
		cub_file = get_file(av[1]);
	new_map = parsing(cub_file, &parser);
	printf("%c\n", parser.player.name);
	if (new_map)
	{
		i = 0;
		while (new_map[i])
		{
			free(new_map[i]);
			i++;
		}
		free (new_map);
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
