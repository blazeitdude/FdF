/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldione <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 21:25:50 by ldione            #+#    #+#             */
/*   Updated: 2022/04/28 21:25:53 by ldione           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "functions.h"

int	close_all(void *param)
{
	(void)param;
	exit(0);
}

void	controls(t_data *data)
{
	mlx_hook(data->mlx_win, 2, 0, key_press, data);
	mlx_hook(data->mlx_win, 17, 0, close_all, data);
	mlx_hook(data->mlx_win, 4, 0, mouse_press, data);
	mlx_hook(data->mlx_win, 5, 0, mouse_release, data);
	mlx_hook(data->mlx_win, 6, 0, mouse_move, data);
}

int	key_press(int key, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (key == MAIN_PAD_ESC)
		exit(0);
	if (key == NUM_PAD_PLUS || key == MAIN_PAD_PLUS
		|| key == NUM_PAD_MINUS || key == MAIN_PAD_MINUS)
		zoom(key, data);
	else if (key == ARROW_LEFT || key == ARROW_RIGHT \
	|| key == ARROW_UP || key == ARROW_DOWN)
		move(key, data);
	else if (key == NUM_PAD_1 || key == MAIN_PAD_1 \
	|| key == NUM_PAD_2 || key == MAIN_PAD_2 \
	|| key == NUM_PAD_3 || key == MAIN_PAD_3 \
	|| key == NUM_PAD_4 || key == MAIN_PAD_4 \
	|| key == NUM_PAD_6 || key == MAIN_PAD_6 \
	|| key == NUM_PAD_7 || key == MAIN_PAD_7 \
	|| key == NUM_PAD_8 || key == MAIN_PAD_8 \
	|| key == NUM_PAD_9 || key == MAIN_PAD_9)
		rotate(key, data);
	else if (key == MAIN_PAD_LESS || key == MAIN_PAD_MORE)
		flatten(key, data);
	else if (key == MAIN_PAD_P || key == MAIN_PAD_I)
		change_projection(key, data);
	return (0);
}
