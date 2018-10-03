/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dop_4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarev <skarev@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 04:01:50 by skarev            #+#    #+#             */
/*   Updated: 2018/10/03 04:01:50 by skarev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	parce_helper_1(t_arg *arg, char c)
{
	c == 'p' ? (arg->bitmap = arg->bitmap | P) : \
							(arg->bitmap = arg->bitmap | I);
}

void	parce_helper_2(t_arg *arg, char c)
{
	c == 's' ? (arg->bitmap = arg->bitmap | SMALL_S) : \
							(arg->bitmap = arg->bitmap | BIG_S);
}

void	parce_helper_3(t_arg *arg, char c)
{
	c == 'd' ? (arg->bitmap = arg->bitmap | SMALL_D) : \
							(arg->bitmap = arg->bitmap | BIG_D);
}

void	parce_helper_4(t_arg *arg, char c)
{
	c == 'o' ? (arg->bitmap = arg->bitmap | SMALL_O) : \
							(arg->bitmap = arg->bitmap | BIG_O);
}
