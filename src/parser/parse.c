/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptopping <ptopping@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 14:28:41 by bpono             #+#    #+#             */
/*   Updated: 2022/07/19 12:47:48 by ptopping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

// int map_size(int f1)
// {
// 	int		i;
// 	char	*str;

// 	i = 0;
// 	str = get_next_line(f1);
// 	while (str)
// 	{
// 		i++;
// 		free(str);
// 		str = get_next_line(f1);
// 	}
// 	return (i);
// }
// void free_map(char **map)
// {
// 	int i;

// 	i = 0;
// 	while(map[i])
// 	{
// 		free(map[i]);
// 		i++;
// 	}
// 	free(map);
// }
// int parsing(int c, char *file_name)
// {
// 	int f1;
// 	char **map;
// 	int i;
// 	int k;
// 	char *new;
	
// 	f1 = open(file_name, 0);
// 	if (f1 < 0)
// 		return (0);
// 	i = map_size(f1);
// 	map =(char **)malloc(sizeof(char *) * (i + 1));
// 	close(f1);
// 	f1 = open(file_name, 0);
// 	if (f1 < 0)
// 		return (0);
// 	k = 0;
// 	new = NULL;
// 	while(k < i)
// 	{
// 		new = get_next_line(f1);
// 		map[k] = ft_new_strdup(new);
// 		free(new);
// 		k++;
// 	}
// 	map[k] = NULL;
// 	k = 0;
// 	while (map[k])
// 	{
// 		printf("%s",map[k]);
// 		k++;
// 	}
// 	free_map(map);
// 	return (0);
// }
