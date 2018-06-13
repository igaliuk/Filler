/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_processing_map.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igaliuk <igaliuk@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 12:27:00 by igaliuk           #+#    #+#             */
/*   Updated: 2018/03/14 12:27:00 by igaliuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		**ft_copy_map(t_field *map)
{
	int		**map2;
	int		i;
	int		j;

	if (!(map2 = (int **)malloc(sizeof(int *) * map->y)))
		ft_error_filler();
	j = 0;
	while (j < map->y)
	{
		if (!(map2[j] = (int *)malloc(sizeof(int) * map->x)))
			ft_error_filler();
		i = 0;
		while (i < map->x)
		{
			map2[j][i] = (map->arr)[j][i];
			i++;
		}
		j++;
	}
	return (map2);
}

void	ft_processing_map(t_field *map, int l)
{
	int		i;
	int		j;

	j = 0;
	while (j < map->y)
	{
		i = 0;
		while (i < map->x)
		{
			if ((map->arr)[j][i] == l)
				ft_processing_map_daughter(map, l, i - 1, j - 1);
			i++;
		}
		j++;
	}
	if (ft_check_map(map))
		return ;
	ft_processing_map(map, l + 1);
}

void	ft_processing_map_daughter(t_field *map, int l, int x, int y)
{
	int		i;
	int		j;

	j = y;
	while (j < map->y && j < y + 3)
	{
		i = x;
		if (j >= 0)
			while (i < map->x && i < x + 3)
			{
				if (i >= 0 && (!((map->arr)[j][i]) || (map->arr)[j][i] == 1))
					(map->arr)[j][i] = l + 1;
				i++;
			}
		j++;
	}
}

int		ft_check_map(t_field *map)
{
	int		i;
	int		j;

	j = 0;
	while (j < map->y)
	{
		i = 0;
		while (i < map->x)
		{
			if ((map->arr)[j][i] == 0)
				return (0);
			i++;
		}
		j++;
	}
	return (1);
}

void	ft_paste_map(t_field *map, int **map2)
{
	int		i;
	int		j;

	j = 0;
	while (j < map->y)
	{
		i = 0;
		while (i < map->x)
		{
			if (map2[j][i] == 1)
				(map->arr)[j][i] = 1;
			i++;
		}
		j++;
	}
}
