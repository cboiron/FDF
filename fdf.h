/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboiron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 21:05:10 by cboiron           #+#    #+#             */
/*   Updated: 2017/04/10 05:56:36 by cboiron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define HEIGHT 1500
# define WIDTH 2000
# define X env->tiles_h
# define Y env->tiles_w
# define Z 0.8
# define MARGIN 300

# include "libft/libft.h"
# include "mlx.h"
# include <fcntl.h>
# include <math.h>

typedef struct	s_pos
{
	int			xi;
	int			xj;
	int			yi;
	int			yj;
	int			dx;
	int			dy;
	int			xinc;
	int			yinc;
	int			x;
	int			y;
}				t_pos;

typedef struct	s_env
{
	void		*mlx;
	void		*win;
	void		*img;
	int			**map;
	int			nb_line;
	int			size;
	int			endian;
	int			bpp;
	int			sizeline;
	int			red;
	int			green;
	int			blue;
	int			tiles_h;
	int			tiles_w;
	int			persp;
	int			color;
	float		z;
	char		*data;
}				t_env;

t_env			*init_env(void);
void			free_map(int **map);
void			free_map_char(char ***map);
void			printing(t_env *env);
void			printing_iso(t_env *env);
void			image(t_env *env);
void			redo(t_env *env);
void			draw(t_env *env, t_pos pos, int x, int y);
void			draw_iso(t_env *env, t_pos pos, int x, int y);
void			put_pixel_to_image(t_env *env, int x, int y, int z);
void			raster(t_env *env, t_pos pos, int z);
void			first_pixel(t_env *env);
void			print_info(t_env *env);
int				checker(int fd, char **line, char **argv);
#endif
