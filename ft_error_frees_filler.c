/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_frees_filler.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igaliuk <igaliuk@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 10:19:00 by igaliuk           #+#    #+#             */
/*   Updated: 2018/03/18 10:19:00 by igaliuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_error_filler(void)
{
	write(1, "\e[1;31mERROR\n\e[0m", 17);
	exit(0);
}

void	ft_free_filler(t_field **map, t_field **token, int **map2)
{
	if (map2)
		ft_arrdel(map2, (size_t)(*map)->y);
	if (map)
	{
		ft_arrdel((*map)->arr, (size_t)((*map)->y));
		free(*map);
		*map = NULL;
	}
	if (token)
	{
		ft_arrdel((*token)->arr, (size_t)((*token)->y));
		free(*token);
		*token = NULL;
	}
}
