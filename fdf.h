/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleslie- <rleslie-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 16:02:57 by rleslie-          #+#    #+#             */
/*   Updated: 2023/01/29 18:21:00 by rleslie-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/libft.h"
# include <mlx.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <math.h>

typedef struct s_fdf
{
	float	zoom;
	char	*addr;
	void	*img;
	void	*mlx_ptr;
	void	*win_ptr;
	int		**z_matrix;
	int		**z_color;
	int		width;
	int		height;
	int		color;
	int		shift_x;
	int		shift_y;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_fdf;

typedef struct s_score
{
	float	x;
	float	y;
	float	x1;
	float	y1;
}	t_score;

void	my_mlx_pixel_put(t_fdf*data, int x, int y, int color);
void	my_mlx_pixel_put(t_fdf*data, int x, int y, int color);
void	read_file(char *file_name, t_fdf*data, int arg);
void	bresenham(t_fdf*data, t_score point);
void	zoom(t_fdf *data, t_score *point);
void	ft_shift(t_fdf *data, t_score *point);
void	isometric(float *x, float *y, int z);
int		ft_max(float a, float b);
void	draw(t_fdf*data);
int		close_x(t_fdf*data);
int		close_esc(int keysym, t_fdf*data);
int		ft_hex_atoi(char *num, char *hex, int x);
char	*ft_conversion_isalpha(char *num);
void	isometric(float *x, float *y, int z);
void    ft_free(t_fdf *data);

#endif
