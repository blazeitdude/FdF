/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   construct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldione <ldione@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 19:11:04 by ldione            #+#    #+#             */
/*   Updated: 2022/07/06 19:27:40 by ldione           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"
// static	void	show_matrix(t_map *map)
// {
// 	int		x;
// 	int		y;

// 	x = 0;
// 	y = 0;
// 	printf("-------матрица z---------\n");
// 	while(y < map->height)
// 	{
// 		while(x < map->width)
// 		{
// 			printf("%3d", map->matrix[y][x]);
// 			x++;
// 		}
// 		printf("\n");
// 		y++;
// 		x = 0;
// 	}
// 	x = 0;
// 	y = 0;
// 		printf("-------матрица цветов---------\n");
// 	while(y < map->height)
// 	{
// 		while(x < map->width)
// 		{
// 			printf("%i ", map->color[y][x]);
// 			x++;
// 		}
// 		printf("\n");
// 		y++;
// 		x = 0;
// 	}
// }

void	fill_matrix(char *line, int *map, int *color)
{
	int		x;
	int		i;
	char	**buff;
	int		numb;

	x = 0;
	buff = ft_split(line, ' ');
	while (buff[x])
	{
		i = 0;
		numb = ft_atoi(buff[x]);
		map[x] = numb;
		while (buff[x][i] != ',' && buff[x][i] != '\0')
			i++;
		if (buff[x][i] == ',')
			color[x] = ft_atox(&buff[x][i + 3]);
		else
			color[x] = -1;
		free(buff[x]);
		x++;
	}
	free(buff);
}

void	init_map(t_map *map, char *name)
{
	char	*line;
	int		x;
	int		fd;

	x = -1;
	fd = open(name, O_RDONLY);
	if (fd < 0)
		terminate(ERR_READING);
	init_map_height(map);
	while (++x < (map->height))
	{
		map->matrix[x] = (int *)ft_allocate((map->width + 1), sizeof(int));
		map->color[x] = (int *)ft_allocate((map->width + 1), sizeof(int));
	}
	line = get_next_line(fd);
	x = 0;
	while (line != NULL)
	{
		fill_matrix(line, map->matrix[x], map->color[x]);
		free(line);
		line = get_next_line(fd);
		x++;
	}
	free(line);
	ft_close(fd);
}

void	init_main_code(t_data *data)
{
	data->mlx_win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "FdF");
	if (!data->mlx_win)
		terminate(ERR_MLX_INIT);
	data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	if (!data->img)
		terminate(ERR_MLX_INIT);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, \
	&data->line_length, &data->endian);
	if (!data->addr)
		terminate(ERR_MLX_INIT);
}

t_camera	*init_camera(t_map *map)
{
	t_camera	*camera;

	camera = (t_camera *)ft_allocate(1, sizeof(t_camera));
	if (!camera)
		terminate(ERR_CAMERA_INIT);
	camera->zoom = find_min((WIDTH - MENU_WIDTH) / map->width / 2, \
	HEIGHT / map->height / 2);
	camera->z_divisor = 1;
	return (camera);
}

void	check_matrix(char *name)
{
	int		prev_len;
	int		next_len;
	char	*line;
	int		fd;

	fd = open(name, O_RDONLY);
	if (!fd)
		terminate(ERR_READING);
	line = get_next_line(fd);
	while (line != NULL)
	{
		prev_len = ft_wdcounter(line, ' ');
		free(line);
		line = get_next_line(fd);
		next_len = ft_wdcounter(line, ' ');
		if (next_len > 0 && (prev_len != next_len))
			terminate(ERR_OF_MAP);
	}
	ft_close(fd);
}
