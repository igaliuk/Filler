/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_map_token.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igaliuk <igaliuk@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 10:21:00 by igaliuk           #+#    #+#             */
/*   Updated: 2018/03/14 10:21:00 by igaliuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_writefield(t_field **field, int player)
{
	char	*str;

	if (!(str = ft_strnew((*field)->y * ((*field)->x * 5 + 1))))
		ft_error_filler();
	ft_writefield_daughter(str, *field, player);
	ft_printf("%s\n", str);
	ft_strdel(&str);
	ft_free_filler(field, NULL, NULL);
}

void	ft_writefield_daughter(char *str, t_field *field, int player)
{
	int		i;
	int		j;
	int		k;

	k = 0;
	i = 0;
	while (i < field->y)
	{
		j = 0;
		while (j < field->x)
		{
			k += ft_super_char(&str, k, (field->arr)[i][j], player);
			str[k++] = ' ';
			j++;
		}
		str[k++] = '\n';
		i++;
	}
}

int		ft_super_char(char **str, int k, int d, int player)
{
	if (d == 2 || (d == 1 && player == 2))
	{
		(*str)[k++] = 240;
		(*str)[k++] = 159;
		(*str)[k++] = 148;
		(*str)[k] = 180;
		return (4);
	}
	if (d == 1)
	{
		(*str)[k++] = 226;
		(*str)[k++] = 154;
		(*str)[k] = 170;
	}
	if (d == 0)
	{
		(*str)[k++] = 226;
		(*str)[k++] = 154;
		(*str)[k] = 171;
	}
	return (3);
}
