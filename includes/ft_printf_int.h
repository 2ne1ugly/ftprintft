/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_int.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchi <mchi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 13:18:12 by mchi              #+#    #+#             */
/*   Updated: 2019/04/25 22:33:50 by mchi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_INT_H
# define FT_PRINTF_INT_H
# include "ft_printf.h"
# include <stdarg.h>
# include <stdlib.h>
# include <libft.h>
# include <unistd.h>
# include <stddef.h>
# include <stdint.h>

typedef enum	e_flags
{
	minus = 0b1,
	plus = 0b10,
	space = 0b100,
	sharp = 0b1000,
	zero = 0b10000
}				t_flags;

t_flags	g_flags;

typedef struct	s_opt
{
	t_flags	flags;
	int		width;
	int		precision;
	int		length;
	char	spec;
}				t_opt;

typedef struct	s_vec
{
	int		size;
	int		cap;
	char	*ptr;
}				t_vec;

typedef union	u_d
{
	int				n;
	long int		l;
	long long int	ll;
	intmax_t		j;
	size_t			z;
	ptrdiff_t		t;
}				t_d;

typedef union	u_u
{
	unsigned int			n;
	unsigned long int		l;
	unsigned long long int	ll;
	uintmax_t				j;
	size_t					z;
	ptrdiff_t				t;
}				t_u;

typedef union	u_f
{
	double		n;
	long double	t;
}				t_f;

void			init_vec(t_vec *vec);
void			push_back_str(t_vec *vec, const char *str, int n);
void			free_vec(t_vec *vec);
void			expand_vec(t_vec *vec, int n);
void			null_ter_vec(t_vec *vec);
t_opt			parse_opt(const char **str, va_list *arg);

int				base_n_length(size_t val, int base);
char			*itoa_base(size_t val, int count, int n, int is_upper);

void			fmt_c(t_vec *vec, t_opt *opt, va_list *arg);
void			fmt_s(t_vec *vec, t_opt *opt, va_list *arg);
void			fmt_p(t_vec *vec, t_opt *opt, va_list *arg);
void			fmt_n(t_vec *vec, t_opt *opt, va_list *arg);
void			fmt_d(t_vec *vec, t_opt *opt, va_list *arg);
void			fmt_u(t_vec *vec, t_opt *opt, va_list *arg);
void			pad_vec(t_vec *vec, char *str, int n, t_opt *opt);
void			pad_zero(char **str, int *n, t_opt *opt);
#endif
