/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03map_setup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 09:53:43 by pnopjira          #+#    #+#             */
/*   Updated: 2024/01/25 11:36:56 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	set_vp(t_main *main)
{
	if (explicit_error(set_scene(main->viewport->scene)))
		return (EXIT_FAILURE);
	main->viewport->mlx = mlx_init();
	main->viewport->win = mlx_new_window(main->viewport->mlx, \
	main->viewport->scene->w, main->viewport->scene->h, "isWorld-cub3D");
	bg_init(main->viewport);
	return (EXIT_SUCCESS);
}

int	allocated_map_int(int ***map, int mapy, int mapx)
{
	int		y;
	int		**n_map;

	y = 0;
	n_map = (int **)malloc(sizeof(int *) * mapy);
	if (n_map == NULL)
		return (EXIT_FAILURE);
	while (y < mapy)
	{
		n_map[y++] = (int *)malloc(sizeof(int) * mapx);
		if (n_map[y - 1] == NULL)
			return (EXIT_FAILURE);
	}
	*map = n_map;
	return (EXIT_SUCCESS);
}

int	tranformer(char o_map)
{
	int		n_map;

	if (o_map == '1')
		n_map = 1;
	else if (o_map == ' ')
		n_map = -1;
	else if (o_map == '0')
		n_map = 0;
	else
		n_map = 0;
	return (n_map);
}

int	char_to_int_map(char **o_map, t_map *plan)
{
	int			**n_map;
	int			y;
	int			x;
	const int	i = plan->mapx;
	const int	j = plan->mapy;

	y = 0;
	allocated_map_int(&n_map, j, i);
	while (y < j)
	{
		x = 0;
		while (o_map[y][x] != '\0')
		{
			n_map[y][x] = tranformer(o_map[y][x]);
			x++;
		}
		while (x < i)
			n_map[y][x++] = -1;
		y++;
	}
	plan->map = n_map;
	return (EXIT_SUCCESS);
}

int	ck_map_info(t_map *map)
{
	if (map->map_begin == 0)
	{
		map->map_begin = 1;
		(map->mapy)++;
	}
	else
	{
		(map->mapy)++;
	}
	return (EXIT_SUCCESS);
}
