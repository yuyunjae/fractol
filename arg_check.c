/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuyu <yuyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 22:19:37 by yuyu              #+#    #+#             */
/*   Updated: 2024/07/09 20:22:51 by yuyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	arg_error(t_mlx *mlx)
{
	write(1, "The parameter is invalid!\n", 26);
	write(1, "Valid input case 1 : mandelbrot\n", 32);
	write(1, "Valid input case 2 : julia ", 27);
	write(1, "\"[real_number]\" \"[imaginary number]\"\n", 37);
	write(1, "Valid input case 3 : my_fractol\n", 32);
	program_end(mlx);
}

double	ft_atof(char *str, int *index)
{
	double	real;
	double	point;

	*index = 0;
	point = 0.1;
	real = 0.0;
	while (ft_isdigit(str[(*index)]))
		real = real * 10 + str[(*index)++] - '0';
	if (str[(*index)] == '.')
		(*index)++;
	while (ft_isdigit(str[(*index)]))
	{
		real = real + point * (str[(*index)++] - '0');
		point *= 0.1;
	}
	return (real);
}

double	check_real(char *str, t_mlx *mlx)
{
	int	sign;
	int	index;
	int	i;

	sign = 1;
	i = 0;
	index = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	mlx->j_complex.real = ft_atof(&str[i], &index) * sign;
	if (!str[i + index] || ft_isspace(str[i + index]))
		return (1);
	return (0);
}

int	check_imagin(char *str, t_mlx *mlx)
{
	int	sign;
	int	index;
	int	i;

	index = 0;
	sign = 1;
	i = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	mlx->j_complex.imagin = ft_atof(&str[i], &index) * sign;
	if (str[i + index] == 'i'
		&& (!str[i + index + 1] || ft_isspace(str[i + index + 1])))
		return (1);
	return (0);
}

void	arg_check(int count, char **str, t_mlx *mlx)
{
	mlx->j_complex.real = 0;
	mlx->j_complex.imagin = 0;
	if (count == 2 && (!ft_strcmp(str[1], "mandelbrot")
			|| !ft_strcmp(str[1], "Mandelbrot")))
		mlx->option = 1;
	else if (count == 4 && (!ft_strcmp(str[1], "julia")
			|| !ft_strcmp(str[1], "Julia")) && str[2] && str[3]
		&& check_real(str[2], mlx) && check_imagin(str[3], mlx))
		mlx->option = 2;
	else if (count == 2 && !ft_strcmp(str[1], "my_fractol"))
		mlx->option = 3;
	else
		arg_error(mlx);
}
