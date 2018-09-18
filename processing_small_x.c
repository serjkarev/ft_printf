/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processing_small_x.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarev <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/15 17:34:45 by skarev            #+#    #+#             */
/*   Updated: 2018/09/15 17:34:45 by skarev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    processing_x(t_arg *arg, va_list *ap)
{
    x_processing_type(arg, ap);
	x_processing_precision(arg);
	x_processing_flags(arg);
	x_processing_width(arg);
}

void    x_processing_type(t_arg *arg, va_list *ap)
{
	if (arg->bitmap & L || arg->bitmap & BIG_X)
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
	if (arg->bitmap & BIG_X)
		arg->content = ft_itoa_base_ull_big(arg->x_content, 16);
	else
		arg->content = ft_itoa_base_ull(arg->x_content, 16);
	arg->content_len = ft_strlen(arg->content);
}

void	x_processing_precision(t_arg *arg)
{
	positive_content(arg);
}

void	x_processing_flags(t_arg *arg)
{
	if (arg->bitmap & HESH && arg->x_content > 0)
	{
		if (arg->bitmap & BIG_X)
			arg->content = ft_strjoin("0X", arg->content);
		else
			arg->content = ft_strjoin("0x", arg->content);
		arg->content_len += 2;
	}
}

void	x_processing_width(t_arg *arg)
{
	if ((arg->width > arg->content_len) && arg->bitmap & WIDTH)
	{
		if (arg->bitmap & MINUS)
			minus_width(arg);
		else if ((arg->bitmap & ZERO) && !(arg->bitmap & PRECISION) && !(arg->bitmap & HESH))
			zero_width(arg);
		else if ((arg->bitmap & ZERO) && !(arg->bitmap & PRECISION) && (arg->bitmap & HESH))
			zero_width_mod(arg);
		else
			only_width(arg);
	}
	arg->content_len = ft_strlen(arg->content);
}

// void getBinary(long long n)
// {
//     int loop;
//     /*loop=7 , for 8 bits value, 7th bit to 0th bit*/
//     for(loop=31; loop>=0; loop--)
//     {
//         if( (1 << loop) & n)
//             printf("1");
//         else
//             printf("0");
//     }
// }