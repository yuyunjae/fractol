/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_fractol.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuyu <yuyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 17:42:40 by yuyu              #+#    #+#             */
/*   Updated: 2024/07/09 20:28:58 by yuyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	my_fractol_set(int i, int j, t_mlx *mlx)
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
	while (p_comp.real * p_comp.imagin < 4 && k < ITER_MAX)
	{
		n_real = p_comp.real - p_comp.imagin + c_comp.real;
		z_comp.imagin = fabs(2 * z_comp.real * z_comp.imagin) + c_comp.imagin;
		z_comp.real = n_real;
		p_comp.real = z_comp.real * z_comp.real;
		p_comp.imagin = z_comp.imagin * z_comp.imagin;
		k++;
	}
	return (k);
}

void	draw_my_fractol(t_mlx *mlx)
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
			iter = my_fractol_set(i, j, mlx);
			my_mlx_pixel_put(mlx, i, j, iter);
		}
	}
}
