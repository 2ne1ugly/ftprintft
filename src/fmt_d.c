/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fmt_d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchi <mchi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 19:13:06 by mchi              #+#    #+#             */
/*   Updated: 2019/04/25 22:36:16 by mchi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_int.h"

void		d_set_arg(intmax_t *val, int length, va_list *arg)
{
	if (length == 0 || length == 1 || length == 2)
		*val = va_arg(*arg, int);
	else if (length == 3)
		*val = va_arg(*arg, long int);
	else if (length == 4)
		*val = va_arg(*arg, long long int);
	else if (length == 5)
		*val = va_arg(*arg, intmax_t);
	else if (length == 6)
		*val = va_arg(*arg, size_t);
	else if (length == 7)
		*val = va_arg(*arg, ptrdiff_t);
}

void		fmt_d(t_vec *vec, t_opt *opt, va_list *arg)
{
	intmax_t	raw;
	int			length;
	char		*out;

	(void)opt;
	d_set_arg(&raw, opt->length, arg);
	length = base_n_length(raw, 10);
	out = itoa_base(raw, length, 10, 0);
	pad_vec(vec, out, length, opt);
	free(out);
}
