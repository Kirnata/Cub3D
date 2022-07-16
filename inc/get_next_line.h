/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptopping <ptopping@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 00:17:19 by ptopping          #+#    #+#             */
/*   Updated: 2022/07/14 16:53:29 by ptopping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

char	*ft_strjoin_gnl(char *s1, char *s2);
// char	*ft_strdup(char *str);
char	*ft_record(char *stat_line);
char	*ft_cut_off(char *stat_line);
// int		ft_strlen(char *str);
char	*get_next_line(int fd);
int		ft_find_endl(char *tmp);
char	*ft_dop_strjoin(char *s1, char *s2, char *s3);
int		reading(char **stat_line, int fd);
char	*func_while_join_gnl(char *s1, char *s2, char *s3);

#endif