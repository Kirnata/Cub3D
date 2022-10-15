/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptopping <ptopping@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 17:32:29 by bpono             #+#    #+#             */
/*   Updated: 2022/10/15 15:41:06 by ptopping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_num_of_textures(char **map, int k, char s1, char s2)
{
	int	i;
	int	j;
	int	sum;

	i = 0;
	sum = 0;
	while (i < k)
	{
		j = 0;
		while (map[i][j])
		{
			while (map[i][j] == ' ')
				j++;
			if (map[i][j] == s1 && map[i][j + 1] == s2)
				sum++;
			j++;
		}
		i++;
	}
	return (sum);
}

int	check_only_4textures(char **map, int k)
{
	if (check_num_of_textures(map, k, 'N', 'O') != 1)
		return (1);
	if (check_num_of_textures(map, k, 'S', 'O') != 1)
		return (1);
	if (check_num_of_textures(map, k, 'W', 'E') != 1)
		return (1);
	if (check_num_of_textures(map, k, 'E', 'A') != 1)
		return (1);
	return (0);
}

int	check_textures(char **map, t_parser *parser)
{
	int	m;
	int	len;

	len = ft_get_len(0, map);
	m = check_only_4textures(map, len);
	if (m == 1)
		ft_error(ERR_TXT);
	m = save_textures(map, parser);
	if (m == 1)
		ft_error(ERR_TXT);
	m = check_open_textures(parser);
	if (m == 1)
		ft_error(ERR_TXT);
	return (m);
}
