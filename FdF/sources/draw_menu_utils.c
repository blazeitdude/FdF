/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_menu_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldione <ldione@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 19:32:54 by ldione            #+#    #+#             */
/*   Updated: 2022/07/06 20:03:55 by ldione           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

static void	start_main_code(t_data *data)
{
	data->camera = init_camera(data->map);
	init_main_code(data);
	controls(data);
	draw_map(data);
}

static void	close_start(t_data *data)
{
	mlx_destroy_window(data->mlx, data->mlx_start_win);
	mlx_destroy_image(data->mlx, data->start_img);
	mlx_destroy_image(data->mlx, data->mlx_play);
	mlx_destroy_image(data->mlx, data->mlx_git);
	ft_bzero(data->addr, WIDTH * HEIGHT * (data->bits_per_pixel / 8));
	start_main_code(data);
}

int	mouse_press_start(int button, int x, int y, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if ((x > 900 && x < 900 + PLAY_WIDTH) && \
	(y > 400 && y < 400 + PLAY_HEIGHT) && button == MOUSE_LEFT_BUTTON)
		close_start(data);
	if ((x > 770 && x < 770 + GIT_WIDTH) && \
	(y > 550 && y < 550 + GIT_HEIGHT) && button == MOUSE_LEFT_BUTTON)
		system("open ./includes/blazeitdude_GIT.mht");
	return (0);
}

void	init_start_mlx(t_data *data)
{
	data->mlx = mlx_init();
	data->mouse = (t_mouse *)ft_allocate(1, sizeof(t_mouse));
	data->mlx_start_win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "FdF");
	if (!data->mlx_start_win)
		terminate(ERR_MLX_INIT);
	data->start_img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	if (!data->start_img)
		terminate(ERR_MLX_INIT);
	data->addr = mlx_get_data_addr(data->start_img, &data->bits_per_pixel, \
	&data->line_length, &data->endian);
	if (!data->addr)
		terminate(ERR_MLX_INIT);
}
