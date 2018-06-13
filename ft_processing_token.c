/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_processing_token.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igaliuk <igaliuk@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 10:17:00 by igaliuk           #+#    #+#             */
/*   Updated: 2018/03/14 10:17:00 by igaliuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_processing_token(t_field *map, t_field *token, t_sum_x_y *best)
{
	t_sum_x_y	cur;

	best->sum = 0;
	cur.y = 1 - token->y;
	while (cur.y < map->y - token->y + 1)
	{
		cur.x = 1 - token->x;
		while (cur.x < map->x - token->x + 1)
		{
			if (ft_check_token(map, token, cur.x, cur.y) == 1)
			{
				cur.sum = ft_proccesing_token_daughter(map,
														token, cur.x, cur.y);
				if (!(best->sum) || best->sum > cur.sum)
				{
					best->sum = cur.sum;
					best->x = cur.x;
					best->y = cur.y;
				}
			}
			cur.x++;
		}
		cur.y++;
	}
}

int		ft_check_token(t_field *map, t_field *token, int x, int y)
{
	int		i;
	int		j;
	int		p;

	p = 0;
	j = y;
	while (j < y + token->y)
	{
		i = x;
		while (i < x + token->x)
		{
			if ((token->arr)[j - y][i - x])
			{
				if (i < 0 || j < 0
					|| (map->arr)[j][i] == ((token->arr)[j - y][i - x]) * 2)
					return (-1);
				if ((token->arr)[j - y][i - x] == (map->arr)[j][i])
					p++;
			}
			i++;
		}
		j++;
	}
	return (p);
}

int		ft_proccesing_token_daughter(t_field *map, t_field *token, int x, int y)
{
	int		sum;
	int		i;
	int		j;

	sum = 0;
	j = y;
	while (j < y + token->y)
	{
		i = x;
		while (i < x + token->x)
		{
			if ((token->arr)[j - y][i - x])
				sum += (map->arr)[j][i];
			i++;
		}
		j++;
	}
	return (sum);
}
