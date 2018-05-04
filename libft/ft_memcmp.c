/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboiron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 00:19:05 by cboiron           #+#    #+#             */
/*   Updated: 2016/11/13 11:44:18 by cboiron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			k;
	unsigned char	*sa;
	unsigned char	*sb;

	sa = (unsigned char*)s1;
	sb = (unsigned char*)s2;
	k = 0;
	while (k < n)
	{
		if (*(sa + k) != *(sb + k))
			return (*(sa + k) - *(sb + k));
		else
			k++;
	}
	return (0);
}
