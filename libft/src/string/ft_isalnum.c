/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awindham <awindham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 14:02:46 by awindham          #+#    #+#             */
/*   Updated: 2018/12/02 11:55:23 by awindham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isalnum(int c)
{
	if (c)
		if (c >= -128 && c < 256)
			return ((ft_isalpha(c) | ft_isdigit(c)));
	return (0);
}