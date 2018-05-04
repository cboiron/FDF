/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboiron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 00:31:19 by cboiron           #+#    #+#             */
/*   Updated: 2016/11/13 11:45:00 by cboiron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t	k;

	c = (unsigned char)c;
	k = 0;
	while (k < n)
	{
		*((unsigned char*)dest + k) = *((unsigned char*)src + k);
		if (*((unsigned char*)src + k) == c)
			return (dest + (k + 1));
		else
			k++;
	}
	return (NULL);
}
