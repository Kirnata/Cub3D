/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpono <bpono@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 14:28:41 by bpono             #+#    #+#             */
/*   Updated: 2022/09/22 16:50:59 by bpono            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//вернет NULL в случае пиздеца 
char	**parsing(char **map, t_parser *parser)
{
	char	**new_map;
	int		l;

	l = check_textures(map, parser);
	l = check_colours(map, parser);
	if (l == 1)
		ft_error("colours problems\n");
	new_map = check_map(map, parser);
	if (!new_map)
		ft_error("map problems\n");
	return (new_map);
}

char	**make_map(t_list *head, int size)
{
	char	**map;
	int		i;

	map = (char **)malloc(sizeof(char *) * (size + 1));
	if (!map)
		ft_error("malloc problems");
	i = -1;
	while (head != NULL)
	{
		map[++i] = head->content;
		head = head->next;
	}
	return (map);
}

char	**get_file(char *map_name)
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
		ft_putstr_fd("problems with file stupid dick\n", 2);
		exit(1);
	}
	line = get_next_line(fd);
	while (line)
	{
		ft_lstadd_back(&head, ft_lstnew(line));
		line = get_next_line(fd);
	}
	map = make_map(head, ft_lstsize(head));
	ft_lstclear(&head, NULL);
	return (map);
}
