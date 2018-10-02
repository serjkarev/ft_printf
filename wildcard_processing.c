/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard_processing.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarev <skarev@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/02 23:29:39 by skarev            #+#    #+#             */
/*   Updated: 2018/10/02 23:29:39 by skarev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	wildcard_processing(t_arg *arg)
{
	if (arg->width < 0)
	{
		arg->bitmap = arg->bitmap | MINUS;
		arg->width *= -1;
	}
	if (arg->precision < 0)
		arg->precision *= -1;
}

void	proc_binary(t_arg *arg, va_list *ap)
{
	if (arg->bitmap & LL)
		arg->x_content = va_arg(*ap, unsigned long long);
	else if (arg->bitmap & L)
		arg->x_content = va_arg(*ap, unsigned long);
	else if (arg->bitmap & J)
		arg->x_content = va_arg(*ap, unsigned long);
	else if (arg->bitmap & H)
		arg->x_content = (unsigned short)va_arg(*ap, unsigned int);
	else if (arg->bitmap & HH)
		arg->x_content = (unsigned char)va_arg(*ap, unsigned int);
	else if (arg->bitmap & Z)
		arg->x_content = va_arg(*ap, size_t);
	else
		arg->x_content = va_arg(*ap, unsigned int);
	arg->content = ft_itoa_base_ull(arg->x_content, 2);
	arg->content_len = ft_strlen(arg->content);
	d_processing_precision(arg);
	d_processing_flags(arg);
	d_processing_width(arg);
}
