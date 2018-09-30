/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processing_big_c.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarev <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 20:33:50 by skarev            #+#    #+#             */
/*   Updated: 2018/09/21 20:33:51 by skarev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	processing_C(t_arg *arg, va_list *ap)
{
	int			byte;
	wchar_t		buf;

	buf = va_arg(*ap, wchar_t);
	byte = count_bytes(buf);
	print_bytes(byte, buf);
	arg->content_len = byte;
}

int		count_bytes(int num)
{
	if (num < 127)
		return (1);
	else if (num < 2047)
		return (2);
	else if (num < 65535)
		return (3);
	else
		return (4);
}

void	print_bytes(int byte, wchar_t buf)
{
	if (byte == 1)
		ft_putchar(buf);
	else if (byte == 2)
	{
		ft_putchar((buf >> 6) | 0xC0);
		ft_putchar((buf & 0x3F) | 0x80);
	}
	else if (byte == 3)
	{
		ft_putchar((buf >> 12) | 0xE0);
		ft_putchar(((buf >> 6) & 0x3F) | 0x80);
		ft_putchar((buf & 0x3F) | 0x80);
	}
	else if (byte == 4)
	{
		ft_putchar((buf >> 18) | 0xF0);
		ft_putchar(((buf >> 12) & 0x3F) | 0x80);
		ft_putchar(((buf >> 6) & 0x3F) | 0x80);
		ft_putchar((buf & 0x3F) | 0x80);
	}
}
