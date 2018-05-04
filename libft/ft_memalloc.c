/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboiron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 14:09:59 by cboiron           #+#    #+#             */
/*   Updated: 2016/11/22 15:20:27 by cboiron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*s;

	s = malloc(sizeof(s) * size);
	if (s == NULL)
		return (0);
	ft_bzero(s, size);
	return (s);
}
