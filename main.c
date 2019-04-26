/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchi <mchi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 13:14:06 by mchi              #+#    #+#             */
/*   Updated: 2019/04/25 22:21:31 by mchi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#define STR argv[1]//"%5c\n"

#include  <stdlib.h>
int	main(int argc, char **argv)
{
	ft_printf(STR, atoi(argv[2]));
	printf(STR, atoi(argv[2]));
}
