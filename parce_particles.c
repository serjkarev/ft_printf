/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parce_particles.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarev <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 20:19:14 by skarev            #+#    #+#             */
/*   Updated: 2018/09/06 20:19:15 by skarev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	parce_flag(int *i, t_arg *arg, const char *format)
{
	while (1)
	{
		if (format[*i] == '#')
			arg->bitmap = arg->bitmap | HESH;
		else if (format[*i] == '0')
			arg->bitmap = arg->bitmap | ZERO;
		else if (format[*i] == '-')
			arg->bitmap = arg->bitmap | MINUS;
		else if (format[*i] == '+')
			arg->bitmap = arg->bitmap | PLUS;
		else if (format[*i] == ' ')
			arg->bitmap = arg->bitmap | SPACE;
		else
			break ;
		*i += 1;
	}
}

void	parce_width(int *i, t_arg *arg, const char *format, va_list *ap)
{
	if (ft_isdigit(format[*i]))
	{
		arg->bitmap = arg->bitmap | WIDTH;
		arg->width = ft_atoi(&format[*i]);
	}
	while (ft_isdigit(format[*i]))
		*i += 1;
	if (format[*i] == '*')
	{
		*i += 1;
		arg->width = va_arg(*ap, int);
	}
}

void	parce_precision(int *i, t_arg *arg, const char *format, va_list *ap)
{
	if (format[*i] == '.')
	{
		*i += 1;
		arg->bitmap = arg->bitmap | PRECISION;
		if (format[*i] == '*')
		{
			*i += 1;
			arg->precision = va_arg(*ap, int);
		}
		else if (ft_isdigit(format[*i]))
		{
			arg->precision = ft_atoi(&format[*i]);
			while (ft_isdigit(format[*i]))
				*i += 1;
		}
	}
}

void	parce_length(int *i, t_arg *arg, const char *format)
{
	if (format[*i] == 'z')
		arg->bitmap = arg->bitmap | Z;
	else if (format[*i] == 'j')
		arg->bitmap = arg->bitmap | J;
	else if (format[*i] == 'l' && format[*i + 1] == 'l')
		arg->bitmap = arg->bitmap | LL;
	else if (format[*i] == 'h' && format[*i + 1] == 'h')
		arg->bitmap = arg->bitmap | HH;
	else if (format[*i] == 'l')
		arg->bitmap = arg->bitmap | L;
	else if (format[*i] == 'h')
		arg->bitmap = arg->bitmap | H;
	while (format[*i] == 'z' || format[*i] == 'j' || format[*i] == 'l' ||\
		format[*i] == 'h')
		*i += 1;
}

int		parce_type(int *i, t_arg *arg, const char *format)
{
	if (format[*i] == 'p' || format[*i] == 'i')
		parce_helper_1(arg, format[*i]);
	else if (format[*i] == 's' || format[*i] == 'S')
		parce_helper_2(arg, format[*i]);
	else if (format[*i] == 'd' || format[*i] == 'D')
		parce_helper_3(arg, format[*i]);
	else if (format[*i] == 'o' || format[*i] == 'O')
		parce_helper_4(arg, format[*i]);
	else if (format[*i] == 'u' || format[*i] == 'U')
		parce_helper_5(arg, format[*i]);
	else if (format[*i] == 'x' || format[*i] == 'X')
		parce_helper_6(arg, format[*i]);
	else if (format[*i] == 'c' || format[*i] == 'C')
		parce_helper_7(arg, format[*i]);
	else if (format[*i] == '%' || format[*i] == 'b')
		parce_helper_8(arg, format[*i]);
	else
	{
		if (arg->bitmap & WIDTH)
			invalid_conversion_specifier(arg, format, i);
		return (0);
	}
	*i += 1;
	arg->i = (int)*i;
	return (1);
}
