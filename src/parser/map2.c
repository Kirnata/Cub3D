/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptopping <ptopping@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 20:13:31 by bpono             #+#    #+#             */
/*   Updated: 2022/09/29 17:43:46 by ptopping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	**ft_clear(char **name)
{
	int	i;

	i = 0;
	while (name[i])
	{
		free(name[i]);
		i++;
	}
	free (name);
	return (NULL);
}

int	get_start_index(char **s)
{
	int		i;
	int		j;
	int		len;
	int		k;

	i = 0;
	k = 0;
	len = 1;
	while (s[i])
	{
		j = 0;
		if (len == k && len != 1)
			return (i - 1);
		len = ft_strlen(s[i]);
		k = 0;
		while (s[i][j])
		{
			if (s[i][j] == '1' || s[i][j] == ' ' || s[i][j] == '\n')
				k++;
			j++;
		}
		i++;
	}
	return (-1);
}

int	ft_get_len(int start, char **list)
{
	int	k;

	k = 0;
	while (list[start])
	{
		k++;
		start++;
	}
	return (k);
}

int	check_last(char **new_map, int len)
{
	int	i;

	i = 0;
	while (new_map[len][i])
	{
		if (new_map[len][i] == '1' || new_map[len][i] == ' ' \
		|| new_map[len][i] == '\n')
			i++;
		else
			return (1);
	}
	return (0);
}

int	check_player(char **map, t_data	*data)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'W'\
			|| map[i][j] == 'E')
			{
				data->player->name = map[i][j];
				data->player->x = i;//тут поменяла
				data->player->y = j;
				count++;
			}
			j++;
		}
		i++;
	}
	data->player->move_key = -1;
	return (count);
}
