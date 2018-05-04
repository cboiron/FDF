/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboiron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 17:32:18 by cboiron           #+#    #+#             */
/*   Updated: 2017/03/11 01:55:08 by cboiron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_countwords(const char *s, char c)
{
	int		i;
	int		count;

	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c)
			count++;
		while (s[i] != c && s[i] != '\0')
			i++;
		while (s[i] == c && s[i] != '\0')
			i++;
	}
	return (count);
}

static int	ft_count_l(const char *s, char c)
{
	int		j;

	j = 0;
	while (*s != c && *s != '\0')
	{
		s++;
		j++;
	}
	return (j);
}

char		**ft_strsplit(const char *s, char c)
{
	char	**tab;
	int		words;
	int		j;

	if (!s)
		return (NULL);
	j = 0;
	words = ft_countwords(s, c);
	tab = (char**)malloc(sizeof(char*) * words + 1);
	if (tab == NULL)
		return (NULL);
	while (words--)
	{
		while (*s == c && *s)
			s++;
		tab[j] = ft_strsub(s, 0, ft_count_l(s, c));
		if (tab[j] == NULL)
			return (NULL);
		j++;
		s = s + ft_count_l(s, c);
	}
	tab[j] = NULL;
	return (tab);
}
