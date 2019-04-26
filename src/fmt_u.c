/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fmt_u.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchi <mchi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 19:21:30 by mchi              #+#    #+#             */
/*   Updated: 2019/04/25 21:43:21 by mchi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_int.h"

void		u_set_arg(uintmax_t *val, int length, va_list *arg)
{
	if (length == 0 || length == 1 || length == 2)
		*val = va_arg(*arg, unsigned int);
	else if (length == 3)
		*val = va_arg(*arg, unsigned long int);
	else if (length == 4)
		*val = va_arg(*arg, unsigned long long int);
	else if (length == 5)
		*val = va_arg(*arg, uintmax_t);
	else if (length == 6)
		*val = va_arg(*arg, size_t);
	else if (length == 7)
		*val = va_arg(*arg, ptrdiff_t);
}

void	fmt_u(t_vec *vec, t_opt *opt, va_list *arg)
{
	uintmax_t	val;
	char		*out;
	int			length;
	int			base;

	u_set_arg(&val, opt->length, arg);
	base = 10;
	if (opt->spec == 'x' || opt->spec == 'X' || opt->spec == 'o')
	{
		base = 8;
		if (opt->flags & sharp)
			push_back_str(vec, "0", 1);
		if (opt->spec == 'x' || opt->spec == 'X')
		{
			push_back_str(vec, &opt->spec, 1);
			base = 16;
			if (opt->flags & sharp)
				push_back_str(vec, &opt->spec, 1);
		}
	}
	length = base_n_length(val, base);
	out = itoa_base(val, length, base, opt->spec == 'X');
	push_back_str(vec, out, length);
	free(out);
}
