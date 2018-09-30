/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processing_big_o.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarev <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 20:17:28 by skarev            #+#    #+#             */
/*   Updated: 2018/09/21 20:17:29 by skarev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    processing_b_o(t_arg *arg, va_list *ap)
{
    o_big_processing_type(arg, ap);
    if (arg->x_content == 0 && arg->width != 0 && arg->precision == 0)
			arg->content = ft_strdup(" ");
	else if (arg->x_content == 0 && arg->bitmap & PRECISION && arg->precision == 0)
		arg->content = ft_strdup("");
    o_processing_precision(arg);
	o_processing_flags(arg);
	o_processing_width(arg);
}

void    o_big_processing_type(t_arg *arg, va_list *ap)
{
    arg->x_content = (unsigned long)va_arg(*ap, long);
    arg->content = ft_itoa_base_ull(arg->x_content, 8);
	arg->content_len = ft_strlen(arg->content);
}
