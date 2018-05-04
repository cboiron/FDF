/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboiron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 07:27:56 by cboiron           #+#    #+#             */
/*   Updated: 2016/11/21 18:04:19 by cboiron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *str)
{
	char			*dest;
	unsigned int	i;
	size_t			j;

	if (!str)
		return (0);
	i = 0;
	j = ft_strlen(str) - 1;
	while (ft_isblank(str[i]) || str[i] == '\n')
	{
		if (str[i + 1] == '\0')
			return (ft_strdup(""));
		i++;
	}
	while (ft_isblank(str[j]) || str[j] == '\n')
		j--;
	if (i == 0 && j == (size_t)(ft_strlen(str) - 1))
		dest = ft_strdup(str);
	else
	{
		dest = ft_strsub(str, i, j - i + 1);
		if (dest == NULL)
			return (0);
	}
	return (dest);
}
