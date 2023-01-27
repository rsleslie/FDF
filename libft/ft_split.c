/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleslie- <rleslie-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 03:10:29 by coder             #+#    #+#             */
/*   Updated: 2023/01/27 18:46:27 by rleslie-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_create(char const *s, char c, size_t index)
{
	char		**list;
	char const	*start;
	char const	*end;

	start = s;
	while (*start && *start == c)
		start++;
	if (*start == '\0')
		return ((char **)ft_calloc(index + 1, sizeof(char *)));
	end = start;
	while (*end && *end != c)
		end++;
	list = ft_create(end, c, index + 1);
	if (!list)
		return (list);
	list[index] = ft_substr(start, 0, end - start);
	if (!list[index])
	{
		while (list[index])
		{
			list[index] = NULL;
			free(list[index++]);
		}
	}
	return (list);
}

char	**ft_split(char const *s, char c)
{
	return (ft_create(s, c, 0));
}
