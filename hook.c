/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuyu <yuyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 16:24:38 by yuyu              #+#    #+#             */
/*   Updated: 2024/07/09 17:34:18 by yuyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	program_end(t_mlx *mlx)
{
	mlx_destroy_image(mlx->mlx_ptr, mlx->img.img_ptr);
	mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	exit(0);
}

int	key_hook(int keycode, t_mlx *mlx)
{
	if (keycode == KEY_EXIT)
		program_end(mlx);
	if (keycode == KEY_UP || keycode == KEY_LEFT
		|| keycode == KEY_DOWN || keycode == KEY_RIGHT)
	{
		if (keycode == KEY_UP)
			mlx->pos.y += 0.03125 / mlx->pos.scope;
		else if (keycode == KEY_LEFT)
			mlx->pos.x += 0.03125 / mlx->pos.scope;
		else if (keycode == KEY_DOWN)
			mlx->pos.y -= 0.03125 / mlx->pos.scope;
		else if (keycode == KEY_RIGHT)
			mlx->pos.x -= 0.03125 / mlx->pos.scope;
		draw_image(mlx);
	}
	else if (keycode == KEY_RED || keycode == KEY_GREEN || keycode == KEY_BLUE)
	{
		mlx->col_op = keycode;
		draw_image(mlx);
	}
	return (0);
}

int	mouse_hook(int keycode, int x, int y, t_mlx *mlx)
{
	if (keycode == MOUSE_SCROLL_UP)
	{
		mlx->pos.x += ((double)x - WIN_X / 2) / (WIN_X * mlx->pos.scope);
		mlx->pos.y -= (WIN_Y / 2 - (double)y) / (WIN_X * mlx->pos.scope);
		mlx->pos.scope *= 2;
		draw_image(mlx);
	}
	else if (keycode == MOUSE_SCROLL_DOWN)
	{
		mlx->pos.x += ((double)x - WIN_X / 2) / (WIN_X * mlx->pos.scope);
		mlx->pos.y -= (WIN_Y / 2 - (double)y) / (WIN_X * mlx->pos.scope);
		mlx->pos.scope /= 2;
		draw_image(mlx);
	}
	else if (keycode == LEFT_CLICK)
	{
		mlx->pos.x += ((double)x - WIN_X / 2) / (WIN_X * mlx->pos.scope);
		mlx->pos.y -= (WIN_Y / 2 - (double)y) / (WIN_X * mlx->pos.scope);
		draw_image(mlx);
	}
	return (0);
}
