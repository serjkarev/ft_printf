/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processing_p.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarev <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 19:09:35 by skarev            #+#    #+#             */
/*   Updated: 2018/09/17 19:09:36 by skarev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	processing_p(t_arg *arg, va_list *ap)
{
	arg->x_content = va_arg(*ap, unsigned long);
	arg->content = ft_itoa_base_ull(arg->x_content, 16);
	arg->content_len = ft_strlen(arg->content);
	if (arg->bitmap & PRECISION && arg->precision == 0 && arg->x_content == 0)
	{
		arg->content = ft_strdup("0x");
		arg->content_len = 2;
	}
	else
	{
		p_processing_precision(arg);
		p_processing_flags(arg);
		p_processing_width(arg);
	}
}

void	p_processing_precision(t_arg *arg)
{
	positive_content(arg);
}

void	p_processing_flags(t_arg *arg)
{
	arg->content = ft_strjoin("0x", arg->content);
	arg->content_len += 2;
}

void	p_processing_width(t_arg *arg)
{
	x_processing_width(arg);
}
