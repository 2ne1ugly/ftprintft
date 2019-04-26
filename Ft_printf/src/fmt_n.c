/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fmt_n.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchi <mchi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 19:09:04 by mchi              #+#    #+#             */
/*   Updated: 2019/04/25 21:09:41 by mchi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_int.h"

void	fmt_n(t_vec *vec, t_opt *opt, va_list *arg)
{
	void *ptr;

	(void)opt;
	ptr = va_arg(*arg, void*);
	if (opt->length == 0)
		*(int *)ptr = vec->size;
	if (opt->length == 1)
		*(char *)ptr = vec->size;
	if (opt->length == 2)
		*(short *)ptr = vec->size;
	if (opt->length == 3)
		*(long *)ptr = vec->size;
	if (opt->length == 4)
		*(long long *)ptr = vec->size;
	if (opt->length == 5)
		*(intmax_t *)ptr = vec->size;
	if (opt->length == 6)
		*(size_t *)ptr = vec->size;
	if (opt->length == 7)
		*(ptrdiff_t *)ptr = vec->size;
}
