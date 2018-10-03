/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processing_percent.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarev <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 17:24:27 by skarev            #+#    #+#             */
/*   Updated: 2018/09/17 17:24:28 by skarev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	processing_percent(t_arg *arg)
{
	percent_processing_type(arg);
	percent_processing_width(arg);
	percent_processing_flags(arg);
}

void	percent_processing_type(t_arg *arg)
{
	char	*buf;

	buf = ft_strnew(1);
	buf[0] = '%';
	arg->content = ft_strdup(buf);
	arg->content_len = ft_strlen(arg->content);
	ft_strdel(&buf);
}

void	percent_processing_width(t_arg *arg)
{
	if ((arg->width > arg->content_len) && arg->bitmap & WIDTH)
	{
		if (arg->bitmap & MINUS)
			minus_width_mod(arg);
		else
			only_width_mod(arg);
		arg->content_len = ft_strlen(arg->content);
	}
}

void	percent_processing_flags(t_arg *arg)
{
	int		i;

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
