/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_dataformat.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnopjira <65420071@kmitl.ac.th>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 05:59:07 by pnopjira          #+#    #+#             */
/*   Updated: 2024/01/27 06:35:48 by pnopjira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	init_content(t_list *iden, char **dst, char **src, char *key)
{
	char	*str;

	str = ft_strtrim(*src, key);
	*dst = ft_strtrim(str, " ");
	free(str);
	if (!ft_strncmp(key, "NO", 2) || !ft_strncmp(key, "SO", 2) || \
	!ft_strncmp(key, "WE", 2) || !ft_strncmp(key, "EA", 2))
	{
		if (invalid_filepath(*dst, ".xpm"))
			return (free(*src), free(*dst), 3);
	}
	else if (!ft_strncmp(key, "F", 1) || !ft_strncmp(key, "C", 1))
	{
		if (invalid_color_code(*dst))
			return (free(*src), free(*dst), 6);
	}
	if (key_to_content(iden, key, *dst))
		return (free(*src), 4);
	free(*src);
	src = NULL;
	return (EXIT_SUCCESS);
}

void	ck_no_so_we_ea(int *err, char *tmp, t_list *iden)
{
	char	*str1;
	char	*str2;

	str1 = NULL;
	str2 = (char *) malloc(sizeof(char) * ft_strlen(tmp));
	ft_strlcpy(str2, tmp, ft_strlen(tmp) - 1);
	if (ft_strncmp(str2, "NO", 2) == 0)
		*err = init_content(iden, &str1, &str2, "NO");
	else if (ft_strncmp(str2, "SO", 2) == 0)
		*err = init_content(iden, &str1, &str2, "SO");
	else if (ft_strncmp(str2, "WE", 2) == 0)
		*err = init_content(iden, &str1, &str2, "WE");
	else if (ft_strncmp(str2, "EA", 2) == 0)
		*err = init_content(iden, &str1, &str2, "EA");
	return ;
}

void	ck_f_c_color(int *err, char *tmp, t_list *iden)
{
	char	*str1;
	char	*str2;

	str1 = NULL;
	str2 = (char *)malloc(sizeof(char) * ft_strlen(tmp));
	ft_strlcpy(str2, tmp, ft_strlen(tmp) - 1);
	if (ft_strncmp(str2, "F", 1) == 0)
		*err = init_content(iden, &str1, &str2, "F");
	if (ft_strncmp(str2, "C", 1) == 0)
		*err = init_content(iden, &str1, &str2, "C");
	return ;
}

void	ck_data_format(char *tmp, int *err, t_map *map)
{
	if (tmp[0] == '\n' && tmp[1] == '\0')
		err_msg(map->map_begin, err, 'n');
	else if ((!ft_strncmp(tmp, "NO ", 3) || !ft_strncmp(tmp, "SO ", 3) \
	|| !ft_strncmp(tmp, "WE ", 3) || !ft_strncmp(tmp, "EA ", 3)) \
	&& map->map_begin == 0)
		ck_no_so_we_ea(err, tmp, map->iden);
	else if ((!ft_strncmp(tmp, "F ", 2) || !ft_strncmp(tmp, "C ", 2)) \
	&& map->map_begin == 0)
		ck_f_c_color(err, tmp, map->iden);
	else if (tmp[0] == ' ' || tmp[0] == '1' || tmp[0] == '0' || \
	(tmp[0] == 'N' && tmp[1] != 'O') || (tmp[0] == 'S' && tmp[1] != 'O') \
	|| (tmp[0] == 'W' && tmp[1] != 'E') || (tmp[0] == 'E' && tmp[1] != 'A'))
	{
		*err = ck_map_info(map);
		if (tmp[0] == 'N' || tmp[0] == 'S' || tmp[0] == 'W' || tmp[0] == 'E')
			*err = 7;
	}
	else
		err_msg(map->map_begin, err, 'c');
}

void	ck_invalid_iden(int *err, int fd1, t_map *map)
{
	char	*line;
	char	*tmp;

	line = get_next_line(fd1);
	while (line)
	{
		if (before_map(map, err))
			break ;
		tmp = ft_strtrim(line, " ");
		free(line);
		line = NULL;
		ck_data_format(tmp, err, map);
		free(tmp);
		if (*err != 0)
			break ;
		line = get_next_line(fd1);
	}
	if (line)
		free(line);
	close(fd1);
}
