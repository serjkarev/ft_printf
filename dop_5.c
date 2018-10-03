/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dop_5.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarev <skarev@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 04:12:25 by skarev            #+#    #+#             */
/*   Updated: 2018/10/03 04:12:25 by skarev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void					parce_helper_5(t_arg *arg, char c)
{
	c == 'u' ? (arg->bitmap = arg->bitmap | SMALL_U) : \
							(arg->bitmap = arg->bitmap | BIG_U);
}

void					parce_helper_6(t_arg *arg, char c)
{
	c == 'x' ? (arg->bitmap = arg->bitmap | SMALL_X) : \
							(arg->bitmap = arg->bitmap | BIG_X);
}

void					parce_helper_7(t_arg *arg, char c)
{
	c == 'c' ? (arg->bitmap = arg->bitmap | SMALL_C) : \
							(arg->bitmap = arg->bitmap | BIG_C);
}

void					parce_helper_8(t_arg *arg, char c)
{
	c == '%' ? (arg->bitmap = arg->bitmap | PERCENT) : \
							(arg->bitmap = arg->bitmap | BINARY);
}
