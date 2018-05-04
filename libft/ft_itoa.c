/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboiron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 02:58:20 by cboiron           #+#    #+#             */
/*   Updated: 2016/11/20 20:30:44 by cboiron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_count(int n)
{
	int		count;

	count = 0;
	while (n != 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

char		*ft_itoa(int c)
{
	int		count;
	char	*tab;

	if (c == -2147483648)
		return (ft_strdup("-2147483648"));
	if (c == 0)
		return (ft_strdup("0"));
	count = ft_count(c);
	if (c < 0)
		count++;
	if (!(tab = (char*)malloc(sizeof(char) * (count + 1))))
		return (NULL);
	if (c < 0)
	{
		tab[0] = '-';
		c = c * -1;
	}
	tab[count] = '\0';
	while (c != 0)
	{
		tab[--count] = ((c % 10) + '0');
		c = c / 10;
	}
	return (tab);
}
