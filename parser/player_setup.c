/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_setup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnopjira <65420071@kmitl.ac.th>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 20:09:46 by pnopjira          #+#    #+#             */
/*   Updated: 2024/01/26 13:28:11 by pnopjira         ###   ########.fr       */
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
	main->player = main->viewport->scene->p;
	if (d == 'S')
		rotate(main, 180);
	else if (d == 'E')
		rotate(main, -90);
	else if (d == 'W')
		rotate(main, 90);
}
