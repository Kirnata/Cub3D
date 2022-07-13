/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpono <bpono@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 14:08:39 by bpono             #+#    #+#             */
/*   Updated: 2022/07/12 20:39:03 by bpono            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/main.h"
int main(int argc, char **argv)
{
	if (argc < 2)
		printf("so stupid!!p2p\n");
	else if (argc == 2)
	{
		if (!is_cubfile(argv[1]))
			return (ft_error("not cub file ahahahaha\n"));
		// cub3d(argv[1]);
	}
	// parsing(argc, argv[1]);
}