/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuyu <yuyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 15:45:14 by yuyu              #+#    #+#             */
/*   Updated: 2024/07/09 16:40:09 by yuyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mlx_start(t_mlx *mlx)
{
	mlx->mlx_ptr = mlx_init();
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, WIN_X, WIN_Y, "Fractol");
	mlx->img.img_ptr = mlx_new_image(mlx->mlx_ptr, WIN_X, WIN_Y);
	mlx->img.addr = mlx_get_data_addr(mlx->img.img_ptr,
			&mlx->img.bits_per_pixel, &mlx->img.line_length, &mlx->img.endian);
	mlx->pos.x = 0;
	mlx->pos.y = 0;
	mlx->pos.scope = 0.25;
	mlx->col_op = KEY_BLUE;
	return (0);
}

int	main(int argc, char **argv)
{
	t_mlx	mlx;

	if (mlx_start(&mlx))
		exit(0);
	arg_check(argc, argv, &mlx);
	draw_image(&mlx);
	mlx_hook(mlx.win_ptr, X_EVNET_EXIT, 0, program_end, &mlx);
	mlx_hook(mlx.win_ptr, X_EVNET_KEY_PRESS, 0, key_hook, &mlx);
	mlx_mouse_hook(mlx.win_ptr, mouse_hook, &mlx);
	mlx_loop(mlx.mlx_ptr);
	return (0);
}
