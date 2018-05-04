/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboiron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 12:10:38 by cboiron           #+#    #+#             */
/*   Updated: 2016/11/23 06:27:16 by cboiron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size, int n)
{
	t_list	*new_elem;

	new_elem = (t_list *)malloc(sizeof(t_list));
	if (new_elem == 0)
		return (NULL);
	if (content == NULL)
	{
		new_elem->nombre = n;
		new_elem->content = NULL;
		new_elem->content_size = 0;
	}
	else
	{
		if (!(new_elem->content = malloc(content_size)))
			return (0);
		ft_memcpy(new_elem->content, content, content_size);
		new_elem->content_size = content_size;
		new_elem->nombre = n;
	}
	new_elem->next = NULL;
	return (new_elem);
}
