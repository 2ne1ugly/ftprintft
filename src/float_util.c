/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 17:05:45 by marvin            #+#    #+#             */
/*   Updated: 2019/04/26 17:05:45 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		get_bit_double(double *val, int n)
{
	char *ptr;

	ptr = val;
	ptr = &ptr[n / 8];
	return (*ptr >> (n % 8)) & 0b1;
}

double	calc_fraction_bit_double(double *val)
{
	double	out;
	int		i;

	out = 1;
	i = 0;
	while(i < 52)
	{
		out += get_bit_double(val, 51 - i) / (double)(1 << i);
		i++;
	}
	if (get_bit_double(val, 63) == -1)
		out *= -1;
	return (out);
}
