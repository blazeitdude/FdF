/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work_with_colors.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldione <ldione@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 20:56:47 by ldione            #+#    #+#             */
/*   Updated: 2022/07/06 18:28:13 by ldione           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

int	get_default_color(int z, t_map *map)
{
	double	percentage;

	percentage = get_percent(map->z_min, map->z_max, z);
	if (percentage < 0.2)
		return (COLOR_DISCO);
	else if (percentage < 0.4)
		return (COLOR_BRICK_RED);
	else if (percentage < 0.6)
		return (COLOR_FLAMINGO);
	else if (percentage < 0.8)
		return (COLOR_JAFFA);
	else
		return (COLOR_SAFFRON);
}

int	get_light(int start, int end, double perc)
{
	return ((int)((1 - perc) * start + perc * end));
}

int	get_color(t_inp cur, t_inp start, t_inp end, t_inp delta)
{
	int		red;
	int		green;
	int		blue;
	double	perc;

	if (cur.color == end.color)
		return (cur.color);
	if (delta.x > delta.y)
		perc = get_percent(start.x, end.x, cur.x);
	else
		perc = get_percent(start.y, end.y, cur.y);
	red = get_light((start.color >> 16) & 0xFF,
			(end.color >> 16) & 0xFF, perc);
	green = get_light((start.color >> 8) & 0xFF,
			(end.color >> 8) & 0xFF, perc);
	blue = get_light(start.color & 0xFF, end.color & 0xFF, perc);
	return ((red << 16) | (green << 8) | blue);
}
