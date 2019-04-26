/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchi <mchi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 12:38:12 by mchi              #+#    #+#             */
/*   Updated: 2019/04/25 19:57:23 by mchi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_int.h"

void	(*g_disp_spec[128])(t_vec *, t_opt *, va_list *) =
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
	['n'] = fmt_n
};

void	format_this(t_vec *vec, const char **format, va_list *list)
{
	t_opt opt;

	(*format)++;
	opt = parse_opt(format, list);
	g_disp_spec[(int)opt.spec](vec, &opt, list);
}

int		ft_printf(const char *format, ...)
{
	t_vec	vec;
	va_list list;

	va_start(list, format);
	init_vec(&vec);
	while (*format != '\0')
	{
		if (*format == '%' && (format[1]) != '%')
			format_this(&vec, &format, &list);
		else
			push_back_str(&vec, format, 1);
		format++;
	}
	null_ter_vec(&vec);
	write(1, vec.ptr, vec.size + 1);
	va_end(list);
	free_vec(&vec);
	return (vec.size);
}
