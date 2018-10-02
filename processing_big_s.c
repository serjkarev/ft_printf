/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processing_big_s.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarev <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 23:18:28 by skarev            #+#    #+#             */
/*   Updated: 2018/09/17 23:18:28 by skarev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	processing_b_s(t_arg *arg, va_list *ap)
{
	int		i;
	int		*buf;

	i = 0;
	if (!(buf = va_arg(*ap, int*)))
	{
		write(1, "(null)", 6);
		arg->content_len += 6;
	}
	else if (!(arg->bitmap & PRECISION))
	{
		while (buf[i])
		{
			arg->d_content += count_bytes(buf[i]);
			i++;
		}
		s_big_processing_width(arg);
		s_big_processing_flags(arg, buf);
	}
	else
		s_big_processing_precision(arg);
}

void	s_big_processing_width(t_arg *arg)
{
	int		i;
	int		len;
	char	*buf;

	i = 0;
	len = arg->width - arg->d_content;
	buf = ft_strnew(len);
	if (arg->bitmap & WIDTH)
	{
		if (arg->bitmap & ZERO)
		{
			while (len)
			{
				buf[i] = '0';
				i++;
				len -= 1;
			}
		}
		else
		{
			while (len)
			{
				buf[i] = ' ';
				i++;
				len -= 1;
			}
		}
		arg->content = ft_strdup(buf);
		arg->content_len = i;
	}
	free(buf);
}

void	s_big_processing_flags(t_arg *arg, int *buf)
{
	if (arg->bitmap & MINUS)
	{
		print_unicode(arg, buf);
		ft_putstr(arg->content);
	}
	else
	{
		ft_putstr(arg->content);
		print_unicode(arg, buf);
	}
}

void	print_unicode(t_arg *arg, int *buf)
{
	int		i;
	int		byte;

	i = 0;
	byte = 0;
	if (buf)
	{
		while (buf[i])
		{
			byte = count_bytes(buf[i]);
			print_bytes(byte, buf[i]);
			arg->content_len += byte;
			i += 1;
		}
	}
	else
		arg->content_len = write(1, "(null)", 6);
}

void    s_big_processing_precision(t_arg *arg)
{
	if (arg->bitmap & WIDTH && arg->precision == 0 && arg->bitmap & PRECISION)
	{
		s_big_processing_width(arg);
		write(1, arg->content, arg->content_len);
	}
}