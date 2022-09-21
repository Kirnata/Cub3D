/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptopping <ptopping@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 20:13:31 by bpono             #+#    #+#             */
/*   Updated: 2022/09/21 17:13:05 by ptopping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// 3 из 5 
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
	int	s;

	i = 0;
	s = 0;
	while (new_map[len][i])
	{
		if (new_map[len][i] == '1' || new_map[len][i] == ' ' \
		|| new_map[len][i] == '\n')
			i++;
		else
			return (1);
	}
	printf("s->%d\n", s);
	return (0);
}
