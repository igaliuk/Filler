/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igaliuk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 19:23:55 by igaliuk           #+#    #+#             */
/*   Updated: 2017/11/01 19:34:18 by igaliuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*elem;

	elem = (t_list*)malloc(sizeof(t_list));
	if (elem == 0)
		return (0);
	if (content != 0)
	{
		elem->content = malloc(content_size);
		if (elem->content == 0)
			return (0);
		elem->content_size = content_size;
		while (content_size + 1 > 0)
		{
			((unsigned char*)elem->content)[content_size - 1] =
				((unsigned char*)content)[content_size - 1];
			content_size--;
		}
	}
	else
	{
		elem->content_size = 0;
		elem->content = NULL;
	}
	elem->next = NULL;
	return (elem);
}
