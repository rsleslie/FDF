/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleslie- <rleslie-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 16:00:07 by rleslie-          #+#    #+#             */
/*   Updated: 2023/01/27 15:10:11 by rleslie-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	bresenham(t_fdf *data, t_score point)
{
	float	dx;
	float	dy;
	int		max;
	int		z;
	int		z1;

	z = data->z_matrix[(int)point.y][(int)point.x];
	z1 = data->z_matrix[(int)point.y1][(int)point.x1];
	data->color = data->z_color[(int)point.y][(int)point.x];
	zoom(data, &point);
	isometric(&point.x, &point.y, z);
	isometric(&point.x1, &point.y1, z1);
	dx = point.x1 - point.x;
	dy = point.y1 - point.y;
	ft_shift(data, &point);
	max = ft_max(fabsf(dx), fabsf(dy));
	dx /= max;
	dy /= max;
	while ((int)(point.x - point.x1) || (int)(point.y - point.y1))
	{
		my_mlx_pixel_put(data, point.x, point.y, data->color);
		point.x += dx;
		point.y += dy;
	}
}

void	var_init(int x, int y, int flag, t_fdf *data)
{
	t_score	point;

	point.x = x;
	point.y = y;
	if (flag == 1)
	{
		point.x1 = x + 1;
		point.y1 = y;
	}
	else
	{
		point.y1 = y + 1;
		point.x1 = x;
	}
	bresenham(data, point);
}

void	draw(t_fdf *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			if (x < data->width - 1)
				var_init(x, y, 1, data);
			if (y < data->height - 1)
				var_init(x, y, 0, data);
			x++;
		}
			y++;
	}
}
