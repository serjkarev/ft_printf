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

void    processing_p(t_arg *arg, va_list *ap)
{
    arg->x_content = va_arg(*ap, unsigned long);
    arg->content = ft_itoa_base_ull(arg->x_content, 16);
    arg->content = ft_strjoin("0x", arg->content);
    arg->content_len = ft_strlen(arg->content);
}

