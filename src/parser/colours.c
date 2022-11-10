/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colours.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpono <bpono@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 19:18:46 by bpono             #+#    #+#             */
/*   Updated: 2022/10/13 15:21:19 by bpono            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*give_line_colour(char **map, char name)
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
			if (map[i][j] == name)
				return (map[i] + 2 + num_pr);
			j++;
		}
		i++;
	}
	return (NULL);
}

int	num_len(int num)
{
	int	i;
	int	k;

	i = 1;
	k = 0;
	while (num >= 10)
	{
		num = num / 10;
		i++;
		k = num;
	}
	k++;
	return (i);
}

int	get_numbers(char *s, t_colour *colour)
{
	int	len;
	int	i;

	colour->r = ft_atoi(s);
	len = num_len(colour->r);
	i = len + 1;
	while (s[i] && (isspace(s[i]) || s[i] == ','))
		i++;
	if (ft_isdigit(s[i]))
		colour->g = ft_atoi(s + i);
	else
		return (1);
	len = num_len(colour->g);
	i = i + len + 1;
	while (s[i] && (isspace(s[i]) || s[i] == ','))
		i++;
	if (ft_isdigit(s[i]))
		colour->b = ft_atoi(s + i);
	else
		return (1);
	len = num_len(colour->b);
	i = i + len + 1;
	if (s[i] != '\0')
		return (1);
	return (0);
}

int	check_colours(char **map, t_parser *parser)
{
	t_colour	colour;
	char		*floor;
	char		*ceilling;

	floor = give_line_colour(map, 'F');
	ceilling = give_line_colour(map, 'C');
	if (floor == NULL || ceilling == NULL)
		return (1);
	if (count_separators(floor) != 2 || count_separators(ceilling) != 2)
		return (1);
	if (get_numbers(floor, &colour) == 1)
		return (1);
	if (check_numbers(&colour) == 1)
		return (1);
	put_numbers(&colour, parser, 'F');
	if (get_numbers(ceilling, &colour) == 1)
		return (1);
	if (check_numbers(&colour) == 1)
		return (1);
	put_numbers(&colour, parser, 'C');
	return (0);
}
