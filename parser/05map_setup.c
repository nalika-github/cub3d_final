/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   05map_setup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnopjira <65420071@kmitl.ac.th>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 15:49:23 by pnopjira          #+#    #+#             */
/*   Updated: 2024/01/27 06:42:14 by pnopjira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	setup_pos_mapx(char **mapdata, int j, t_map *map, t_player *p)
{
	int		x;

	x = 0;
	while (mapdata[j][x])
	{
		if (mapdata[j][x] == 'N' || mapdata[j][x] == 'S' \
		|| mapdata[j][x] == 'W' || mapdata[j][x] == 'E')
		{
			if (setup_pos(&mapdata[j][x], x, j, p))
				return (8);
		}
		else if (!(mapdata[j][x] == '0' || mapdata[j][x] == '1' \
		|| mapdata[j][x] == ' '))
			return (5);
		x++;
	}
	if ((int)ft_strlen(mapdata[j]) > map->mapx)
		map->mapx = ft_strlen(mapdata[j]);
	return (EXIT_SUCCESS);
}

int	set_main_struct(t_main	*main)
{
	if (set_vp(main))
		return (EXIT_FAILURE);
	main->filemap = main->viewport->scene->map;
	main->player = main->viewport->scene->p;
	find_player_pos(main->player);
	begin_dir_of_player(main, main->player->d);
	main->map = main->viewport->scene->map->map;
	main->floor_color = main->viewport->scene->floor_color;
	main->ceiling_color = main->viewport->scene->ceiling_color;
	get_textures_path(main);
	main->viewport->tex_so_img = get_tex_image(main->viewport, main->tex_so, \
	&main->tex_width, &main->tex_hight);
	main->viewport->tex_no_img = get_tex_image(main->viewport, main->tex_no, \
	&main->tex_width, &main->tex_hight);
	main->viewport->tex_we_img = get_tex_image(main->viewport, main->tex_we, \
	&main->tex_width, &main->tex_hight);
	main->viewport->tex_ea_img = get_tex_image(main->viewport, main->tex_ea, \
	&main->tex_width, &main->tex_hight);
	return (EXIT_SUCCESS);
}

void	get_textures_path(t_main *main)
{
	t_list	*ptr;

	ptr = main->filemap->iden;
	while (ptr)
	{
		if (ft_strncmp(ptr->key, "NO", 1) == 0)
			main->tex_no = ptr->content;
		else if (ft_strncmp(ptr->key, "SO", 1) == 0)
			main->tex_so = ptr->content;
		else if (ft_strncmp(ptr->key, "WE", 1) == 0)
			main->tex_we = ptr->content;
		else if (ft_strncmp(ptr->key, "EA", 1) == 0)
			main->tex_ea = ptr->content;
		ptr = ptr->next;
	}
}

int	err_msg(bool map_begin, int *err, char type)
{
	if (map_begin == true)
		*err = 5;
	else
	{
		if (type == 'n')
			*err = 0;
		else if (type == 'c')
			*err = 9;
	}
}
