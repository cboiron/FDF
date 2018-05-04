/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboiron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 05:13:16 by cboiron           #+#    #+#             */
/*   Updated: 2017/04/10 05:54:00 by cboiron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		print_info(t_env *env)
{
	mlx_string_put(env->mlx, env->win, 50, 25, 0x0FFFFFF,
			"CONTROLS ---------------------------------");
	mlx_string_put(env->mlx, env->win, 50, 50, 0x0FFFFFF,
			"Press Q W E to modify red, green and blue");
	mlx_string_put(env->mlx, env->win, 50, 75, 0x0FFFFFF,
			"Press C for parallel view, V for iso");
	mlx_string_put(env->mlx, env->win, 50, 100, 0x0FFFFFF,
			"Press O and L for funny colors");
	mlx_string_put(env->mlx, env->win, 50, 125, 0x0FFFFFF,
			"home/end     to increase/decrease tiles height");
	mlx_string_put(env->mlx, env->win, 50, 150, 0x0FFFFFF,
			"page up/down to increase/decrease tiles width");
	mlx_string_put(env->mlx, env->win, 50, 175, 0x0FFFFFF,
			"+/- to change depth");
	mlx_string_put(env->mlx, env->win, 50, 200, 0x0FFFFFF,
			"ESACPE to quit");
}

int			checker(int fd, char **line, char **argv)
{
	int		i;

	i = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd <= -1)
	{
		ft_putstr("invalid file\n");
		exit(EXIT_FAILURE);
	}
	while (get_next_line(fd, line) > 0)
	{
		i++;
		free(*line);
	}
	close(fd);
	return (i);
}
