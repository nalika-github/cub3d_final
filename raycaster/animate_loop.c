/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animate_loop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnopjira <65420071@kmitl.ac.th>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 13:56:36 by ptungbun          #+#    #+#             */
/*   Updated: 2024/01/25 21:16:01 by pnopjira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	animate_loop(t_main *ms)
{
	t_vp		*vp;
	t_player	*p;

	vp = ms->viewport;
	p = ms->player;
	calculate_movement(ms);
	re_calculate_ray(ms);
	cub3d_render(ms, ms->viewport);
	mlx_put_image_to_window(vp->mlx, vp->win, vp->bgimg->img, 0, 0);
	return (0);
}

void	re_calculate_ray(t_main *ms)
{
	int			i;
	t_ray		*ray;
	t_player	*p;

	ray = ms->ray;
	if (!ray)
		return ;
	p = ms->player;
	i = 0;
	while (i < WINDOW_WIDTH)
	{
		ray[i].raydir.x = p->dir->x + p->cam_plane->x * ray[i].lcpd;
		ray[i].raydir.y = p->dir->y + p->cam_plane->y * ray[i].lcpd;
		get_step_ray_dist(&ray[i]);
		get_first_step_ray_dist(&ray[i], p);
		perform_dda(&ray[i], ms->map, p);
		cal_ray_projection_dist_n_wall_hight(&ray[i]);
		ray_on_wall_pos_cal(ms, &ray[i], p);
		i++;
	}
}

void	calculate_movement(t_main *ms)
{
	if(ms->event.turn_r == 1)
		rotate(ms, -1 * TURN_SPEED);
	if(ms->event.turn_l == 1)
		rotate(ms, TURN_SPEED);
	if(ms->event.move_l == 1)
		move_l(ms);
	if(ms->event.move_r == 1)
		move_r(ms);
	if(ms->event.move_f == 1)
		move_f(ms);
	if(ms->event.move_b == 1)
		move_b(ms);
}

int	press_event(int key, t_main *ms)
{
	if (key == KEY_ESC)
		x_exit(ms);
	if (key == KEY_RIGHT)
		ms->event.turn_r = 1;
	if (key == KEY_LEFT)
		ms->event.turn_l = 1;
	if (key == KEY_A)
		ms->event.move_l = 1;
	if (key == KEY_D)
		ms->event.move_r = 1;
	if (key == KEY_UP || key == KEY_W)
		ms->event.move_f = 1;
	if (key == KEY_DOWN || key == KEY_S)
		ms->event.move_b = 1;
	return (0);
}

int	release_event(int key, t_main *ms)
{
	if (key == KEY_RIGHT)
		ms->event.turn_r = 0;
	if (key == KEY_LEFT)
		ms->event.turn_l = 0;
	if (key == KEY_A)
		ms->event.move_l = 0;
	if (key == KEY_D)
		ms->event.move_r = 0;
	if (key == KEY_UP || key == KEY_W)
		ms->event.move_f = 0;
	if (key == KEY_DOWN || key == KEY_S)
		ms->event.move_b = 0;
	return (0);
}

