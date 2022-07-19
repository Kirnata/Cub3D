/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptopping <ptopping@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 15:56:36 by ptopping          #+#    #+#             */
/*   Updated: 2022/07/19 16:12:25 by ptopping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

char	**make_map(t_list **head,int size)
{
	char **map;
	int		i;
	
	map = (char **)malloc(sizeof(char *) * (size + 1));
	i = -1;
	t_list *tmp = *head;
	while (tmp)
	{
		map[++i] = tmp->content;
		tmp = tmp->next;
	}
	// i = -1;
	// while (map[++i])
	// 	ft_putstr_fd(map[i],1);
	return(map);
}
char	**cub3d(char *map_name)
{
	int			fd;
	char		*line;
	t_list		*head;
	char		**map;

	head = NULL;
	line = NULL;
	fd = open(map_name, O_RDONLY);
	if (fd <= 0)
		{
			ft_putstr_fd("problems with file stupid dick\n",2);
			exit(1);
		}
	line = get_next_line(fd);
	while (line)
	{
		ft_lstadd_back(&head,ft_lstnew(line));
		line = get_next_line(fd);
	}
	ft_lstadd_back(&head,ft_lstnew(line));
	map = make_map(&head,ft_lstsize(head));
	return (map);
}
int count_lines_textures(char **map)
{
	int i;

	i = 0;
	while (map[i] && !ft_isdigit(map[i][0]))
		i++;
	return(i);
}
int count_lines_map(char **map)
{
	int i;
	int k;

	i = 0;
	k = 0;
	while (map[i])
	{
		if (ft_isdigit(map[i][0]))
			k++;
		i++;
	}
	return(k);
}
// char *give_texture_value(char *s,char **map,int k)
// {
	
// }
// void parsing(char **map)
// {
// 	int k = count_lines_textures(map);
// 	char *s = give_texture_value("NO",map,k);
// 	printf("%d\n",k);
// }
char **parsing_map(char **map)
{
	int num_lines;
	char **new_map;
	int k;
	int i;

	num_lines = count_lines_map(map);
	k = 0;
	i = 0;
	new_map = (char **)malloc(sizeof(char *) * (num_lines + 1));
	while (map[k])
		k++;
	num_lines = k - num_lines;
	// printf("%d\n",num_lines);
	while (num_lines < k )
	{
		new_map[i] = ft_strdup(map[num_lines]);
		i++;
		num_lines++;
	}
	// printf("%d\n",num_lines);
	return(new_map);
}
int main(int ac, char **av)
{
	char **cub_file;
	t_data *data;
	//int i = 0;

	cub_file = NULL;
	if (ac < 2)
		ft_error("so stupid!!no cub file\n");
	else if (ac == 2 && is_cubfile(av[1]))
		cub_file = cub3d(av[1]);
	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		ft_error("malloc error");
	data->map = calloc(1, sizeof(char *));
	data->map = parsing_map(cub_file);
	// int i = 0;
	// while (data->map[0][i])
	// {
	// 	printf("%c",data->map[0][i]);
	// 	i++;
	// }
	// exit(0);
	create_game(data);
	//mlx_hook(data->win, ON_DESTROY, 1L << 13, key_press, data);
	mlx_hook(data->win, ON_DESTROY, 1L << 13, destroy, data);
	mlx_loop(data->mlx);
}