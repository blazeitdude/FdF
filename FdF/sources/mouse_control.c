/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_control.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldione <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 22:26:52 by ldione            #+#    #+#             */
/*   Updated: 2022/04/28 22:26:54 by ldione           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "functions.h"

int	mouse_press(int button, int x, int y, void *param)
{
	t_data	*data;

	(void)x;
	(void)y;
	data = (t_data *)param;
	if (button == MOUSE_SCROLL_UP || button == MOUSE_SCROLL_DOWN)
		zoom(button, data);
	else if (button == MOUSE_LEFT_BUTTON)
		data->mouse->is_pressed = true;
	return (0);
}

int	mouse_release(int button, int x, int y, void *param)
{
	t_data	*data;

	(void)x;
	(void)y;
	(void)button;
	data = (t_data *)param;
	data->mouse->is_pressed = false;
	return (0);
}

int	mouse_move(int x, int y, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	data->mouse->previous_x = data->mouse->x;
	data->mouse->previous_y = data->mouse->y;
	data->mouse->x = x;
	data->mouse->y = y;
	if (data->mouse->is_pressed)
	{
		data->camera->alpha += (x - data->mouse->previous_x) * 0.002;
		data->camera->beta += (y - data->mouse->previous_y) * 0.002;
		draw_map(data);
	}
	return (0);
}
