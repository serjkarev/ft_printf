/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proces_inv_conv_spec.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarev <skarev@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/29 22:07:37 by skarev            #+#    #+#             */
/*   Updated: 2018/09/29 22:07:38 by skarev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	invalid_conversion_specifier(t_arg *arg, const char *format, int *i)
{
	arg->bitmap = arg->bitmap | JOPA;
	arg->content_len = arg->width;
	arg->width -= 1;
	if (arg->bitmap & MINUS)
	{
		write(1, &format[*i], 1);
		while (arg->width--)
			write(1, " ", 1);
	}
	else
	{
		if (arg->bitmap & ZERO)
		{
			while (arg->width--)
				write(1, "0", 1);
		}
		else
		{
			while (arg->width--)
				write(1, " ", 1);
		}
		write(1, &format[*i], 1);
	}
	*i += 1;
	arg->i = (int)*i;
}
