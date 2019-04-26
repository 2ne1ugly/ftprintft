/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchi <mchi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 13:16:53 by mchi              #+#    #+#             */
/*   Updated: 2019/04/25 22:18:12 by mchi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_int.h"

/*
** 1 -> -
** 2 -> +
** 3 -> ' '
** 4 -> #
** 5 -> 0
*/

void	get_flag(t_opt *opt, const char **str)
{
	opt->flags = 0;

	while (**str != '\0' && (**str == '-' || **str == '+' || **str == ' '
		|| **str == '#' || **str == '0'))
	{
		if (**str == '-')
			opt->flags |= minus;
		else if (**str == '+')
			opt->flags |= plus;
		else if (**str == ' ')
			opt->flags |= space;
		else if (**str == '#')
			opt->flags |= sharp;
		else if (**str == '0')
			opt->flags |= zero;
		(*str)++;
	}
}

void	get_width(t_opt *opt, const char **str)
{
	opt->width = 0;
	while (**str != '\0' && (('0' <= (**str) && (**str) <= '9')
		|| **str == '*'))
	{
		if (**str == '*')
		{
			opt->width = -1;
			(*str)++;
			break ;
		}
		else
		{
			opt->width *= 10;
			opt->width += **str - '0';
		}
		(*str)++;
	}
}

void	get_precision(t_opt *opt, const char **str)
{
	opt->precision = 0;
	if (**str != '.')
		return ;
	while (**str != '\0' && (('0' <= (**str) && (**str) <= '9')
		|| **str == '*'))
	{
		if (**str == '*')
		{
			opt->precision = -1;
			(*str)++;
			break ;
		}
		else
		{
			opt->precision *= 10;
			opt->precision += **str - '0';
		}
		(*str)++;
	}
}

/*
** 0 -> ' '
** 1 -> hh
** 2 -> h
** 3 -> ll
** 4 -> l
** 5 -> j
** 6 -> z
** 7 -> t
** 8 -> L
*/

void	get_length(t_opt *opt, const char **str)
{
	opt->length = 0;
	if (**str == 'h')
		opt->length = 2;
	else if (**str == 'l')
		opt->length = 4;
	else if (**str == 'j')
		opt->length = 5;
	else if (**str == 'z')
		opt->length = 6;
	else if (**str == 't')
		opt->length = 7;
	else if (**str == 'L')
		opt->length = 8;
	if (**str == 'h' || **str == 'l' || **str == 'j' || **str == 'z'
		|| **str == 't' || **str == 'L')
		(*str)++;
	if (**str == 'h' || **str == 'l')
	{
		opt->length--;
		(*str)++;
	}
}

t_opt	parse_opt(const char **str)
{
	int		i;
	t_opt	out;

	i = 0;
	get_flag(&out, str);
	get_width(&out, str);
	get_precision(&out, str);
	get_length(&out, str);
	out.spec = **str;
	return (out);
}
