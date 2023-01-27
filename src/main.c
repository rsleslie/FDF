/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleslie- <rleslie-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 16:00:11 by rleslie-          #+#    #+#             */
/*   Updated: 2023/01/27 17:55:02 by rleslie-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	main(int argc, char **argv)
{
	t_fdf	data;

	data.mlx_ptr = mlx_init();
	data.win_ptr = mlx_new_window(data.mlx_ptr, 900, 600, "FDF");
	data.img = mlx_new_image(data.mlx_ptr, 900, 600);
	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel, \
	&data.line_length, &data.endian);
	read_file(argv[1], &data, argc);
	data.zoom = 600 / sqrt(pow(data.width, 2) + pow(data.height, 2));
	data.shift_x = 350;
	data.shift_y = 150;
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, close_esc, &data);
	mlx_hook(data.win_ptr, DestroyNotify, NoEventMask, close_x, &data);
	draw(&data);
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.img, 0, 0);
	mlx_loop(data.mlx_ptr);
	return (0);
}
