/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_printing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboiron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 08:49:09 by cboiron           #+#    #+#             */
/*   Updated: 2017/04/11 02:19:38 by cboiron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			get_key_2(int key_code, t_env *env)
{
	if (key_code == 116)
		env->tiles_h += 1;
	if (key_code == 121)
		env->tiles_h -= 1;
	if (key_code == 115)
		env->tiles_w += 1;
	if (key_code == 119)
		env->tiles_w -= 1;
	if (key_code == 31)
		env->color++;
	redo(env);
	return (0);
}

int			get_key(int key_code, t_env *env)
{
	if (key_code == 53)
		exit(EXIT_SUCCESS);
	if (key_code == 12)
		env->red += 10;
	if (key_code == 13)
		env->green += 10;
	if (key_code == 14)
		env->blue += 10;
	if (key_code == 78)
		env->z += 0.1;
	if (key_code == 69)
		env->z -= 0.1;
	if (key_code == 8)
		env->persp = 1;
	if (key_code == 9)
		env->persp = 0;
	if (key_code == 37)
		env->color--;
	get_key_2(key_code, env);
	return (0);
}

void		put_pixel_to_image(t_env *env, int x, int y, int z)
{
	int		pos;

	pos = (x * (*env).bpp / 8) + ((y) * (*env).sizeline);
	if (x >= 0 && y >= 0 && x < WIDTH && y < HEIGHT)
	{
		env->data[pos] = env->red + (z * 2);
		env->data[pos + 1] = env->green + (z);
		env->data[pos + 2] = env->blue;
		env->data[pos + 3] = 0;
	}
}

void		image(t_env *env)
{
	int		x;
	int		y;
	t_pos	pos;

	x = 0;
	env->img = mlx_new_image(env->mlx, WIDTH, HEIGHT);
	env->data = mlx_get_data_addr(env->img, &(env->bpp), &(env->sizeline),
			&(env->endian));
	first_pixel(env);
	while (x < env->nb_line)
	{
		y = 0;
		while (y < env->size)
		{
			draw_iso(env, pos, x, y);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(env->mlx, env->win, env->img, 50, 50);
	mlx_destroy_image(env->mlx, env->img);
	print_info(env);
	mlx_hook(env->win, 2, 3, get_key, env);
	mlx_loop(env->mlx);
}

void		redo(t_env *env)
{
	int		x;
	int		y;
	t_pos	pos;

	x = 0;
	env->img = mlx_new_image(env->mlx, WIDTH, HEIGHT);
	env->data = mlx_get_data_addr(env->img, &(env->bpp), &(env->sizeline),
			&(env->endian));
	first_pixel(env);
	while (x < env->nb_line)
	{
		y = 0;
		while (y < env->size)
		{
			if (env->persp == 0)
				draw_iso(env, pos, x, y);
			else
				draw(env, pos, x, y);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(env->mlx, env->win, env->img, 50, 50);
	mlx_destroy_image(env->mlx, env->img);
	print_info(env);
}
