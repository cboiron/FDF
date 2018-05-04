/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raster.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboiron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 13:08:21 by cboiron           #+#    #+#             */
/*   Updated: 2017/04/10 02:47:48 by cboiron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw(t_env *env, t_pos pos, int x, int y)
{
	if (env->map[x + 1])
	{
		pos.xi = (y + (env->z / 2 * env->map[x][y])) * Y + MARGIN;
		pos.yi = (x + (env->z * env->map[x][y])) * X + MARGIN;
		pos.xj = (y + (env->z / 2 * env->map[x + 1][y])) * Y + MARGIN;
		pos.yj = (x + 1 + env->map[x + 1][y] * env->z) * X + MARGIN;
		raster(env, pos, (env->map[x][y] + env->map[x + 1][y]));
	}
	if (y < env->size && env->map[x][y + 1] != -2500000)
	{
		pos.xi = (y + (env->z / 2 * env->map[x][y])) * Y + MARGIN;
		pos.yi = (x + (env->z * env->map[x][y])) * X + MARGIN;
		pos.xj = (y + (1 + env->z / 2 * env->map[x][y + 1])) * Y + MARGIN;
		pos.yj = (x + (env->z * env->map[x][y + 1])) * X + MARGIN;
		raster(env, pos, (env->map[x][y + 1] + env->map[x][y]));
	}
}

void	draw_iso(t_env *env, t_pos pos, int x, int y)
{
	int	i;
	int	j;

	i = x * X + WIDTH / 2;
	j = y * Y + HEIGHT / 4;
	if (env->map[x + 1])
	{
		pos.xi = (-i + j) + HEIGHT;
		pos.yi = (j + i + env->map[x][y] * Y * env->z) / 2 - MARGIN;
		pos.xj = (-i - X + j) + HEIGHT;
		pos.yj = (j + X + i + env->map[x + 1][y] * Y * env->z) / 2 - MARGIN;
		raster(env, pos, (env->map[x][y] + env->map[x + 1][y]));
	}
	if (y < env->size && env->map[x][y + 1] != -2500000)
	{
		pos.xi = -i + j + HEIGHT;
		pos.yi = (i + j + env->map[x][y] * Y * env->z) / 2 - MARGIN;
		pos.xj = (-i + (j + Y)) + HEIGHT;
		pos.yj = (i + j + Y + env->map[x][y + 1] * Y * env->z) / 2 - MARGIN;
		raster(env, pos, (env->map[x][y + 1] + env->map[x][y]));
	}
}

void	raster2(t_env *env, t_pos pos, int z)
{
	int	i;
	int	cumul;

	cumul = pos.dx / 2;
	i = 1;
	while (i <= pos.dx && i < HEIGHT)
	{
		pos.x = pos.x + pos.xinc;
		cumul = cumul + pos.dy;
		if (cumul >= pos.dx)
		{
			cumul = cumul - pos.dx;
			pos.y = pos.y + pos.yinc;
		}
		put_pixel_to_image(env, pos.x, pos.y, z);
		i++;
	}
}

void	raster3(t_env *env, t_pos pos, int z)
{
	int	i;
	int	cumul;

	cumul = pos.dy / 2;
	i = 1;
	while (i <= pos.dy && i < HEIGHT)
	{
		pos.y = pos.y + pos.yinc;
		cumul = cumul + pos.dx;
		if (cumul >= pos.dy)
		{
			cumul = cumul - pos.dy;
			pos.x = pos.x + pos.xinc;
		}
		put_pixel_to_image(env, pos.x, pos.y, z);
		i++;
	}
}

void	raster(t_env *env, t_pos pos, int z)
{
	pos.x = pos.xi;
	pos.y = pos.yi;
	pos.dx = pos.xj - pos.xi;
	pos.dy = pos.yj - pos.yi;
	pos.xinc = (pos.dx > 0) ? 1 : -1;
	pos.yinc = (pos.dy > 0) ? 1 : -1;
	pos.dx = abs(pos.dx);
	pos.dy = abs(pos.dy);
	z = z * env->color;
	if (pos.dx > pos.dy)
		raster2(env, pos, z);
	else
		raster3(env, pos, z);
}
