/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboiron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 11:54:33 by cboiron           #+#    #+#             */
/*   Updated: 2016/11/19 20:31:04 by cboiron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*dest;
	unsigned int	len;
	unsigned int	i;

	i = 0;
	if (!s)
		return (0);
	len = ft_strlen(s);
	dest = malloc(sizeof(char) * len + 1);
	if (dest == NULL)
		return (0);
	ft_strclr(dest);
	while (i < len)
	{
		dest[i] = f(i, s[i]);
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
