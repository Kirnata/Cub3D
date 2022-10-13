/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_textures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpono <bpono@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 19:36:30 by ptopping          #+#    #+#             */
/*   Updated: 2022/10/13 20:21:40 by bpono            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	culc_txt(t_raycast *raycast, t_player *player)
{
	if (raycast->side == 0)
		raycast->wall_x = player->y + raycast->perp_walldst
			* raycast->ray_dir.y;
	else
		raycast->wall_x = player->x + raycast->perp_walldst
			* raycast->ray_dir.x;
	raycast->wall_x -= floorf(raycast->wall_x);
	raycast->tex_x = (int)(raycast->wall_x * (double)(TEXWIDTH));
	if (raycast->side == 0 && raycast->ray_dir.x > 0)
		raycast->tex_x = TEXWIDTH - raycast->tex_x - 1;
	if (raycast->side == 1 && raycast->ray_dir.y < 0)
		raycast->tex_x = TEXWIDTH - raycast->tex_x - 1;
}

void	open_txt(void *mlx, t_image *txt, char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		ft_error("open error");
	close(fd);
	txt->img_height = TEXHEIGHT;
	txt->img_weight = TEXWIDTH;
	txt->img = mlx_xpm_file_to_image(mlx, path, &txt->img_height,
			&txt->img_weight);
	txt->addr = mlx_get_data_addr(txt->img, &txt->bpp,
			&txt->line_length, &txt->endian);
}

void	txt_loader(t_textures *txts, void *mlx, t_parser *xpms_path)
{
	open_txt(mlx, txts->txt_east, xpms_path->east);
	open_txt(mlx, txts->txt_west, xpms_path->west);
	open_txt(mlx, txts->txt_north, xpms_path->north);
	open_txt(mlx, txts->txt_south, xpms_path->south);
}

int	txt_init(t_data *data)
{
	data->txts->txt_east = (t_image *)malloc(sizeof(t_image));
	data->txts->txt_west = (t_image *)malloc(sizeof(t_image));
	data->txts->txt_north = (t_image *)malloc(sizeof(t_image));
	data->txts->txt_south = (t_image *)malloc(sizeof(t_image));
	if (!data->txts->txt_east || !data->txts->txt_west
		|| !data->txts->txt_north || !data->txts->txt_south)
		ft_error("malloc_error");
	image_init(data->txts->txt_east);
	image_init(data->txts->txt_west);
	image_init(data->txts->txt_north);
	image_init(data->txts->txt_south);
	txt_loader(data->txts, data->mlx, data->xpms_path);
	return (0);
}
