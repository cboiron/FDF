/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboiron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 00:03:06 by cboiron           #+#    #+#             */
/*   Updated: 2016/11/12 04:37:10 by cboiron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t len)
{
	size_t	k;

	k = 0;
	c = (unsigned char)c;
	while (k < len)
	{
		if (*((unsigned char*)s + k) == c)
			return ((void*)s + k);
		k++;
	}
	return (NULL);
}
