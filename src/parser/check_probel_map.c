/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_probel_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpono <bpono@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 20:10:47 by bpono             #+#    #+#             */
/*   Updated: 2022/08/15 20:43:22 by bpono            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_right(char **s, int i, int j )
{
	if (s[i][j] == '\n' || s[i][j] == ' ' || s[i][j] == '1')
		return (0);
	else
		return (1);
}

int	check_left(char **s, int i, int j )
{
	if (j == -1)
		return (0);
	if (s[i][j] == ' ' || s[i][j] == '1')
		return (0);
	return (1);
}

int	check_top(char **s, int i, int j )
{
	if (i == -1 || i - 1 == -1)
		return (0);
	if ((ft_strlen(s[i + 1]) > ft_strlen(s[i])) && \
	!check_left(s, i + 1, j - 1) && !check_right(s, i + 1, j + 1))
		return (0);
	if (s[i][j] == ' ' || s[i][j] == '1')
		return (0);
	return (1);
}

int	check_down(char **s, int i, int j, int len )
{
	if (i == len)
		return (0);
	if ((ft_strlen(s[i - 1]) > ft_strlen(s[i])) && \
	!check_left(s, i - 1, j - 1) && !check_right(s, i - 1, j + 1))
		return (0);
	if (s[i][j] == ' ' || s[i][j] == '1')
		return (0);
	else
		return (1);
}

int	check_probel(char **s, int len)
{
	int	i;
	int	j;
	int	res;

	i = 0;
	j = 0;
	res = 0;
	while (i < len)
	{
		j = 0;
		while (s[i][j] != '\0')
		{
			if (s[i][j] == ' ')
				res = check_top(s, i - 1, j) + check_down(s, i + 1, j, len) \
					+ check_right(s, i, j + 1) + check_left(s, i, j - 1);
			j++;
		}
		i++;
	}
	return (res);
}
