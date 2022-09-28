/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldione <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 17:45:57 by ldione            #+#    #+#             */
/*   Updated: 2022/01/25 17:46:01 by ldione           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef ERRORS_H
# define ERRORS_H

# define ERR_OF_ARGUMENT	"invalid argument :("
# define ERR_MLX_INIT		"error of init mlx :("
# define ERR_CAMERA_INIT	"error of init camera :("
# define ERR_OF_CLOSE		"error of close    "
# define ERR_OF_ALLOC		"memory is not allocated     "
# define ERR_OF_MAP			"invalid map :(     "
# define ERR_READING		"impossible to read the map     "

void	terminate(char *s);

#endif
