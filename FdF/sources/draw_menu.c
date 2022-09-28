/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_menu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldione <ldione@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 16:08:49 by ldione            #+#    #+#             */
/*   Updated: 2022/07/06 19:59:26 by ldione           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

static void	draw_buttons(t_data *data)
{
	int	x_play;
	int	y_play;
	int	x_git;
	int	y_git;

	data->mlx_play = mlx_xpm_file_to_image(data->mlx, PLAY, &x_play, &y_play);
	data->mlx_git = mlx_xpm_file_to_image(data->mlx, GIT, &x_git, &y_git);
	mlx_put_image_to_window(data->mlx, data->mlx_start_win, \
	data->mlx_play, 900, 400);
	mlx_put_image_to_window(data->mlx, data->mlx_start_win, \
	data->mlx_git, 770, 550);
}

int	draw_start_menu(void *inp)
{
	t_data	*data;

	data = (t_data *)inp;
	init_start_mlx(data);
	draw_background(data, 1);
	mlx_put_image_to_window(data->mlx, data->mlx_start_win, \
	data->start_img, 0, 0);
	draw_buttons(data);
	mlx_hook(data->mlx_start_win, 17, 0, close_all, data);
	mlx_hook(data->mlx_start_win, 4, 0, mouse_press_start, data);
	mlx_hook(data->mlx_start_win, 5, 0, mouse_release, data);
	return (0);
}

void	draw_pepega(t_data *data)
{
	int	x;
	int	y;

	data->mlx_logo = mlx_xpm_file_to_image(data->mlx, PEPEGA, &x, &y);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->mlx_logo, 1825, 8);
}
