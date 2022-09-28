/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_control_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldione <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 21:30:12 by ldione            #+#    #+#             */
/*   Updated: 2022/04/28 21:30:14 by ldione           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "functions.h"

void	zoom(int key, t_data *data)
{
	if (key == NUM_PAD_PLUS || \
	key == MAIN_PAD_PLUS || \
	key == MOUSE_SCROLL_UP)
		data->camera->zoom++;
	else if (key == NUM_PAD_MINUS || \
	key == MAIN_PAD_MINUS || \
	key == MOUSE_SCROLL_DOWN)
		data->camera->zoom--;
	if (data->camera->zoom < 1)
		data->camera->zoom = 1;
	draw_map(data);
}

void	move(int key, t_data *data)
{
	if (key == ARROW_LEFT)
		data->camera->x_offset -= 10;
	else if (key == ARROW_RIGHT)
		data->camera->x_offset += 10;
	else if (key == ARROW_UP)
		data->camera->y_offset -= 10;
	else
		data->camera->y_offset += 10;
	draw_map(data);
}

void	rotate(int key, t_data *data)
{
	if (key == NUM_PAD_2 || key == MAIN_PAD_2)
		data->camera->alpha += 0.05;
	else if (key == NUM_PAD_8 || key == MAIN_PAD_8)
		data->camera->alpha -= 0.05;
	else if (key == NUM_PAD_4 || key == MAIN_PAD_4)
		data->camera->beta -= 0.05;
	else if (key == NUM_PAD_6 || key == MAIN_PAD_6)
		data->camera->beta += 0.05;
	else if (key == NUM_PAD_1 || key == MAIN_PAD_1 \
	|| key == NUM_PAD_3 || key == MAIN_PAD_3)
		data->camera->gamma += 0.05;
	else if (key == NUM_PAD_7 || key == MAIN_PAD_7 \
	|| key == NUM_PAD_9 || key == MAIN_PAD_9)
		data->camera->gamma -= 0.05;
	draw_map(data);
}

void	flatten(int key, t_data *data)
{
	if (key == MAIN_PAD_LESS)
		data->camera->z_divisor -= 0.1;
	else if (key == MAIN_PAD_MORE)
		data->camera->z_divisor += 0.1;
	if (data->camera->z_divisor < 0.1)
		data->camera->z_divisor = 0.1;
	else if (data->camera->z_divisor > 10)
		data->camera->z_divisor = 10;
	draw_map(data);
}

void	change_projection(int key, t_data *data)
{
	data->camera->alpha = 0;
	data->camera->beta = 0;
	data->camera->gamma = 0;
	if (key == MAIN_PAD_I)
		data->camera->projection = ISO;
	else if (key == MAIN_PAD_P)
		data->camera->projection = PARALLEL;
	draw_map(data);
}
