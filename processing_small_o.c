/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processing_small_o.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarev <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/16 19:56:49 by skarev            #+#    #+#             */
/*   Updated: 2018/09/16 19:56:49 by skarev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	processing_o(t_arg *arg, va_list *ap)
{
	o_processing_type(arg, ap);
	if (arg->x_content == 0 && arg->width != 0 && arg->precision == 0)
	{
		free(arg->content);
		arg->content = ft_strdup(" ");
	}
	else if (arg->x_content == 0 && arg->bitmap & PRECISION && arg->precision == 0)
	{
		free(arg->content);
		arg->content = ft_strdup("");
	}
	o_processing_precision(arg);
	o_processing_flags(arg);
	o_processing_width(arg);
}

void	o_processing_type(t_arg *arg, va_list *ap)
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
		arg->x_content = va_arg(*ap, unsigned long);
	else
		arg->x_content = va_arg(*ap, unsigned int);
	arg->content = ft_itoa_base_ull(arg->x_content, 8);
	arg->content_len = ft_strlen(arg->content);
}

void	o_processing_precision(t_arg *arg)
{
	int		i;
	int		len;
	int		precision;
	char	*buf;
	char	*tmp;
	char	*tmp2;

	i = 0;
	if (arg->precision != 0)
	{
		len = arg->content_len;
		precision = arg->precision;
		buf = ft_strnew(len + precision);
		while (precision > len)
		{
			buf[i] = '0';
			i++;
			precision -= 1;
		}
		tmp = ft_strsub(arg->content, 0, arg->content_len);
		tmp2 = ft_strdup(buf);
		free(buf);
		buf = ft_strjoin(tmp2, tmp);
		free(arg->content);
		arg->content = ft_strdup(buf);
		arg->content_len = ft_strlen(arg->content);
		free(buf);
		free(tmp);
		free(tmp2);
	}
	else if (arg->x_content == 0 && arg->bitmap & PRECISION && arg->precision == 0 && arg->bitmap & HESH)
	{
		free(arg->content);
		arg->content = ft_strdup("0");
	}
}

void	o_processing_flags(t_arg *arg)
{
	char	*buf;

	if (arg->bitmap & HESH && arg->x_content != 0 && arg->precision == 0)
	{
		buf = ft_strdup(arg->content);
		free(arg->content);
		arg->content = ft_strjoin("0", buf);
		free(buf);
	}
	else if (arg->bitmap & HESH && arg->bitmap & WIDTH && !(arg->bitmap & PRECISION))
	{
		buf = ft_strdup(arg->content);
		free(arg->content);
		arg->content = ft_strjoin(" ", buf);
		free(buf);
	}
	arg->content_len = ft_strlen(arg->content);
}

void	o_processing_width(t_arg *arg)
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
