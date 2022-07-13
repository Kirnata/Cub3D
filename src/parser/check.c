/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpono <bpono@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 19:47:18 by bpono             #+#    #+#             */
/*   Updated: 2022/07/13 19:54:01 by bpono            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/main.h"

int		is_cubfile(char *file)
{
	int i;

	i = ft_strlen(file) - 1;
	if (file[i--] != 'b')
		return (0);
	if (file[i--] != 'u')
		return (0);
	if (file[i--] != 'c')
		return (0);
	if (file[i] != '.')
		return (0);
	return (1);
}