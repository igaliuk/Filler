/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igaliuk <igaliuk@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 10:18:00 by igaliuk           #+#    #+#             */
/*   Updated: 2018/03/14 10:18:00 by igaliuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"

typedef struct	s_field
{
	int			**arr;
	int			x;
	int			y;
}				t_field;

typedef struct	s_sum_x_y
{
	int			sum;
	int			x;
	int			y;
}				t_sum_x_y;

int				ft_readplayer(void);

void			ft_readfield(t_field **field, int player, int shift);
void			ft_readfield_xy(t_field **field, int shift);
t_list			*ft_readfield_list(int y, int shift);
void			ft_readfield_daughter(int player, t_field **field,
										t_list *lstfield, int shift);
int				ft_processing_xo(int player, char c);

int				**ft_copy_map(t_field *map);
void			ft_processing_map(t_field *map, int l);
void			ft_processing_map_daughter(t_field *map, int l, int x, int y);
int				ft_check_map(t_field *map);
void			ft_paste_map(t_field *map, int **map2);

void			ft_processing_token(t_field *map,
										t_field *token, t_sum_x_y *best);
int				ft_check_token(t_field *map, t_field *token, int x, int y);
int				ft_proccesing_token_daughter(t_field *map,
												t_field *token, int x, int y);

void			ft_shift_token_x(t_field *token);
void			ft_shift_token_y(t_field *token);

void			ft_readhead_readwritefooter(void);
int				ft_checkplayer(void);

void			ft_writefield(t_field **field, int player);
void			ft_writefield_daughter(char *str, t_field *field, int player);
int				ft_super_char(char **str, int k, int d, int player);

void			ft_error_filler(void);
void			ft_free_filler(t_field **map, t_field **token, int **map2);

#endif
