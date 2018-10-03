/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processing_p.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarev <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 19:09:35 by skarev            #+#    #+#             */
/*   Updated: 2018/09/17 19:09:36 by skarev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	processing_p(t_arg *arg, va_list *ap)
{
	char	*buf;

	arg->x_content = va_arg(*ap, unsigned long);
	arg->content = ft_itoa_base_ull(arg->x_content, 16);
	arg->content_len = ft_strlen(arg->content);
	if (arg->bitmap & PRECISION && arg->precision == 0 && arg->x_content == 0)
	{
		free(arg->content);
		arg->content = ft_strdup("0x");
		arg->content_len = 2;
	}
	else
	{
		positive_content(arg);
		buf = ft_strdup(arg->content);
		free(arg->content);
		arg->content = ft_strjoin("0x", buf);
		arg->content_len += 2;
		free(buf);
		p_processing_width(arg);
	}
}

void	p_processing_width(t_arg *arg)
{
	int		i;
	int		len;
	char	*buf;
	char	*tmp;

	i = 0;
	len = arg->width - arg->content_len;
	if (arg->bitmap & ZERO && arg->x_content == 0)
	{
		buf = ft_strnew(len);
		while (len--)
			buf[i++] = '0';
		tmp = ft_strdup(arg->content);
		free(arg->content);
		arg->content = ft_strjoin(tmp, buf);
		arg->content_len = ft_strlen(arg->content);
		free(tmp);
		free(buf);
	}
	else
		x_processing_width(arg);
}
