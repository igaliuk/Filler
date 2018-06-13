/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igaliuk <igaliuk@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 10:17:00 by igaliuk           #+#    #+#             */
/*   Updated: 2018/03/14 10:17:00 by igaliuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		ft_readplayer(void)
{
	char	*line;

	if (get_next_line(0, &line) < 0)
		ft_error_filler();
	if (line[10] == '1')
	{
		ft_strdel(&line);
		return (1);
	}
	ft_strdel(&line);
	return (2);
}

int		main(void)
{
	t_field			*map;
	t_field			*token;
	int				**map2;
	int				player;
	t_sum_x_y		best;

	player = ft_readplayer();
	while (1)
	{
		ft_readfield(&map, player, 4);
		ft_readfield(&token, player, 0);
		map2 = ft_copy_map(map);
		ft_processing_map(map, 2);
		ft_paste_map(map, map2);
		ft_processing_token(map, token, &best);
		if (!(best.sum))
		{
			ft_printf("0 0\n");
			break ;
		}
		else
			ft_printf("%d %d\n", best.y, best.x);
		ft_free_filler(&map, &token, map2);
	}
	return (0);
}
