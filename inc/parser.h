/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpono <bpono@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 16:11:24 by ptopping          #+#    #+#             */
/*   Updated: 2022/09/25 17:50:15 by bpono            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H
#include "cub3d.h"
#include "types.h"


/*
// typedef struct s_player
// {
// 	char	name;
// 	int		x;
// 	int		y;
// }	t_player;
*/
typedef struct s_parser
{
	char		*north;
	char		*south;
	char		*west;
	char		*east;
	int			floor;
	int			ceilling;
}	t_parser;

typedef struct s_colour
{
	int	r;
	int	g;
	int	b;
}	t_colour;


typedef struct s_dick
{
	int	i;
	int	j;
	int	b;
}	t_dick;

//super+pussy_parser
char	**parsing(char **map, t_parser *parser, t_data *data);
char	**get_file(char *map_name);
char	*ft_new_strdup(char *src);
int		ft_error(char *name);
int		is_cubfile(char *file);
int		is_xpmfile(char *file);
int		check_colours(char **map, t_parser *parser);
int		count_separators(char *line);
int		check_numbers(t_colour *colour);
void	put_numbers(t_colour *colour, t_parser *parser, char name);
int		check_textures(char **map, t_parser *parser);
int		save_textures(char **map, t_parser *parser);
int		check_open_textures(t_parser *parser);
char	**check_map(char **content, t_data *data);
int		check_probel(char **s, int len);
int		check_last(char **new_map, int len);
int		ft_get_len(int start, char **list);
int		get_start_index(char **s);
char	**ft_clear(char **name);
int		check_player(char **map, t_data *data);

#endif