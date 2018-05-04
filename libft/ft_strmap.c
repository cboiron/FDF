/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboiron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 07:42:02 by cboiron           #+#    #+#             */
/*   Updated: 2016/11/20 18:07:45 by cboiron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(const char *s, char (*f)(char))
{
	unsigned int	i;
	unsigned int	len;
	char			*dest;

	i = 0;
	if (!s)
		return (NULL);
	len = ft_strlen(s);
	dest = (char *)malloc(sizeof(char) * (len + 1));
	if (dest == 0)
		return (NULL);
	while (i < len)
	{
		dest[i] = f(s[i]);
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
