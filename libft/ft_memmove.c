/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboiron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 23:12:14 by cboiron           #+#    #+#             */
/*   Updated: 2016/11/13 11:43:44 by cboiron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*dest2;
	unsigned char	*src2;

	dest2 = (unsigned char*)dest;
	src2 = (unsigned char*)src;
	i = 0;
	if (dest2 < src2)
	{
		while (i < len)
		{
			dest2[i] = src2[i];
			i++;
		}
	}
	else
	{
		i = len;
		while (i > 0)
		{
			dest2[i - 1] = src2[i - 1];
			i--;
		}
	}
	return (dest);
}
