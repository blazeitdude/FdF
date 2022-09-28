/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldione <ldione@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 19:00:07 by ldione            #+#    #+#             */
/*   Updated: 2022/07/06 20:04:28 by ldione           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H

# include <stdbool.h>
# include "key.h"
# include "colors.h"
# include "libft.h"
# include "mlx.h"
# include "errors.h"
# include <math.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# define HEIGHT			1080
# define WIDTH			1920
# define MENU_WIDTH		350
# define MENU_HEIGHT	400
# define PLAY_WIDTH		150
# define PLAY_HEIGHT	150
# define GIT_WIDTH		400
# define GIT_HEIGHT		162
# define PEPEGA			"./includes/images/pepega"
# define PLAY			"./includes/images/play"
# define GIT			"./includes/images/git"

typedef enum e_projection
{
	ISO,
	PARALLEL
}	t_projection;

typedef struct s_mouse
{
	char				is_pressed;
	int					x;
	int					y;
	int					previous_x;
	int					previous_y;
}						t_mouse;

typedef struct s_camera
{
	t_projection	projection;
	int				zoom;
	double			alpha;
	double			beta;
	double			gamma;
	float			z_divisor;
	int				x_offset;
	int				y_offset;
}				t_camera;

typedef struct s_inp
{
	int	x;
	int	y;
	int	z;
	int	color;
}				t_inp;

typedef struct s_map
{
	int	**matrix;
	int	**color;
	int	height;
	int	width;
	int	zoom;
	int	z_min;
	int	z_max;
}				t_map;

typedef struct s_data
{
	t_map		*map;
	t_camera	*camera;
	t_mouse		*mouse;
	void		*mlx;
	void		*mlx_start_win;
	void		*mlx_win;
	void		*mlx_logo;
	void		*mlx_play;
	void		*mlx_git;
	void		*start_img;
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_data;

void		controls(t_data *data);
int			close_all(void *param);
t_inp		create_inp(t_map *map, int x, int y);
void		check_matrix(char *name);
void		change_projection(int key, t_data *data);
void		draw_background(t_data *data, int flag);
void		draw_line(t_data *data, t_inp from, t_inp to);
void		draw_map(t_data *data);
void		draw_pepega(t_data *data);
void		draw_point(t_data *data, int x, int y, int color);
int			draw_start_menu(void *data);
void		flatten(int key, t_data *data);
void		*ft_allocate(size_t num, size_t size);
void		ft_close(int fd);
int			find_min(int a, int b);
int			find_max(int a, int b);
void		ft_mlx_string_put(void *mlx, void *mlx_win, int y);
void		gwh(t_map *map, char *name);
int			get_color(t_inp cur, t_inp start, t_inp end, t_inp delta);
int			get_default_color(int z, t_map *map);
int			get_light(int start, int end, double perc);
double		get_percent(int start, int end, int cur);
void		iso(int *x, int *y, int z);
t_inp		inp_addition(t_data *data, t_inp inp);
t_camera	*init_camera(t_map *map);
void		init_map(t_map *map, char *name);
void		init_main_code(t_data *data);
void		init_map_height(t_map *map);
void		init_start_mlx(t_data *data);
int			key_press(int key, void *param);
void		move(int key, t_data *data);
void		min_max_z(t_map *map);
int			mouse_press(int button, int x, int y, void *param);
int			mouse_press_start(int button, int x, int y, void *param);
int			mouse_release(int button, int x, int y, void *param);
int			mouse_move(int x, int y, void *param);
void		rotate(int key, t_data *data);
void		rotate_x(int *y, int *z, float alpha);
void		rotate_y(int *x, int *z, float beta);
void		rotate_z(int *x, int *y, float gamma);
void		sign_check(t_inp *from, t_inp *to, t_inp *sign);
void		simple_draw(t_data *data);
//void		init_pepega(t_data *data);
void		zoom(int key, t_data *data);

#endif