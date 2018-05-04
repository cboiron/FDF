/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboiron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 17:04:09 by cboiron           #+#    #+#             */
/*   Updated: 2016/11/21 17:47:46 by cboiron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new_elem;

	new_elem = NULL;
	if (lst && f)
	{
		new_elem = f(lst);
		if (new_elem && lst->next)
			new_elem->next = ft_lstmap(lst->next, f);
	}
	return (new_elem);
}
