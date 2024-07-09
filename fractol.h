/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuyu <yuyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 15:57:38 by yuyu              #+#    #+#             */
/*   Updated: 2024/07/09 17:34:34 by yuyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <unistd.h>
# include <math.h>
# include <stdlib.h>
# include <mlx.h>

# define WIN_X 1920
# define WIN_Y 1080
# define X_EVNET_KEY_PRESS 2
# define X_EVNET_EXIT 17

# define KEY_EXIT 53
# define KEY_UP 126
# define KEY_LEFT 123
# define KEY_DOWN 125
# define KEY_RIGHT 124

# define KEY_RED 15
# define KEY_GREEN 5
# define KEY_BLUE 11

# define LEFT_CLICK 1
# define MOUSE_SCROLL_UP 4
# define MOUSE_SCROLL_DOWN 5

# define ITER_MAX 500

typedef struct s_position
{
	double	x;
	double	y;
	double	scope;
}	t_position;

typedef struct s_data
{
	void	*img_ptr;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_complex
{
	double	real;
	double	imagin;
}	t_complex;

typedef struct s_mlx
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			option;
	int			col_op;
	t_position	pos;
	t_data		img;
	t_complex	j_complex;
}	t_mlx;

int		ft_strcmp(const char *s1, const char *s2);
int		ft_isdigit(int c);
int		ft_isspace(char c);
void	draw_image(t_mlx *mlx);
int		program_end(t_mlx *mlx);
int		key_hook(int keycode, t_mlx *mlx);
int		mouse_hook(int keycode, int x, int y, t_mlx *mlx);
void	arg_check(int count, char **str, t_mlx *mlx);
void	my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color);

void	draw_my_fractol(t_mlx *mlx);

#endif
