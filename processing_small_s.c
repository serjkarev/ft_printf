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

void    processing_s(t_arg *arg, va_list *ap)
{
    // if (ap == NULL)
    // {
    //     arg->content = ft_strnew(6);
    //     arg->content = ft_strdup("(null)");
    //     //что боять делать???
    // }
    s_processing_type(arg, ap);
	s_processing_precision(arg);
	s_processing_width(arg);
}

void    s_processing_type(t_arg *arg, va_list *ap)
{
    char    *buf;

    buf = ft_strnew(1);
    buf = va_arg(*ap, char*);
    arg->content = ft_strdup(buf);
    arg->content_len = ft_strlen(arg->content);
}

void	s_processing_precision(t_arg *arg)
{
    if (arg->bitmap & PRECISION)
    {
        arg->content = ft_strsub(arg->content, 0, arg->precision);
        arg->content_len = ft_strlen(arg->content);
    }
}

void	s_processing_width(t_arg *arg)
{
    if ((arg->width > arg->content_len) && arg->bitmap & WIDTH)
    {
        if (arg->bitmap & MINUS)
            minus_width(arg);
        else
            only_width(arg);
        arg->content_len = ft_strlen(arg->content);
    }
}
