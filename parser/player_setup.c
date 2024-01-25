/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_setup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 20:09:46 by pnopjira          #+#    #+#             */
/*   Updated: 2024/01/25 17:49:18 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	find_player_pos(t_player *p)
{
	double	pos_x;
	double	pos_y;

	pos_x = (p->map_x + 0.5);
	pos_y = (p->map_y + 0.5);
	p->pos->x = pos_x;
	p->pos->y = pos_y;
}

void	begin_dir_of_player(t_main *main, char d)
{
	t_coor	*dir;
	t_coor	*right_dir;
	t_coor	*cam_plane;

	dir = main->viewport->scene->p->dir;
	right_dir = main->viewport->scene->p->right_dir;
	cam_plane = main->viewport->scene->p->cam_plane;
	dir->x = 0;
	dir->y = -1;
	right_dir->x = -1;
	right_dir->y = 0;
	cam_plane->x = 0.66;
	cam_plane->y = 0;
	main->player = main->viewport->scene->p;
	if (d == 'S')
		rotate(main, 180);
	else if (d == 'E')
		rotate(main, 90);
	else if (d == 'W')
		rotate(main, -90);
}
