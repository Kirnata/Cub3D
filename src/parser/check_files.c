/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_files.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptopping <ptopping@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 19:47:18 by bpono             #+#    #+#             */
/*   Updated: 2022/10/15 15:29:33 by ptopping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_xpmfile(char *file)
{
	int	i;

	i = ft_strlen(file) - 1;
	if (file[i--] != 'm')
		return (ft_error(ERR_XPM));
	if (file[i--] != 'p')
		return (ft_error(ERR_XPM));
	if (file[i--] != 'x')
		return (ft_error(ERR_XPM));
	if (file[i] != '.')
		return (ft_error(ERR_XPM));
	return (1);
}

int	is_cubfile(char *file)
{
	int	i;

	i = ft_strlen(file) - 1;
	if (file[i--] != 'b')
		return (ft_error(ERR_CUB));
	if (file[i--] != 'u')
		return (ft_error(ERR_CUB));
	if (file[i--] != 'c')
		return (ft_error(ERR_CUB));
	if (file[i] != '.')
		return (ft_error(ERR_CUB));
	return (1);
}
