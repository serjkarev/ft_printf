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

void    processing_u(t_arg *arg, va_list *ap)
{
    u_processing_type(arg, ap);
    u_processong_precision(arg);
    u_processing_width(arg);
}

void    u_processing_type(t_arg *arg, va_list *ap)
{
    if (arg->bitmap & L || arg->bitmap & BIG_U)
        arg->d_content = va_arg(*ap, unsigned long);
    else if (arg->bitmap & LL)
        arg->d_content = va_arg(*ap, unsigned long long);
    else if (arg->bitmap & J)
        arg->d_content = va_arg(*ap, unsigned long);
    else
        arg->d_content = va_arg(*ap, unsigned int);
    arg->content = ft_itoa_u(arg->d_content);//який itoa юзать???
    arg->content_len = ft_strlen(arg->content);
}

void    u_processong_precision(t_arg *arg)
{
    positive_content(arg);
}

void    u_processing_width(t_arg *arg)
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
