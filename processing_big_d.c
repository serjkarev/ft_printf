/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processing_big_d.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarev <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 20:37:14 by skarev            #+#    #+#             */
/*   Updated: 2018/09/17 20:37:14 by skarev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	processing_b_d(t_arg *arg, va_list *ap)
{
	d_big_processing_type(arg, ap);
	d_big_processing_precision(arg);
	d_big_processing_flags(arg);
	d_big_processing_width(arg);
}

void	d_big_processing_type(t_arg *arg, va_list *ap)
{
	arg->d_content = va_arg(*ap, long);
	arg->content = ft_itoa_ll(arg->d_content);
	arg->content_len = ft_strlen(arg->content);
}

void	d_big_processing_precision(t_arg *arg)
{
	if (arg->d_content < 0)
		negative_content(arg);
	else
		positive_content(arg);
}

void	d_big_processing_flags(t_arg *arg)
{
	char	*buf;

	if (arg->d_content >= 0)
	{
		buf = ft_strnew(arg->content_len + 1);
		if (arg->bitmap & PLUS)
		{
			buf[0] = '+';
			buf = ft_strjoin(buf, arg->content);
			free(arg->content);
			arg->content = ft_strdup(buf);
			arg->content_len += 1;
		}
		else if (arg->bitmap & SPACE)
		{
			buf[0] = ' ';
			buf = ft_strjoin(buf, arg->content);
			free(arg->content);
			arg->content = ft_strdup(buf);
			arg->content_len += 1;
		}
		free(buf);
	}
}

void	d_big_processing_width(t_arg *arg)
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
