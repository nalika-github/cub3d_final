/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_allocated02.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 17:10:05 by pnopjira          #+#    #+#             */
/*   Updated: 2024/01/25 11:37:27 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_color(char **color)
{
	int	i;

	i = 0;
	while (color[i])
		free(color[i++]);
	free(color);
}

void	del(void *lst)
{
	t_list	*tmp;

	tmp = (t_list *)lst;
	free(tmp->key);
	free(tmp->content);
	tmp->key = NULL;
	tmp->content = NULL;
}

void	free_int_map(int **tab, int mapy)
{
	int	j;

	j = 0;
	while (j < mapy)
		free(tab[j++]);
	free(tab);
}

void	free_map(t_map *map)
{
	int	j;
	int	i;

	i = 0;
	j = 0;
	if (map->iden)
		ft_lstclear(&map->iden, del);
	if (map->map_original)
	{
		while (map->map_original[i])
			free(map->map_original[i++]);
		free(map->map_original);
	}
	if (map->map)
		free_int_map(map->map, map->mapy);
}
