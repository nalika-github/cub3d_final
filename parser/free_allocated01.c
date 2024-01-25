/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_allocated01.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnopjira <65420071@kmitl.ac.th>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 18:42:34 by pnopjira          #+#    #+#             */
/*   Updated: 2024/01/25 21:16:15 by pnopjira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


void	free_player(t_player *p)
{
	free(p->pos);
	free(p->dir);
	free(p->right_dir);
	free(p->cam_plane);
}

void	free_scene(t_frame *scene)
{
	t_frame	*s;

	s = scene;
	if (s->map)
	{
		free_map(s->map);
		free(s->map);
	}
	if (s->p)
	{
		free_player(s->p);
		free(s->p);
	}
	s->map = NULL;
	s->p = NULL;
	free(s);
}

int	cub3d_exit(t_main *main_struc)
{
	t_vp	*vp;

	vp = main_struc->viewport;
	if (vp->scene)
		free_scene(vp->scene);
	if (vp->bgimg)
	{
		if (vp->bgimg->img)
			mlx_destroy_image(vp->mlx, vp->bgimg->img);
		free(vp->bgimg);
	}
	if (vp->mlx && vp->win)
		mlx_destroy_window(vp->mlx, vp->win);
	free(vp);
	if (main_struc->ray)
		free(main_struc->ray);
	return (0);
}

int x_exit(t_main *main_struct)
{
	cub3d_exit(main_struct);
	ft_putstr_fd(RED"Exit\n"RESET, 1);
	exit(0);
}