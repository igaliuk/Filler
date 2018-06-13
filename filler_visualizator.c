/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler_visualizator.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igaliuk <igaliuk@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 10:17:00 by igaliuk           #+#    #+#             */
/*   Updated: 2018/03/14 10:17:00 by igaliuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_readhead_readwritefooter(void)
{
	int		i;
	char	*line;

	i = 0;
	while (i < 9)
	{
		if (get_next_line(0, &line) < 0)
			ft_error_filler();
		system("clear");
		ft_strdel(&line);
		i++;
	}
}

int		ft_checkplayer(void)
{
	char	*line;

	if (get_next_line(0, &line) < 0)
		ft_error_filler();
	if (line[6] == 'O')
	{
		ft_strdel(&line);
		return (1);
	}
	ft_strdel(&line);
	return (2);
}

int		main(void)
{
	t_field		*map;
	t_field		*token;
	int			check;

	check = 0;
	ft_readhead_readwritefooter();
	while (1)
	{
		ft_readfield(&map, 1, 4);
		if (map)
		{
			usleep(166666);
			system("clear");
			ft_writefield(&map, 0);
		}
		else
			check++;
		if (check == 2)
			break ;
		ft_readfield(&token, 1, 0);
		if (token)
			ft_writefield(&token, ft_checkplayer());
	}
	return (0);
}
