/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboiron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 23:37:33 by cboiron           #+#    #+#             */
/*   Updated: 2016/11/07 23:51:02 by cboiron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t k;

	k = 0;
	while (k < n)
	{
		*((unsigned char*)(dest + k)) = *((unsigned char*)(src + k));
		k++;
	}
	return (dest);
}
