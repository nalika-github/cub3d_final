/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01map_setup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 20:01:21 by pnopjira          #+#    #+#             */
/*   Updated: 2024/01/25 17:26:01 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_main_struct(t_main *main)
{
	main->viewport = NULL;
	main->filemap = NULL;
	main->player = NULL;
	main->ray = NULL;
	main->map = NULL;
	main->floor_color = 0xFFFFFF;
	main->ceiling_color = 0x000000;
	main->tex_so = NULL;
	main->tex_no = NULL;
	main->tex_we = NULL;
	main->tex_ea = NULL;
	main->one_player = false;
	main->tex_width = TEX_WIDTH;
	main->tex_hight = TEX_HIGHT;
	main->event.move_f = 0;
	main->event.move_b = 0;
	main->event.move_l = 0;
	main->event.move_r = 0;
	main->event.turn_l = 0;
	main->event.turn_r = 0;
}

void	init_imgdata(t_imgdata *bgimg)
{
	bgimg->img = NULL;
	bgimg->addr = NULL;
	bgimg->bpp = 0;
	bgimg->llen = 0;
	bgimg->endian = 0;
}

int	is_invalid_input(char *argv, t_main *main)
{
	t_vp		*vars;

	main->viewport = (t_vp *)malloc(sizeof(t_vp) * 1);
	vars = main->viewport;
	vars->mlx = NULL;
	vars->win = NULL;
	vars->scene = (t_frame *)malloc(sizeof(t_frame) * 1);
	vars->bgimg = (t_imgdata *)malloc(sizeof(t_imgdata) * 1);
	if (vars == NULL || vars->scene == NULL || vars->bgimg == NULL)
		return (EXIT_FAILURE);
	init_scene(vars->scene);
	init_imgdata(vars->bgimg);
	if (check_invalid_filedata(argv, vars->scene->map, vars->scene->p))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

void	del_nl(char **line)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = *line;
	while (tmp[i])
	{
		if (tmp[i] == '\n')
		{
			tmp[i] = '\0';
			break ;
		}
		i++;
	}
}

int	setup_pos(char *dir, int x, int y, t_player *p)
{
	if (p->one_player == false)
		p->one_player = true;
	else
		return (EXIT_FAILURE);
	p->map_x = x;
	p->map_y = y;
	p->d = *dir;
	return (EXIT_SUCCESS);
}
