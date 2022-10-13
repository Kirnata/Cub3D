/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpono <bpono@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 19:28:16 by bpono             #+#    #+#             */
/*   Updated: 2022/10/13 15:24:11 by bpono            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	**get_map(int start, char **list)
{
	int		len;
	int		i;
	char	**new_map;

	len = ft_get_len(start, list);
	i = 0;
	new_map = (char **)malloc(sizeof(char *) * (len + 1));
	if (!new_map)
		ft_error("malloc problems\n");
	while (list[start])
	{
		new_map[i] = ft_strdup(list[start]);
		if (!new_map[i])
			ft_error("malloc problems\n");
		start++;
		i++;
	}
	new_map[i] = NULL;
	return (new_map);
}

int	check_symbols(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != ' ' && map[i][j] != '1'\
			&& map[i][j] != '0' && map[i][j] != 'N'\
			&& map[i][j] != 'S' && map[i][j] != 'W'\
			&& map[i][j] != 'E' && map[i][j] != '\n')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	double_check(char **s, int i, int j)
{
	if (s[i][j] == '1' && s[i][j + 1] == ' ')
	{
		j++;
		while (s[i][j] == ' ')
			j++;
		if (s[i][j] == '\n')
			return (1);
	}
	if (s[i][j] == '1' && s[i][j + 1] == '\n')
		return (1);
	return (0);
}

int	check_odin(char **s, int k)
{
	t_element	element;
	int			t;

	element.i = 0;
	t = 0;
	while (element.i < k)
	{
		element.j = 0;
		while (s[element.i][element.j] == ' ')
					element.j++;
		if (s[element.i][element.j] == '1')
			element.j++;
		else
		{
			element.i++;
			continue ;
		}
		while (s[element.i][element.j])
		{
			t = t + double_check(s, element.i, element.j);
			element.j++;
		}
		element.i++;
	}
	return (t);
}

char	**check_map(char **content, t_data	*data)
{
	int		start;
	char	**new_map;
	int		len;

	start = get_start_index(content);
	if (start == -1)
		return (NULL);
	new_map = get_map(start, content);
	if (!new_map)
		return (NULL);
	len = ft_get_len(0, new_map);
	if (check_symbols(new_map) == 1 || check_last(new_map, len - 1) == 1 \
	|| check_odin(new_map, len) != len || check_probel(new_map, len) == 1 \
	|| check_player(new_map, data) != 1)
		return (ft_clear(new_map));
	return (new_map);
}
