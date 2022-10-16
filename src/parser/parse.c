/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptopping <ptopping@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 14:28:41 by bpono             #+#    #+#             */
/*   Updated: 2022/10/15 15:37:50 by ptopping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	**parsing(char **map, t_parser *parser, t_data	*data)
{
	char	**new_map;
	int		l;

	l = check_textures(map, parser);
	l = check_colours(map, parser);
	if (l == 1)
		ft_error(ERR_COLOUR);
	new_map = check_map(map, data);
	if (!new_map)
		ft_error(ERR_MAP);
	return (new_map);
}

char	**make_map(t_list *head, int size)
{
	char	**map;
	int		i;

	map = (char **)malloc(sizeof(char *) * (size + 1));
	if (!map)
		ft_error(ERR_MALLOC);
	ft_bzero(map, sizeof(char *) * (size + 1));
	i = 0;
	while (head != NULL)
	{
		map[i++] = head->content;
		head = head->next;
	}
	map[i] = NULL;
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
		ft_putstr_fd("problems with file\n", 2);
		exit(1);
	}
	line = get_next_line(fd);
	while (line)
	{
		ft_lstadd_back(&head, ft_lstnew(line));
		line = get_next_line(fd);
	}
	close(fd);
	map = make_map(head, ft_lstsize(head));
	ft_lstclear(&head, NULL);
	return (map);
}
