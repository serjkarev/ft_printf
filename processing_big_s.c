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

void    processing_S(t_arg *arg, va_list *ap)
{
	// unsigned long	buf;
	wchar_t		s1;
	wchar_t		s2;

	setlocale(LC_ALL, "");
	s1 = va_arg(*ap, wchar_t);
	// printf("buf_bef = %lu\n", buf);
	s1 = s1 << 16;
	s2 = va_arg(*ap, wchar_t);
	s2 = s2 >> 16;
	printf("s1 = %d\n", s1);
	printf("s2 = %d\n", s2);
	// printf("buf = %lu\n", buf);

}

// void    S_processing_type(t_arg *arg, va_list *ap)
// {

// }

// void	S_processing_precision(t_arg *arg)
// {

// }

// void	S_processing_width(t_arg *arg)
// {

// }
