/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboiron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 10:42:29 by cboiron           #+#    #+#             */
/*   Updated: 2016/11/20 18:36:57 by cboiron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int	i;
	int	signe;
	int	resultat;

	i = 0;
	resultat = 0;
	signe = 1;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-' && ft_isdigit(str[i + 1]))
	{
		signe = -1;
		i++;
	}
	if (str[i] == '+' && ft_isdigit(str[i + 1]))
		i++;
	while (ft_isdigit(str[i]))
		resultat = resultat * 10 + str[i++] - 48;
	return (resultat * signe);
}
