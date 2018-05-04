/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboiron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 20:41:32 by cboiron           #+#    #+#             */
/*   Updated: 2016/11/20 20:22:24 by cboiron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*dest;
	size_t	i;

	i = 0;
	dest = (char*)malloc(sizeof(char) * ft_strlen(src) + 1);
	if (dest == 0)
		return (0);
	else
	{
		while (i < ft_strlen(src))
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (dest);
}
