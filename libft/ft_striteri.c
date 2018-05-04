/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboiron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 07:30:49 by cboiron           #+#    #+#             */
/*   Updated: 2016/11/19 20:42:56 by cboiron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;
	unsigned int	len;

	if (!s || !f)
		return ;
	i = 0;
	len = ft_strlen(s);
	if (len != 0)
	{
		while (i < len && s[i])
		{
			f(i, (s + i));
			i++;
		}
	}
}
