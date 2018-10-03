/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processing_small_c.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarev <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/16 21:21:02 by skarev            #+#    #+#             */
/*   Updated: 2018/09/16 21:21:02 by skarev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	processing_c(t_arg *arg, va_list *ap)
{
	c_processing_type(arg, ap);
	c_processing_width(arg);
	c_processing_flags(arg);
	if (arg->x_content == 0)
		arg->content_len += 1;
}

void	c_processing_type(t_arg *arg, va_list *ap)
{
	unsigned char	c;
	char			*buf;

	arg->x_content = va_arg(*ap, int);
	c = (unsigned char)arg->x_content;
	buf = ft_strnew(1);
	buf[0] = c;
	arg->content = ft_strdup(buf);
	arg->content_len = ft_strlen(arg->content);
	free(buf);
}

void	c_processing_width(t_arg *arg)
{
	if ((arg->width > arg->content_len) && arg->width)
	{
		if (arg->bitmap & MINUS)
			minus_width_mod(arg);
		else
			only_width_mod(arg);
		arg->content_len = ft_strlen(arg->content);
	}
}

void	c_processing_flags(t_arg *arg)
{
	int	i;

	i = 0;
	if ((arg->bitmap & ZERO) && !(arg->bitmap & MINUS))
	{
		while (i < arg->width - 1)
		{
			arg->content[i] = '0';
			i += 1;
		}
	}
}
