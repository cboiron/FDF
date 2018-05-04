/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboiron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 05:04:40 by cboiron           #+#    #+#             */
/*   Updated: 2016/11/12 08:38:46 by cboiron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (little[i] == '\0')
		return ((char*)big);
	while (big[i])
	{
		while (little[j] == big[i])
		{
			i++;
			j++;
			if (little[j] == '\0')
				return ((char*)(big + i - j));
			if (big[i] == '\0' && little[i] != '\0')
				return (NULL);
		}
		i = i - j + 1;
		j = 0;
	}
	return (NULL);
}
