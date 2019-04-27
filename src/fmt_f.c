/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fmt_f.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchi <mchi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 19:29:23 by mchi              #+#    #+#             */
/*   Updated: 2019/04/25 19:43:33 by mchi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_int.h"

void	calculate_fraction(double val)
{

}

//solve this one later
void	fmt_f(t_vec *vec, t_opt *opt, va_list *arg)
{
	long double	val;
	char		*out;

	if (opt->length == 8)
		val = va_arg(*arg, long double);
	else
		val = va_arg(*arg, long double);
	push_back_str(vec, out, ft_strlen(out));
}
