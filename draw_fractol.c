/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fractol.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuyu <yuyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 16:05:33 by yuyu              #+#    #+#             */
/*   Updated: 2024/07/09 17:33:50 by yuyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	julia_set(int i, int j, t_mlx *mlx)
{
	int			k;
	t_complex	complex;
	t_complex	p_comp;
	double		n_real;

	k = 0;
	complex.real = ((double)i - WIN_X / 2)
		/ (WIN_X * mlx->pos.scope) + mlx->pos.x;
	complex.imagin = (WIN_Y / 2 - (double)j)
		/ (WIN_X * mlx->pos.scope) - mlx->pos.y;
	p_comp.real = complex.real * complex.real;
	p_comp.imagin = complex.imagin * complex.imagin;
	while (p_comp.real + p_comp.imagin < 4 && k < ITER_MAX)
	{
		n_real = p_comp.real - p_comp.imagin
			+ mlx->j_complex.real;
		complex.imagin = complex.real * complex.imagin * 2
			+ mlx->j_complex.imagin;
		complex.real = n_real;
		p_comp.real = complex.real * complex.real;
		p_comp.imagin = complex.imagin * complex.imagin;
		k++;
	}
	return (k);
}

void	draw_julia(t_mlx *mlx)
{
	int	i;
	int	j;
	int	iter;

	i = -1;
	while (++i < WIN_X)
	{
		j = -1;
		while (++j < WIN_Y)
		{
			iter = julia_set(i, j, mlx);
			my_mlx_pixel_put(mlx, i, j, iter);
		}
	}
}

int	mandelbrot_set(int i, int j, t_mlx *mlx)
{
	int			k;
	double		n_real;
	t_complex	z_comp;
	t_complex	c_comp;
	t_complex	p_comp;

	c_comp.real = ((double)i - 5 * WIN_X / 8)
		/ (WIN_X * mlx->pos.scope) + mlx->pos.x;
	c_comp.imagin = (WIN_Y / 2 - (double)j)
		/ (WIN_X * mlx->pos.scope) - mlx->pos.y;
	k = 0;
	z_comp.real = 0;
	z_comp.imagin = 0;
	p_comp.real = 0;
	p_comp.imagin = 0;
	while (p_comp.real + p_comp.imagin < 4 && k < ITER_MAX)
	{
		n_real = p_comp.real - p_comp.imagin + c_comp.real;
		z_comp.imagin = 2 * z_comp.real * z_comp.imagin + c_comp.imagin;
		z_comp.real = n_real;
		p_comp.real = z_comp.real * z_comp.real;
		p_comp.imagin = z_comp.imagin * z_comp.imagin;
		k++;
	}
	return (k);
}

void	draw_mandelbort(t_mlx *mlx)
{
	int	i;
	int	j;
	int	iter;

	i = -1;
	while (++i < WIN_X)
	{
		j = -1;
		while (++j < WIN_Y)
		{
			iter = mandelbrot_set(i, j, mlx);
			my_mlx_pixel_put(mlx, i, j, iter);
		}
	}
}

void	draw_image(t_mlx *mlx)
{
	if (mlx->option == 1)
		draw_mandelbort(mlx);
	else if (mlx->option == 2)
		draw_julia(mlx);
	else if (mlx->option == 3)
		draw_my_fractol(mlx);
	else
		program_end(mlx);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img.img_ptr, 0, 0);
}
