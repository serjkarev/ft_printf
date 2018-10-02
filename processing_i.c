/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processing_i.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarev <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 21:26:58 by skarev            #+#    #+#             */
/*   Updated: 2018/09/17 21:26:59 by skarev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	processing_i(t_arg *arg, va_list *ap)
{
	i_processing_type(arg, ap);
	i_processing_precision(arg);
	i_processing_flags(arg);
	i_processing_width(arg);
}

void	i_processing_type(t_arg *arg, va_list *ap)
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
	if (arg->d_content == 0 && arg->precision == 0 && arg->bitmap & PRECISION)
		arg->content = ft_strdup("");
	else
		arg->content = ft_itoa_ll(arg->d_content);
	arg->content_len = ft_strlen(arg->content);
}

void	i_processing_precision(t_arg *arg)
{
	if (arg->d_content < 0)
		negative_content(arg);
	else
		positive_content(arg);
}

void	i_processing_flags(t_arg *arg)
{
	char	*buf;
	char	*tmp;

	if (arg->d_content >= 0)
	{
		buf = ft_strnew(arg->content_len + 1);
		if (arg->bitmap & PLUS)
		{
			buf[0] = '+';
			tmp = ft_strjoin(buf, arg->content);
			free(arg->content);
			arg->content = ft_strdup(tmp);
			arg->content_len += 1;
			free(tmp);
		}
		else if (arg->bitmap & SPACE)
		{
			buf[0] = ' ';
			tmp = ft_strjoin(buf, arg->content);
			free(arg->content);
			arg->content = ft_strdup(tmp);
			arg->content_len += 1;
			free(tmp);
		}
		free(buf);
	}
}

void	i_processing_width(t_arg *arg)
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
