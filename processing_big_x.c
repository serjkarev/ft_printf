/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processing_big_x.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarev <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 22:25:18 by skarev            #+#    #+#             */
/*   Updated: 2018/09/18 22:25:18 by skarev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	processing_b_x(t_arg *arg, va_list *ap)
{
	x_big_processing_type(arg, ap);
	x_big_processing_precision(arg);
	x_big_processing_flags(arg);
	x_big_processing_width(arg);
}

void	x_big_processing_type(t_arg *arg, va_list *ap)
{
	if (arg->bitmap & L)
		arg->x_content = (unsigned long)va_arg(*ap, long);
	else if (arg->bitmap & LL)
		arg->x_content = (unsigned long long)va_arg(*ap, long long);
	else if (arg->bitmap & H)
		arg->x_content = (unsigned short)va_arg(*ap, int);
	else if (arg->bitmap & HH)
		arg->x_content = (unsigned char)va_arg(*ap, int);
	else if (arg->bitmap & Z)
		arg->x_content = va_arg(*ap, size_t);
	else if (arg->bitmap & J)
		arg->x_content = va_arg(*ap, unsigned long);	
	else
		arg->x_content = (unsigned int)va_arg(*ap, int);
	if ((arg->x_content == 0 && arg->bitmap & PRECISION))
		arg->non_valid = 228;
	else
		arg->content = ft_itoa_base_ull_big(arg->x_content, 16);
	arg->content_len = ft_strlen(arg->content);	
}

void	x_big_processing_precision(t_arg *arg)
{
	positive_content(arg);
}

void	x_big_processing_flags(t_arg *arg)
{
	if (arg->bitmap & HESH && arg->x_content > 0)
	{
		arg->content = ft_strjoin("0X", arg->content);
		arg->content_len += 2;
	}
}

void	x_big_processing_width(t_arg *arg)
{
	x_processing_width(arg);
}
