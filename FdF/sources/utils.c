/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldione <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 19:08:13 by ldione            #+#    #+#             */
/*   Updated: 2022/04/19 19:08:16 by ldione           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

void	*ft_allocate(size_t num, size_t size)
{
	void	*out;

	out = malloc(size * num);
	if (!out)
		terminate(ERR_OF_ALLOC);
	ft_bzero(out, num * size);
	return (out);
}

void	gwh(t_map *map, char *name)
{
	int		fd;
	char	*line;

	fd = open(name, O_RDONLY);
	if (fd < 0)
		terminate(ERR_READING);
	map->height = 0;
	line = get_next_line(fd);
	map->width = ft_wdcounter(line, ' ');
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		map->height += 1;
	}
	ft_close(fd);
	free(line);
}

void	terminate(char *s)
{
	ft_putendl_fd(s, 1);
	exit(1);
}

int	find_min(int a, int b)
{
	if (a > b)
		return (b);
	else
		return (a);
}

int	find_max(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}
