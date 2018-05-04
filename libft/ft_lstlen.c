/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboiron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 05:53:44 by cboiron           #+#    #+#             */
/*   Updated: 2016/11/25 06:04:45 by cboiron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_lstlen(t_list **lst)
{
	size_t	len;
	t_list	*tmp;

	len = 0;
	tmp = *lst;
	if (!tmp)
		return (0);
	while (tmp)
	{
		tmp = (tmp)->next;
		len++;
	}
	return (len);
}
