/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptopping <ptopping@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 19:47:18 by bpono             #+#    #+#             */
/*   Updated: 2022/07/16 22:34:51 by ptopping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// int		is_cubfile(char *file)
// {
// 	int i;

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
