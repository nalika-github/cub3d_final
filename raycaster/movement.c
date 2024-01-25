/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 16:25:38 by ptungbun          #+#    #+#             */
/*   Updated: 2024/01/25 19:14:38 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_l(t_main *ms)
{
	t_player	*p;
	t_coor		buf;

	p = ms->player;
	buf.x = p->pos->x + p->right_dir->x * MOVE_SPEED;
	buf.y = p->pos->y + p->right_dir->y * MOVE_SPEED;
	if (ms->map[(int)buf.y][(int)buf.x] == 0)
	{
		p->pos->x = buf.x;
		p->pos->y = buf.y;
		p->map_x = (int)p->pos->x;
		p->map_y = (int)p->pos->y;
	}
}

void	move_r(t_main *ms)
{
	t_player	*p;
	t_coor		buf;

	p = ms->player;
	buf.x = p->pos->x - p->right_dir->x * MOVE_SPEED;
	buf.y = p->pos->y - p->right_dir->y * MOVE_SPEED;
	if (ms->map[(int)buf.y][(int)buf.x] == 0)
	{
		p->pos->x = buf.x;
		p->pos->y = buf.y;
		p->map_x = (int)p->pos->x;
		p->map_y = (int)p->pos->y;
	}
}

void	move_f(t_main *ms)
{
	t_player	*p;
	t_coor		buf;

	p = ms->player;
	buf.x = p->pos->x + p->dir->x * MOVE_SPEED;
	buf.y = p->pos->y + p->dir->y * MOVE_SPEED;
	if (ms->map[(int)buf.y][(int)buf.x] == 0)
	{
		p->pos->x = buf.x;
		p->pos->y = buf.y;
		p->map_x = (int)p->pos->x;
		p->map_y = (int)p->pos->y;
	}
}

void	move_b(t_main *ms)
{
	t_player	*p;
	t_coor		buf;

	p = ms->player;
	buf.x = p->pos->x - p->dir->x * MOVE_SPEED;
	buf.y = p->pos->y - p->dir->y * MOVE_SPEED;
	if (ms->map[(int)buf.y][(int)buf.x] == 0)
	{
		p->pos->x = buf.x;
		p->pos->y = buf.y;
		p->map_x = (int)p->pos->x;
		p->map_y = (int)p->pos->y;
	}
}
