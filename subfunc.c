/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subfunc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuyu <yuyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 21:50:00 by yuyu              #+#    #+#             */
/*   Updated: 2024/07/09 17:27:09 by yuyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_isspace(char c)
{
	if (c == ' ' || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

void	my_mlx_pixel_put(t_mlx *mlx, int x, int y, int iter)
{
	char	*dst;

	dst = mlx->img.addr + (y * mlx->img.line_length
			+ x * (mlx->img.bits_per_pixel / 8));
	iter *= 12;
	if (mlx->col_op == KEY_RED)
	{
		*(unsigned int *)dst = iter << 16 | (iter >> 8);
	}
	else if (mlx->col_op == KEY_GREEN)
	{
		*(unsigned int *)dst = iter << 8;
	}
	else if (mlx->col_op == KEY_BLUE)
	{
		*(unsigned int *)dst = iter;
	}
}
