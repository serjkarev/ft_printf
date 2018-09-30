/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processing_big_u.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarev <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 19:10:26 by skarev            #+#    #+#             */
/*   Updated: 2018/09/21 19:10:27 by skarev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	processing_b_u(t_arg *arg, va_list *ap)
{
	u_big_processing_type(arg, ap);
	u_big_processong_precision(arg);
	u_big_processing_width(arg);
}

void	u_big_processing_type(t_arg *arg, va_list *ap)
{
	arg->d_content = va_arg(*ap, unsigned long);
	arg->content = ft_itoa_base_ull(arg->d_content, 10);
	arg->content_len = ft_strlen(arg->content);
}

void	u_big_processong_precision(t_arg *arg)
{
	positive_content(arg);
}

void	u_big_processing_width(t_arg *arg)
{
	u_processing_width(arg);
}
