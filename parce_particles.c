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
	while(1)
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
			break;
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
		format[*i] == 'p' ? (arg->bitmap = arg->bitmap | P) : \
							(arg->bitmap = arg->bitmap | I);
	else if (format[*i] == 's' || format[*i] == 'S')
		format[*i] == 's' ? (arg->bitmap = arg->bitmap | SMALL_S) : \
							(arg->bitmap = arg->bitmap | BIG_S);
	else if (format[*i] == 'd' || format[*i] == 'D')
		format[*i] == 'd' ? (arg->bitmap = arg->bitmap | SMALL_D) : \
							(arg->bitmap = arg->bitmap | BIG_D);
	else if (format[*i] == 'o' || format[*i] == 'O')
		format[*i] == 'o' ? (arg->bitmap = arg->bitmap | SMALL_O) : \
							(arg->bitmap = arg->bitmap | BIG_O);
	else if (format[*i] == 'u' || format[*i] == 'U')
		format[*i] == 'u' ? (arg->bitmap = arg->bitmap | SMALL_U) : \
							(arg->bitmap = arg->bitmap | BIG_U);
	else if (format[*i] == 'x' || format[*i] == 'X')
		format[*i] == 'x' ? (arg->bitmap = arg->bitmap | SMALL_X) : \
							(arg->bitmap = arg->bitmap | BIG_X);
	else if (format[*i] == 'c' || format[*i] == 'C')
		format[*i] == 'c' ? (arg->bitmap = arg->bitmap | SMALL_C) : \
							(arg->bitmap = arg->bitmap | BIG_C);
	else if (format[*i] == '%')
		arg->bitmap = arg->bitmap | PERCENT;
	else if (ft_isalpha(format[*i]) && !ft_isalpha(format[*i + 1]) \
											&& arg->bitmap & WIDTH)
	{
		arg->content_char = format[*i];
		*i += 1;
		arg->i = (int)*i;
		return (2);
	}
	else
		return (0);
	*i += 1;
	arg->i = (int)*i;
	return(1);
}
