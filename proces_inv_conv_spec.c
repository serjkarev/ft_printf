/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proces_inv_conv_spec.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarev <skarev@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/29 22:07:37 by skarev            #+#    #+#             */
/*   Updated: 2018/09/29 22:07:38 by skarev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	invalid_conversion_specifier(t_arg *arg)
{
	ics_processing_width(arg);
}

void	ics_processing_width(t_arg *arg)
{
	int		i;
	int		len;
	char	*buf;

	i = 0;
	len = arg->width - 1;
	buf = (char*)malloc(sizeof(char));
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
		ics_processing_flags(arg, buf);
	}
}

void	ics_processing_flags(t_arg *arg, char *buf)
{
	if (arg->bitmap & MINUS)
	{
		write(1, &arg->content_char, 1);
		write(1, buf, arg->width);
	}
	else
	{
		write(1, buf, arg->width);
		write(1, &arg->content_char, 1);
	}
	arg->content_len = ft_strlen(buf) + 1;
}
