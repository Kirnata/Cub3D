/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpono <bpono@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 19:47:18 by bpono             #+#    #+#             */
/*   Updated: 2022/08/16 16:56:34 by bpono            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_xpmfile(char *file)
{
	int	i;

	i = ft_strlen(file) - 1;
	if (file[i--] != 'm')
		return (ft_error("not xpm file!!\n"));
	if (file[i--] != 'p')
		return (ft_error("not xpm file!!\n"));
	if (file[i--] != 'x')
		return (ft_error("not xpm file!!\n"));
	if (file[i] != '.')
		return (ft_error("not xpm file!!\n"));
	return (1);
}

int	is_cubfile(char *file)
{
	int	i;

	i = ft_strlen(file) - 1;
	if (file[i--] != 'b')
		return (ft_error("not cub file!!\n"));
	if (file[i--] != 'u')
		return (ft_error("not cub file!!\n"));
	if (file[i--] != 'c')
		return (ft_error("not cub file!!\n"));
	if (file[i] != '.')
		return (ft_error("not cub file!!\n"));
	return (1);
}
