/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldione <ldione@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 20:08:05 by ldione            #+#    #+#             */
/*   Updated: 2022/07/06 18:54:23 by ldione           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

int	get_index(int x, int y, int width)
{
	return (y * width + x);
}

double	get_percent(int start, int end, int cur)
{
	double	place;
	double	dist;

	place = cur - start;
	dist = end - start;
	if (dist == 0)
		return (1.0);
	else
		return (place / dist);
}

t_inp	create_inp(t_map *map, int x, int y)
{
	t_inp	out;

	out.x = x;
	out.y = y;
	out.z = map->matrix[y][x];
	if (map->color[y][x] == -1)
		out.color = get_default_color(out.z, map);
	else
		out.color = map->color[y][x];
	return (out);
}

t_inp	inp_addition(t_data *data, t_inp inp)
{
	inp.x *= data->camera->zoom;
	inp.y *= data->camera->zoom;
	inp.z *= data->camera->zoom / data->camera->z_divisor;
	inp.x -= (data->map->width * data->camera->zoom) / 2;
	inp.y -= (data->map->height * data->camera->zoom) / 2;
	rotate_x(&inp.x, &inp.z, data->camera->alpha);
	rotate_y(&inp.y, &inp.z, data->camera->beta);
	rotate_z(&inp.x, &inp.y, data->camera->gamma);
	if (data->camera->projection == ISO)
		iso(&inp.x, &inp.y, inp.z);
	inp.x += (WIDTH - MENU_WIDTH) / 2 \
	+ data->camera->x_offset + MENU_WIDTH;
	inp.y += (HEIGHT + data->map->height * data->camera->zoom) \
	/ 2 + data->camera->y_offset;
	return (inp);
}

void	ft_close(int fd)
{
	if (close (fd) < 0)
		terminate(ERR_OF_CLOSE);
}
