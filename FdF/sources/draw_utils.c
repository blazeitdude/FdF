/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldione <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 20:11:51 by ldione            #+#    #+#             */
/*   Updated: 2022/05/04 14:56:44 by ldione           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "functions.h"

void	iso(int *x, int *y, int z)
{
	int	pre_x;
	int	pre_y;

	pre_x = *x;
	pre_y = *y;
	*x = (pre_x - pre_y) * cos(0.523599);
	*y = -z + (pre_x + pre_y) * sin(0.523599);
}

void	rotate_x(int *y, int *z, float alpha)
{
	int	pre_y;

	pre_y = *y;
	*y = pre_y * cos(alpha) + *z * sin(alpha);
	*z = -pre_y * sin(alpha) + *z * cos(alpha);
}

void	rotate_y(int *x, int *z, float beta)
{
	int	pre_x;

	pre_x = *x;
	*x = pre_x * cos(beta) + *z * sin(beta);
	*z = -pre_x * sin(beta) + *z * cos(beta);
}

void	rotate_z(int *x, int *y, float gamma)
{
	int	pre_x;
	int	pre_y;

	pre_x = *x;
	pre_y = *y;
	*x = pre_x * cos(gamma) - pre_y * sin(gamma);
	*y = pre_x * sin(gamma) + pre_y * cos(gamma);
}

void	ft_mlx_string_put(void *mlx, void *mlx_win, int y)
{
	mlx_string_put(mlx, mlx_win, 65, y += 20, TEXT_COLOR, "-How to use-");
	mlx_string_put(mlx, mlx_win, 15, y += 35, TEXT_COLOR, "Zoom: mouse wheel");
	mlx_string_put(mlx, mlx_win, 15, y += 30, TEXT_COLOR, "Move: arrows");
	mlx_string_put(mlx, mlx_win, 15, y += 30, TEXT_COLOR, "Stab: <>");
}
