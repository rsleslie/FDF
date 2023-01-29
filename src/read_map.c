/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleslie- <rleslie-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 16:00:17 by rleslie-          #+#    #+#             */
/*   Updated: 2023/01/29 18:20:30 by rleslie-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	inc_matrix(t_fdf *data, char *str1, int y, int x)
{
    int i;
	char	**value_two;
	
    i = 0;
	if (ft_strchr(str1, ',') && str1)
	{
		value_two = ft_split(str1, ',');
		data->z_matrix[y][x] = ft_atoi(value_two[0]);
		data->z_color[y][x] = ft_hex_atoi(value_two[1], \
		"0123456789abcdef", 2);
        free(value_two[0]);
        free(value_two);
	}
	else
	{
		data->z_matrix[y][x] = ft_atoi(str1);
		data->z_color[y][x] = 0xff00;
	}
}

void	value_matrix(t_fdf *data, char *file_name, int x, int y)
{
	char	**value_one;
	int		fd;
	char	*line;
	
	fd = open(file_name, O_RDONLY, 0);
	line = get_next_line(fd);
	value_one = ft_split(line, ' ');
	y = 0;
	while (line)
	{
		x = 0;
		while (x < data->width)
		{
			inc_matrix(data, value_one[x], y, x);
			x++;
		}
        free(line);
        x = 0;
        while(value_one[x])
            free(value_one[x++]);
        free(value_one);
		line = get_next_line(fd);
        x = 0;
		if (line)
			value_one = ft_split(line, ' ');
		y++;
	}
}

int	get_heigth(char *file_name)
{
	int	fd;
	int	height;
    char *line;

	fd = open(file_name, O_RDONLY, 0);
	height = 0;
    line = get_next_line(fd);
	while (line)
    {
        height++;
        if (line)
            free(line);
        line = get_next_line(fd);
    }
    free(line);
	close(fd);
	return (height);
}

int	get_width(char *file_name)
{
	int		fd;
	int		width;
	char	*line;

	fd = open(file_name, O_RDONLY, 0);
	line = get_next_line(fd);
	width = ft_counter(line, ' ');
	free(line);
	close(fd);
	return (width);
}

void	read_file(char *file_name, t_fdf *data, int arg)
{
	int	i;
	int	y;

	y = 0;
	data->height = get_heigth(file_name);
	data->width = get_width(file_name);
	data->z_matrix = (int **)malloc(sizeof(int *) * (data->height));
	i = 0;
	while (i < data->height && arg)
		data->z_matrix[i++] = (int *)malloc(sizeof(int) * (data->width));
	data->z_color = (int **)malloc(sizeof(int *) * (data->height));
	i = 0;
	while (i < data->height && arg)
		data->z_color[i++] = (int *)malloc(sizeof(int) * (data->width));
	value_matrix(data, file_name, i, y);
}
