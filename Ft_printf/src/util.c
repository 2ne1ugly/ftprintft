/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchi <mchi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 19:56:35 by mchi              #+#    #+#             */
/*   Updated: 2019/04/25 22:37:54 by mchi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_int.h"

int		base_n_length(uintmax_t val, int base)
{
	int count;

	if (val == 0)
		return (1);
	count = 0;
	while (val != 0)
	{
		val /= base;
		count++;
	}
	return (count);
}

char	*itoa_base(uintmax_t val, int count, int n, int is_upper)
{
	char		*str;
	char		*base;

	base = "0123456789ABCDEF";
	if (!is_upper)
		base = "0123456789abcdef";
	str = malloc(sizeof(char) * count);
	if (val == 0)
	{
		str[0] = base[0];
		return (str);
	}
	while (count > 0)
	{
		count--;
		str[count] = base[val % n];
		val /= n;
	}
	return (str);
}

void	pad_vec(t_vec *vec, char *str, int n, t_opt *opt)
{
	int		i;

	if (opt->width > n)
	{
		if (opt->flags & minus)
		{
			push_back_str(vec, str, n);
			i = n - 1;
			while (++i < opt->width)
				push_back_str(vec, " ", 1);
			n = opt->width;
		}
		else
		{
			i = -1;
			while (++i < opt->width - n)
				push_back_str(vec, " ", 1);
			push_back_str(vec, str, n);
		}
	}
	else
		push_back_str(vec, str, n);
}

