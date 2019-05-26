/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchi <mchi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 12:38:12 by mchi              #+#    #+#             */
/*   Updated: 2019/05/25 19:00:25 by mchi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_int.h"

t_vec	(*g_disp_spec[])(t_opt *, va_list *) =
{
	['d'] = fmt_d,
	['i'] = fmt_d,
	['u'] = fmt_u,
	['o'] = fmt_u,
	['x'] = fmt_u,
	['X'] = fmt_u,
	['c'] = fmt_c,
	['s'] = fmt_s,
	['p'] = fmt_p,
	['f'] = fmt_f,
	['%'] = fmt_per
};

void	format_this(t_vec *vec, const char **format, va_list *list)
{
	t_opt	opt;
	t_vec	sub_vec;

	(*format)++;
	opt = parse_opt(format, list);
	if (opt.spec == 'n')
		fmt_n(&opt, list, vec->size);
	else
		sub_vec = g_disp_spec[(int)opt.spec](&opt, list);
	push_back_str(vec, sub_vec.ptr, sub_vec.size);
	free_vec(&sub_vec);
}

int		ft_printf(const char *format, ...)
{
	t_vec	vec;
	va_list list;

	va_start(list, format);
	init_vec(&vec);
	while (*format != '\0')
	{
		if (*format == '%')
			format_this(&vec, &format, &list);
		else
			push_back_str(&vec, format, 1);
		format++;
	}
	write(1, vec.ptr, vec.size);
	va_end(list);
	free_vec(&vec);
	return (vec.size);
}
