/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnopjira <65420071@kmitl.ac.th>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 16:25:38 by ptungbun          #+#    #+#             */
/*   Updated: 2024/01/27 09:59:01 by pnopjira         ###   ########.fr       */
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

int	check_before_move(t_player *p, t_main *ms, int m_map_x, int m_map_y)
{
	int	p_map_x;
	int	p_map_y;
	int	**map;

	p_map_x = p->map_x;
	p_map_y = p->map_y;
	map = ms->map;
	if (m_map_x == p_map_x - 1 && (map[m_map_y][m_map_x + 1] == 1))
	{
		if (m_map_y == p_map_y - 1 && map[m_map_y + 1][m_map_x] == 1)
			return (1);
		else if (m_map_y == p_map_y + 1 && map[m_map_y - 1][m_map_x] == 1)
			return (1);
	}
	else if (m_map_x == p_map_x + 1 && map[m_map_y][m_map_x - 1] == 1)
	{
		if (m_map_y == p_map_y - 1 && map[p_map_y + 1][m_map_x] == 1)
			return (1);
		else if (m_map_y == p_map_y + 1 && map[p_map_y - 1][m_map_x] == 1)
			return (1);
	}
	return (0);
}

void	move_f(t_main *ms)
{
	t_player	*p;
	t_coor		buf;

	p = ms->player;
	buf.x = p->pos->x + p->dir->x * MOVE_SPEED;
	buf.y = p->pos->y + p->dir->y * MOVE_SPEED;
	if (check_before_move(p, ms, (int)buf.x, (int)buf.y))
		return ;
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
	if (check_before_move(p, ms, (int)buf.x, (int)buf.y))
		return ;
	if (ms->map[(int)buf.y][(int)buf.x] == 0)
	{
		p->pos->x = buf.x;
		p->pos->y = buf.y;
		p->map_x = (int)p->pos->x;
		p->map_y = (int)p->pos->y;
	}
}
