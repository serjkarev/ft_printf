/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processing_small_d.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarev <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 19:04:21 by skarev            #+#    #+#             */
/*   Updated: 2018/09/10 19:04:23 by skarev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	processing_d(t_arg *arg, va_list *ap)
{
	d_processing_type(arg, ap);
	if (arg->d_content == 0 && arg->width != 0 && arg->precision == 0 && \
														!(arg->bitmap & ZERO))
	{
		free(arg->content);
		arg->content = ft_strdup(" ");
	}
	else if (arg->d_content == 0 && arg->bitmap & PRECISION && \
												arg->precision == 0)
	{
		free(arg->content);
		arg->content = ft_strdup("");
	}
	else if (arg->d_content == 0 && arg->bitmap & ZERO && \
	arg->bitmap & WIDTH && (arg->bitmap & PLUS || arg->bitmap & MINUS || \
														arg->bitmap & SPACE))
	{
		free(arg->content);
		arg->content = ft_strdup("0");
	}
	d_processing_precision(arg);
	d_processing_flags(arg);
	d_processing_width(arg);
}

void	d_processing_type(t_arg *arg, va_list *ap)
{
	if (arg->bitmap & L)
		arg->d_content = va_arg(*ap, long);
	else if (arg->bitmap & LL)
		arg->d_content = va_arg(*ap, long long);
	else if (arg->bitmap & H)
		arg->d_content = (short)va_arg(*ap, int);
	else if (arg->bitmap & HH)
		arg->d_content = (char)va_arg(*ap, int);
	else if (arg->bitmap & Z)
		arg->d_content = va_arg(*ap, size_t);
	else if (arg->bitmap & J)
		arg->d_content = va_arg(*ap, long);
	else
		arg->d_content = va_arg(*ap, int);
	arg->content = ft_itoa_ll(arg->d_content);
	arg->content_len = ft_strlen(arg->content);
}

void	d_processing_precision(t_arg *arg)
{
	if (arg->d_content < 0)
		negative_content(arg);
	else
		positive_content(arg);
}

void	d_processing_flags(t_arg *arg)
{
	char	*buf;
	char	*tmp;

	if (arg->d_content >= 0)
	{
		if (arg->bitmap & PLUS)
		{
			buf = "+";
			tmp = ft_strjoin(buf, arg->content);
			free(arg->content);
			arg->content = ft_strdup(tmp);
			arg->content_len += 1;
			free(tmp);
		}
		else if (arg->bitmap & SPACE)
		{
			buf = " ";
			tmp = ft_strjoin(buf, arg->content);
			free(arg->content);
			arg->content = ft_strdup(tmp);
			arg->content_len += 1;
			free(tmp);
		}
	}
}

void	d_processing_width(t_arg *arg)
{
	if ((arg->width > arg->content_len) && arg->width)
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
