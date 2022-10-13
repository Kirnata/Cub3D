/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpono <bpono@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 18:00:23 by bpono             #+#    #+#             */
/*   Updated: 2022/10/13 15:19:39 by bpono            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_open_textures(t_parser *parser)
{
	int	f1;
	int	f2;
	int	f3;
	int	f4;

	f1 = open(parser->north, O_RDONLY);
	f2 = open(parser->south, O_RDONLY);
	f3 = open(parser->west, O_RDONLY);
	f4 = open(parser->east, O_RDONLY);
	if (f1 < 0 || f2 < 0 || f3 < 0 || f4 < 0)
		return (1);
	if (is_xpmfile(parser->north) || is_xpmfile(parser->north) \
	|| is_xpmfile(parser->north) || is_xpmfile(parser->north))
		return (0);
	return (1);
}

char	*give_line(int j, char **map, int i, int num_pr)
{
	int		j1;
	int		j2;
	char	*line;

	j = j + 2;
	while (map[i][j] == ' ')
	{
		j++;
		num_pr++;
	}
	j1 = j;
	while (map[i][j] != '\n')
			j++;
	j2 = j;
	line = ft_substr(map[i], j1, j2 - j1);
	if (!line)
		return (NULL);
	return (line);
}

char	*give_texture_value(char s1, char s2, char **map)
{
	int	i;
	int	j;
	int	num_pr;

	i = 0;
	num_pr = 0;
	while (map[i])
	{
		j = 0;
		num_pr = 0;
		while (map[i][j])
		{
			while (map[i][j] == ' ')
			{
				j++;
				num_pr++;
			}
			if (map[i][j] == s1 && map[i][j + 1] == s2)
				return (give_line(j, map, i, num_pr));
			j++;
		}
		i++;
	}
	return (NULL);
}

int	save_textures(char **map, t_parser *parser)
{
	parser->north = give_texture_value('N', 'O', map);
	parser->south = give_texture_value('S', 'O', map);
	parser->west = give_texture_value('W', 'E', map);
	parser->east = give_texture_value('E', 'A', map);
	if (parser->north == NULL || parser->south == NULL \
	|| parser->west == NULL || parser->east == NULL)
		return (1);
	return (0);
}
