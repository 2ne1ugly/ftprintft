/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fmt_p.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchi <mchi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 18:39:58 by mchi              #+#    #+#             */
/*   Updated: 2019/04/25 19:55:19 by mchi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_int.h"

void	fmt_p(t_vec *vec, t_opt *opt, va_list *arg)
{
	void	*ptr;
	int		length;
	char	*conv;

	(void)opt;
	ptr = va_arg(*arg, void*);
	length = base_n_length((uintmax_t)ptr, 16);
	conv = itoa_base((uintmax_t)ptr, length, 16, 0);
	push_back_str(vec, "0x", ft_strlen("0x"));
	push_back_str(vec, conv, length);
	free(conv);
}
