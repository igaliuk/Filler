/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_map_token.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igaliuk <igaliuk@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 10:21:00 by igaliuk           #+#    #+#             */
/*   Updated: 2018/03/14 10:21:00 by igaliuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_readfield(t_field **field, int player, int shift)
{
	t_list		*lstfield;

	*field = NULL;
	ft_readfield_xy(field, shift);
	if (*field)
	{
		lstfield = ft_readfield_list((*field)->y, shift);
		ft_readfield_daughter(player, field, lstfield, shift);
		ft_lstdel(&lstfield, &ft_del);
	}
}

void	ft_readfield_xy(t_field **field, int shift)
{
	static char	*line = NULL;
	int			i;
	int			x;
	int			y;

	if (!line && get_next_line(0, &line) < 0)
		ft_error_filler();
	if ((ft_strncmp(line, "Plateau", 7) && shift == 4)
		|| (ft_strncmp(line, "Piece", 5) && shift == 0))
		return ;
	i = 0;
	while (line[i] && line[i] != ' ')
		i++;
	i++;
	y = ft_atoi(line + i);
	while (line[i] && line[i] != ' ')
		i++;
	x = ft_atoi(line + i);
	ft_strdel(&line);
	if (!(*field = (t_field *)malloc(sizeof(t_field))))
		ft_error_filler();
	(*field)->x = x;
	(*field)->y = y;
}

t_list	*ft_readfield_list(int y, int shift)
{
	char	*line;
	t_list	*lstfield;
	t_list	*tmp;

	lstfield = NULL;
	if (shift)
	{
		if (get_next_line(0, &line) < 0)
			ft_error_filler();
		ft_strdel(&line);
	}
	while (y > 0)
	{
		if ((get_next_line(0, &line) < 0)
			|| !(tmp = ft_lstnew(NULL, 0))
			|| !(tmp->content = ft_strdup(line)))
			ft_error_filler();
		ft_lstaddback(&lstfield, tmp);
		ft_strdel(&line);
		y--;
	}
	return (lstfield);
}

void	ft_readfield_daughter(int player, t_field **field,
								t_list *lstfield, int shift)
{
	t_list	*tmp;
	int		i;
	int		j;

	if (!((*field)->arr = (int **)malloc(sizeof(int *) * (*field)->y)))
		ft_error_filler();
	tmp = lstfield;
	i = 0;
	while (tmp)
	{
		if (!(((*field)->arr)[i] = (int *)malloc(sizeof(int) * (*field)->x)))
			ft_error_filler();
		j = 0;
		while (j < (*field)->x)
		{
			((*field)->arr)[i][j] = ft_processing_xo(player,
										((char *)(tmp->content))[j + shift]);
			j++;
		}
		tmp = tmp->next;
		i++;
	}
}

int		ft_processing_xo(int player, char c)
{
	if (player == 1)
	{
		if (c == 'o' || c == 'O' || c == '*')
			return (1);
		if (c == 'x' || c == 'X')
			return (2);
	}
	else
	{
		if (c == 'o' || c == 'O')
			return (2);
		if (c == 'x' || c == 'X' || c == '*')
			return (1);
	}
	return (0);
}
