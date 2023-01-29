/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleslie- <rleslie-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 15:10:19 by rleslie-          #+#    #+#             */
/*   Updated: 2023/01/29 17:56:56 by rleslie-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	ft_max(float a, float b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

void    ft_free(t_fdf *data)
{
	int i;

	i = 0;
	while(i < data->height && data->z_matrix[i] && data->z_color[i])
	{
		free(data->z_matrix[i]);
		free(data->z_color[i]);
		i++;
	}
    if (data->z_matrix)
	    free(data->z_matrix);
    if (data->z_color)
	    free(data->z_color);
}

void	ft_shift(t_fdf *data, t_score *point)
{
	point->x += data->shift_x;
	point->x1 += data->shift_x;
	point->y += data->shift_y;
	point->y1 += data->shift_y;
}

void	zoom(t_fdf *data, t_score *point)
{
	point->x *= data->zoom;
	point->x1 *= data->zoom;
	point->y *= data->zoom;
	point->y1 *= data->zoom;
}

int	ft_hex_atoi(char *num, char *hex, int x)
{
	int		i;
	int		size_num;
	int		value_dec;
	
	size_num = ft_strlen(num) - x;
	num = ft_conversion_isalpha(num);
	value_dec = 0;
	while (num[x] != '\0')
	{
		i = 0;
		while (hex[i] != '\0')
		{
			if (hex[i] == num[x])
			{
				size_num = size_num - 1;
				value_dec += i * pow(16, size_num);
			}
			i++;
		}
		x++;
	}
	free(num);
	return (value_dec);
}

char	*ft_conversion_isalpha(char *num)
{
	int		i;
	char	*new_num;

	new_num = (char *)malloc(sizeof(char) * ft_strlen(num) + 1);
	if(!new_num)
		return(NULL);
	new_num[ft_strlen(num)] = '\0';
	i = 0;
	while (num[i] != '\0')
	{
		new_num[i] = num[i];
		if (ft_isalpha(num[i]))
		{
			if (num[i] >= 65 && num[i] <= 70)
				new_num[i] = num[i] + 32;
		}
		i++;
	}
	free(num);
	return (new_num);
}
