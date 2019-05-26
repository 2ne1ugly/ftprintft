/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchi <mchi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 19:07:53 by mchi              #+#    #+#             */
/*   Updated: 2019/05/25 23:46:14 by mchi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_int.h"

void	add_pre_prefix(t_vec *vec, t_opt *opt, char *str)
{
	if (opt->flags & ZERO)
		opt->width -= ft_strlen(str);
	else
		push_front_str(vec, str, ft_strlen(str));
}

void	add_post_prefix(t_vec *vec, t_opt *opt, char *str)
{
	if (opt->flags & ZERO)
		push_front_str(vec, str, ft_strlen(str));
}
