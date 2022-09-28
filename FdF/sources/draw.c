/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldione <ldione@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 19:10:57 by ldione            #+#    #+#             */
/*   Updated: 2022/07/06 19:19:39 by ldione           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

void	draw_background(t_data *data, int flag)
{
	int	*img;
	int	i;

	ft_bzero(data->addr, WIDTH * HEIGHT * (data->bits_per_pixel / 8));
	img = (int *)(data->addr);
	i = 0;
	if (flag == 0)
	{
		while (i < HEIGHT * WIDTH)
		{
			if (i % WIDTH < MENU_WIDTH && i / HEIGHT < MENU_HEIGHT)
				img[i] = MENU_BACKGROUND;
			else
				img[i] = BACKGROUND;
			i++;
		}
	}
	else
	{
		while (i < HEIGHT * WIDTH)
				img[i++] = START_BACKGROUND;
	}
}

void	draw_point(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x < WIDTH - 1 && y <= HEIGHT - 1 && x >= 0 \
	&& y >= 0 && (x >= MENU_WIDTH || y >= 225))
	{
		dst = data->addr + (y * data->line_length \
		+ x * (data->bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}

void	draw_line(t_data *data, t_inp from, t_inp to)
{
	t_inp	delta;
	t_inp	sign;
	t_inp	cur;
	int		error[2];

	delta.x = abs(to.x - from.x);
	delta.y = abs(to.y - from.y);
	error[0] = delta.x - delta.y;
	sign_check(&from, &to, &sign);
	cur = from;
	while (cur.x != to.x || cur.y != to.y)
	{
		draw_point(data, cur.x, cur.y, get_color(cur, from, to, delta));
		error[1] = error[0] * 2;
		if (error[1] > -delta.y)
		{
			error[0] -= delta.y;
			cur.x += sign.x;
		}
		if (error[1] < delta.x)
		{
			error[0] += delta.x;
			cur.y += sign.y;
		}
	}
}

static void	draw_menu(t_data *data)
{
	int		y;
	void	*mlx;
	void	*mlx_win;

	y = 0;
	mlx = data->mlx;
	mlx_win = data->mlx_win;
	mlx_string_put(mlx, mlx_win, 15, y += 30, \
	TEXT_COLOR, "Cool rotate: push and rotate");
	mlx_string_put(mlx, mlx_win, 15, y += 25, \
	TEXT_COLOR, "Rotate from X coordinate: 2 or 8");
	mlx_string_put(mlx, mlx_win, 15, y += 25, \
	TEXT_COLOR, "Rotate from Y coordinate: 4 or 6");
	mlx_string_put(mlx, mlx_win, 15, y += 25, \
	TEXT_COLOR, "Rotate from Z coordinate: 1 or 7");
	mlx_string_put(mlx, mlx_win, 15, y += 30, \
	TEXT_COLOR, "-Projection-");
	mlx_string_put(mlx, mlx_win, 15, y += 25, \
	TEXT_COLOR, "ISO: I on keyboard");
	mlx_string_put(mlx, mlx_win, 15, y += 25, \
	TEXT_COLOR, "Parallel: P on keyboard");
}

void	draw_map(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	draw_background(data, 0);
	while (y < data->map->height)
	{
		x = 0;
		while (x < data->map->width)
		{
			if (x != data->map->width - 1)
				draw_line(data, inp_addition(data, \
				create_inp(data->map, x, y)), \
				inp_addition(data, create_inp(data->map, x + 1, y)));
			if (y != data->map->height - 1)
				draw_line(data, inp_addition(data, \
				create_inp(data->map, x, y)), \
				inp_addition(data, create_inp(data->map, x, y + 1)));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
	draw_menu(data);
	draw_pepega(data);
}
