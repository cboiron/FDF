/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboiron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 22:25:27 by cboiron           #+#    #+#             */
/*   Updated: 2016/11/20 20:21:47 by cboiron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t	k;

	k = 0;
	while (k < n)
	{
		dest[k] = src[k];
		if (k > ft_strlen(src))
			dest[k] = '\0';
		k++;
	}
	return (dest);
}
