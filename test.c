/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchi <mchi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 13:31:55 by mchi              #+#    #+#             */
/*   Updated: 2019/04/25 21:59:42 by mchi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <math.h>

int		get_bit_double(double *val, int n)
{
	char *ptr;

	ptr = val;
	ptr = &ptr[n / 8];
	return (*ptr >> (n % 8)) & 0b1;
}

long long	calc_fraction_bit_double(double *val)
{
	long long	out;
	int		i;

	out = 1;
	i = 51;
	while(i >= 0)
	{
		out <<= 1;
		out += get_bit_double(val, i);
		i--;
	}
	printf("%d\n", out);
	if (get_bit_double(val, 63))
		out *= -1;
	return (out);
}

double		calc_exp_bit_double(double *val)
{
	int	out;
	int	i;

	out = 0;
	i = 62;
	while (i >= 52)
	{
		out *= 2;
		out += get_bit_double(val, i);
		printf("%d\n", get_bit_double(val, i));
		i--;
	}
	printf("%d\n",out);
	return (pow(2, out - 1023 - 52));
}

int main()
{
	double val;

	val = 3.14;
	printf("%f\n", val);
	printf("%f\n", calc_exp_bit_double(&val) * calc_fraction_bit_double(&val));
}
