/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tex_image.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnopjira <65420071@kmitl.ac.th>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 15:05:52 by pnopjira          #+#    #+#             */
/*   Updated: 2024/01/27 09:50:08 by pnopjira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	bg_init(t_vp *vars)
{
	t_imgdata	*img;
	t_frame		*scene;

	img = (*vars).bgimg;
	scene = (*vars).scene;
	img->img = mlx_new_image((*vars).mlx, scene->w, scene->h);
	img->addr = mlx_get_data_addr(img->img, &img->bpp, \
	&img->llen, &img->endian);
}

t_imgdata	get_tex_image(t_vp *vp, char *path, int *w, int *h)
{
	t_imgdata	teximg;

	teximg.img = mlx_xpm_file_to_image(vp->mlx, path, w, h);
	if (teximg.img == NULL)
	{
		ft_putstr_fd(RED"Error\n"RESET, 2);
		ft_putstr_fd(RED"image path: %s not found\n"RESET, 2);
		return (teximg);
	}
	teximg.addr = mlx_get_data_addr(teximg.img, &teximg.bpp, \
	&teximg.llen, &teximg.endian);
	return (teximg);
}
