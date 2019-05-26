/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchi <mchi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 13:31:55 by mchi              #+#    #+#             */
/*   Updated: 2019/05/25 22:27:16 by mchi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <math.h>
#include <float.h>

int			ft_msb(int val)
{
	unsigned int r;

	r = 0;
	while (val >>= 1)
	{
		r++;
	}
	return (r);
}

long double	ft_ln(long double y)
{
	int			log2val;
	long double divisor;
	long double x;
	long double result;

	log2val = ft_msb((int)y);
	divisor = (long double)(1 << log2val);
	x = y / divisor;
	result = -1.7417939 +
		(2.8212026 +
		(-1.4699568 + (0.44717955 - 0.056570851 * x) * x) * x) * x;
	result += ((long double)log2val) * 0.69314718;
	return (result);
}

long double	ft_log10(long double y)
{
	return (ft_ln(y) / 2.30258509299L);
}

int main()
{
	printf("%Lf", ft_log10(100.0L));
	return (0);
}
