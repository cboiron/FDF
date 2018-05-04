/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboiron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 11:05:27 by cboiron           #+#    #+#             */
/*   Updated: 2016/11/21 18:03:51 by cboiron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	int		j;

	i = 0;
	j = 0;
	if (little[i] == '\0')
		return ((char*)big);
	while (i < len && big[i])
	{
		while (big[i] == little[j] && i < len && little[j])
		{
			i++;
			j++;
			if (little[j] == '\0')
				return ((char*)big + i - j);
		}
		i = i - j + 1;
		j = 0;
	}
	return (NULL);
}
