/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processing_small_u.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarev <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 17:51:19 by skarev            #+#    #+#             */
/*   Updated: 2018/09/14 17:51:19 by skarev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	processing_u(t_arg *arg, va_list *ap)
{
	u_processing_type(arg, ap);
	u_processong_precision(arg);
	u_processing_width(arg);
}

void	u_processing_type(t_arg *arg, va_list *ap)
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
		arg->x_content = va_arg(*ap, unsigned long); //что за юинтмакс???
	else
		arg->x_content = (unsigned int)va_arg(*ap, int);
	if (arg->x_content == 0 && arg->precision == 0 && arg->bitmap & PRECISION)
		arg->content = ft_strdup("");
	else
		arg->content = ft_itoa_base_ull(arg->x_content, 10);
	arg->content_len = ft_strlen(arg->content);
}

void	u_processong_precision(t_arg *arg)
{
	positive_content(arg);
}

void	u_processing_width(t_arg *arg)
{
	if ((arg->width > arg->content_len) && arg->bitmap & WIDTH)
	{
		if (arg->bitmap & MINUS)
			minus_width(arg);
		else if ((arg->bitmap & ZERO) && !(arg->bitmap & PRECISION))
			zero_width(arg);
		else
			only_width(arg);
	}
	arg->content_len = ft_strlen(arg->content);
}
