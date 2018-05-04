/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboiron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 03:41:47 by cboiron           #+#    #+#             */
/*   Updated: 2017/03/11 04:49:52 by cboiron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char		*ft_fill_line(char *stock)
{
	int			i;
	char		*tmp;

	i = 0;
	while (stock[i] != '\n' && stock[i] != '\0')
		i++;
	tmp = ft_strsub(stock, 0, i);
	return (tmp);
}

static char		*ft_reduce_stock(char *stock)
{
	int			i;
	char		*tmp;

	i = 0;
	while (stock[i] != '\n' && stock[i] != '\0')
		i++;
	tmp = ft_strsub(stock, i + 1, ft_strlen(stock) - i);
	free(stock);
	return (tmp);
}

static char		*ft_joinbuff(char *stock, char *buffer)
{
	char		*tmp;

	tmp = ft_strjoin(stock, buffer);
	free(stock);
	stock = NULL;
	return (tmp);
}

int				get_next_line(const int fd, char **line)
{
	static char *stock;
	int			len;
	char		buffer[BUFF_SIZE + 1];

	if (fd < 0 || !&(*line))
		return (-1);
	len = 0;
	if (!stock)
		stock = ft_strnew(1);
	while (!(ft_strchr(stock, '\n')))
	{
		if ((len = read(fd, buffer, BUFF_SIZE)) == -1)
			return (-1);
		buffer[len] = '\0';
		if (!(stock = ft_joinbuff(stock, buffer)))
			return (-1);
		if (len == 0 && stock[0] == '\0')
			return (0);
		if (len == 0)
			break ;
	}
	*line = ft_fill_line(stock);
	if (!(*line) || !(stock = ft_reduce_stock(stock)))
		return (-1);
	return (1);
}
