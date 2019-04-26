/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fmt_s.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchi <mchi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 18:32:51 by mchi              #+#    #+#             */
/*   Updated: 2019/04/25 19:05:19 by mchi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_int.h"

void	fmt_s(t_vec *vec, t_opt *opt, va_list *arg)
{
	char *str;

	(void)opt;
	str = va_arg(*arg, void*);
	if (str == NULL)
	{
		push_back_str(vec, "(null)", 6);
		return ;
	}
	push_back_str(vec, str, ft_strlen(str));
}
