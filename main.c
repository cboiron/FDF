/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboiron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 05:23:15 by cboiron           #+#    #+#             */
/*   Updated: 2017/04/10 07:05:54 by cboiron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			get_length(char ***map_char, int size)
{
	int		j;
	int		i;
	int		line_size;

	i = 1;
	j = 0;
	if (map_char[0] == NULL)
		exit(EXIT_FAILURE);
	while (map_char[0][j])
		j++;
	line_size = j;
	while (i < size)
	{
		j = 0;
		while (map_char[i][j])
			j++;
		if (line_size != j)
		{
			ft_putstr("invalid map \n");
			exit(EXIT_FAILURE);
		}
		i++;
	}
	return (j);
}

int			**create_map(int size, char ***map_char)
{
	int		i;
	int		length;
	int		**map;

	length = get_length(map_char, size);
	i = 0;
	if (!(map = (int **)malloc(sizeof(map) * size + 1)))
		return (NULL);
	while (i < size)
	{
		if (!(map[i] = (int *)malloc(sizeof(map[i]) * length + 1)))
			return (NULL);
		i++;
	}
	return (map);
}

int			**map_char_to_int(int size, char ***map_char, int line_size)
{
	int		i;
	int		j;
	int		**map;

	i = 0;
	if (!(map = create_map(size, map_char)))
		exit(EXIT_FAILURE);
	while (i < size)
	{
		j = 0;
		while (j < line_size)
		{
			map[i][j] = ft_atoi(map_char[i][j]);
			j++;
		}
		map[i][j] = -2500000;
		i++;
	}
	map[i] = NULL;
	return (map);
}

int			**get_map(int fd, char **line, t_env **env, char **argv)
{
	char	***map_char;
	int		**map;
	int		i;

	i = 0;
	(*env)->nb_line = checker(fd, line, argv);
	if (!(map_char = malloc(sizeof(char**) * ((*env)->nb_line + 1))))
		exit(EXIT_FAILURE);
	fd = open(argv[1], O_RDONLY);
	while (get_next_line(fd, line) > 0)
	{
		map_char[i++] = ft_strsplit(*line, ' ');
		free(*line);
	}
	close(fd);
	map_char[i] = NULL;
	(*env)->size = get_length(map_char, i);
	map = map_char_to_int(i, map_char, (*env)->size);
	free_map_char(map_char);
	free(map_char);
	return (map);
}

int			main(int argc, char **argv)
{
	int		fd;
	char	*line;
	t_env	*env;

	line = NULL;
	fd = 0;
	env = init_env();
	if (argc == 2)
	{
		env->mlx = mlx_init();
		env->win = mlx_new_window(env->mlx, WIDTH, HEIGHT, "FDF");
		env->map = get_map(fd, &line, &env, argv);
		env->tiles_h = HEIGHT / (env->nb_line * 2);
		env->tiles_w = WIDTH / (env->size * 2);
		if (env->map)
		{
			image(env);
			free_map(env->map);
		}
	}
	free(env);
	return (0);
}
