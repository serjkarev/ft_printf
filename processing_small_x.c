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

void	processing_x(t_arg *arg, va_list *ap)
{
	char	*tmp;

	x_processing_type(arg, ap);
	positive_content(arg);
	if (arg->bitmap & HESH && arg->x_content > 0)
	{
		tmp = ft_strdup(arg->content);
		free(arg->content);
		arg->content = ft_strjoin("0x", tmp);
		arg->content_len += 2;
		free(tmp);
	}
	x_processing_width(arg);
}

void	x_processing_type(t_arg *arg, va_list *ap)
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
		arg->x_content = (unsigned long)va_arg(*ap, long);
	else
		arg->x_content = va_arg(*ap, unsigned int);
	if ((arg->x_content == 0 && arg->bitmap & PRECISION))
		arg->non_valid = 228;
	else
		arg->content = ft_itoa_base_ull(arg->x_content, 16);
	arg->content_len = ft_strlen(arg->content);
}

void	x_processing_width(t_arg *arg)
{
	if ((arg->width > arg->content_len) && arg->width)
	{
		if (arg->bitmap & MINUS)
			minus_width(arg);
		else if ((arg->bitmap & ZERO) && !(arg->bitmap & PRECISION) && \
													!(arg->bitmap & HESH))
			zero_width(arg);
		else if ((arg->bitmap & ZERO) && !(arg->bitmap & PRECISION) && \
														(arg->bitmap & HESH))
			zero_width_mod(arg);
		else
			only_width(arg);
	}
	arg->content_len = ft_strlen(arg->content);
}
