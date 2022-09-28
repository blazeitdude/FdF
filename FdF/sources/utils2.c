/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldione <ldione@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 14:29:51 by ldione            #+#    #+#             */
/*   Updated: 2022/07/06 18:54:51 by ldione           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

void	init_map_height(t_map *map)
{
	map->matrix = (int **)ft_allocate((map->height + 1), sizeof(int *));
	map->color = (int **)ft_allocate((map->height + 1), sizeof(int *));
}

void	sign_check(t_inp *from, t_inp *to, t_inp *sign)
{
	if (from->x < to->x)
		sign->x = 1;
	else
		sign->x = -1;
	if (from->y < to->y)
		sign->y = 1;
	else
		sign->y = -1;
}

void	min_max_z(t_map *map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (map->matrix[y][x] > map->z_max)
				map->z_max = map->matrix[y][x];
			if (map->matrix[y][x] < map->z_min)
				map->z_min = map->matrix[y][x];
			x++;
		}
		y++;
	}
}
