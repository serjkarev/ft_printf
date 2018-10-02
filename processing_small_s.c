/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processing_small_s.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarev <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 20:17:02 by skarev            #+#    #+#             */
/*   Updated: 2018/09/14 20:17:02 by skarev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	processing_s(t_arg *arg, va_list *ap)
{
	s_processing_type(arg, ap);
	s_processing_precision(arg);
	s_processing_width(arg);
}

void	s_processing_type(t_arg *arg, va_list *ap)
{
	char	*buf;

	buf = va_arg(*ap, char*);
	if (buf == NULL)
		arg->content = ft_strdup("(null)");
	else
		arg->content = ft_strdup(buf);
	arg->content_len = ft_strlen(arg->content);
}

void	s_processing_precision(t_arg *arg)
{
	if (arg->bitmap & PRECISION)
	{
		free(arg->content);
		arg->content = ft_strsub(arg->content, 0, arg->precision);
		arg->content_len = ft_strlen(arg->content);
	}
}

void	s_processing_width(t_arg *arg)
{
	if ((arg->width > arg->content_len) && arg->width)
	{
		if (arg->bitmap & MINUS)
			minus_width(arg);
		else if (arg->bitmap & ZERO && arg->width)
			zero_width(arg);
		else
			only_width(arg);
		arg->content_len = ft_strlen(arg->content);
	}
}
