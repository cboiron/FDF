/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboiron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 17:30:37 by cboiron           #+#    #+#             */
/*   Updated: 2016/11/21 18:04:33 by cboiron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(const char *s, unsigned int start, size_t len)
{
	char	*dest;
	size_t	i;
	size_t	j;

	if (!s)
		return (NULL);
	i = start;
	j = 0;
	if (len == 0)
		return (ft_strdup(""));
	dest = malloc(sizeof(char) * len + 1);
	if (dest == NULL)
		return (NULL);
	while (s[i] != '\0' && j < len)
	{
		dest[j++] = s[i++];
	}
	dest[j] = '\0';
	return (dest);
}
