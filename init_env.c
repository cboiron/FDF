/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboiron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 02:39:49 by cboiron           #+#    #+#             */
/*   Updated: 2017/04/10 04:44:19 by cboiron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	first_pixel(t_env *env)
{
	int	z;

	z = env->map[0][0];
	if (env->map[0][1])
		z = z + env->map[0][1];
	z = z * env->color;
	if (env->persp == 0)
	{
		put_pixel_to_image(env, -WIDTH / 2 + HEIGHT + HEIGHT / 4,
				(HEIGHT / 4 + WIDTH / 2 + env->map[0][0] * Y * env->z) / 2
				- MARGIN, z);
	}
	else
	{
		put_pixel_to_image(env, env->z / 2 * env->map[0][0] * Y + MARGIN,
				env->z * env->map[0][0] * X + MARGIN, z);
	}
}

void	free_map_char(char ***map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			free(map[i][j++]);
		}
		free(map[i++]);
	}
}

void	free_map(int **map)
{
	int	i;

	i = 0;
	while (map[i] != NULL)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

t_env	*init_env(void)
{
	t_env	*env;

	env = malloc(sizeof(t_env));
	env->mlx = NULL;
	(*env).win = NULL;
	(*env).img = NULL;
	(*env).map = NULL;
	(*env).size = -10;
	(*env).nb_line = -10;
	(*env).endian = 0;
	(*env).bpp = 0;
	(*env).sizeline = 0;
	(*env).red = 255;
	(*env).green = 255;
	(*env).blue = 255;
	(*env).data = NULL;
	(*env).z = -0.1;
	(*env).tiles_h = 0;
	(*env).tiles_w = 0;
	(*env).persp = 0;
	(*env).color = 1;
	return (env);
}
