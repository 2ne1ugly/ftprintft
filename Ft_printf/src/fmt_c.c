/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fmt_c.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchi <mchi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 13:16:42 by mchi              #+#    #+#             */
/*   Updated: 2019/04/25 22:33:18 by mchi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_int.h"

void	fmt_c(t_vec *vec, t_opt *opt, va_list *arg)
{
	char	c;
	int		len;

	c = va_arg(*arg, int);
	len = 1;
	pad_vec(vec, &c, len, opt);
}
