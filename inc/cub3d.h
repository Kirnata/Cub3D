/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpono <bpono@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 20:53:40 by bpono             #+#    #+#             */
/*   Updated: 2022/09/15 17:07:53 by bpono            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <ctype.h>
// # include "mlx.h"
# include <math.h>
# include "get_next_line.h"
# include "../libft/libft.h"
//open
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# define WIDTH 1920
# define HEIGHT 1080
# define MAP_INSIDE "0NSEW"

typedef struct s_parser
{
	char	*north;
	char	*south;
	char	*west;
	char	*east;
	int		floor;
	int		ceilling;
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
char	**parsing(char **map, t_parser *parser);
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
char	**check_map(char **content);
int		check_probel(char **s, int len);
int		check_last(char **new_map, int len);
int		ft_get_len(int start, char **list);
int		get_start_index(char **s);

#endif
