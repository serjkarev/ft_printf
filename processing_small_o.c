/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processing_small_o.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarev <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/16 19:56:49 by skarev            #+#    #+#             */
/*   Updated: 2018/09/16 19:56:49 by skarev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    processing_o(t_arg *arg, va_list *ap)
{
    o_processing_type(arg, ap);
	o_processing_precision(arg);
	o_processing_flags(arg);
	o_processing_width(arg);
}

void    o_processing_type(t_arg *arg, va_list *ap)
{
    if (arg->bitmap & L || arg->bitmap & BIG_O)
		arg->x_content = va_arg(*ap, unsigned long);
	else if (arg->bitmap & LL)
		arg->x_content = va_arg(*ap, unsigned long long);
	else if (arg->bitmap & H)
		arg->x_content = (unsigned short)va_arg(*ap, unsigned int);
	else if (arg->bitmap & HH)
		arg->x_content = (unsigned char)va_arg(*ap, unsigned int);
	else if (arg->bitmap & Z)
		arg->x_content = va_arg(*ap, size_t);
	else if (arg->bitmap & J)
		arg->x_content = va_arg(*ap, unsigned long);
	else
		arg->x_content = va_arg(*ap, unsigned int);
	arg->content = ft_itoa_base_ull(arg->x_content, 8);
	arg->content_len = ft_strlen(arg->content);
}

void	o_processing_precision(t_arg *arg)
{
    positive_content(arg);
}

void	o_processing_flags(t_arg *arg)
{
    if (arg->bitmap & HESH && !(arg->bitmap & PRECISION))
        arg->content = ft_strjoin("0", arg->content);
    else if (arg->bitmap & HESH && arg->bitmap & WIDTH && !(arg->bitmap & PRECISION))
        arg->content = ft_strjoin(" ", arg->content);
    arg->content_len = ft_strlen(arg->content);
}

void	o_processing_width(t_arg *arg)
{
    u_processing_width(arg);
}
