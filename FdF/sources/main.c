/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldione <ldione@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 18:59:43 by ldione            #+#    #+#             */
/*   Updated: 2022/07/06 20:04:02 by ldione           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

int	main(int argc, char **argv)
{
	t_data	*data;

	data = (t_data *)ft_allocate(1, sizeof(*data));
	data->map = (t_map *)ft_allocate(1, sizeof(*data->map));
	if (argc != 2)
		terminate(ERR_OF_ARGUMENT);
	gwh(data->map, argv[1]);
	check_matrix(argv[1]);
	init_map(data->map, argv[1]);
	min_max_z(data->map);
	draw_start_menu(data);
	mlx_loop(data->mlx);
}
