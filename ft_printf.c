/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarev <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 12:31:52 by skarev            #+#    #+#             */
/*   Updated: 2018/07/18 12:31:53 by skarev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	int		byte;
	va_list	ap;

	va_start(ap, format);
	byte = start_parce(&ap, format);
	va_end(ap);
	return (byte);
}

int		start_parce(va_list *ap, const char *format)
{
	int		i;
	int		i2;
	int		len;
	t_arg	*arg;

	i = 0;
	i2 = 0;
	len = 0;
	while (format[i2])
	{
		if (format[i2] == '%')
		{
			len += print(format, i, i2);
			i = i2;
			arg = create_new_arg();
			len += fill_arg(&i, format, arg, ap);
			i2 = i;
			free_struct(arg);
		}
		else
			i2 += 1;
	}
	len += print(format, i, i2);
	return (len);
}

t_arg	*create_new_arg(void)
{
	t_arg	*new_arg;

	if (!(new_arg = (t_arg*)malloc(sizeof(t_arg))))
		return (NULL);
	new_arg->bitmap = 0;
	new_arg->i = 0;
	new_arg->width = 0;
	new_arg->precision = 0;
	new_arg->d_content = 0;
	new_arg->x_content = 0;
	new_arg->content = NULL;
	new_arg->content_len = 0;
	new_arg->non_valid = 0;
	new_arg->content_char = 0;
	return (new_arg);
}

int		fill_arg(int *i, const char *format, t_arg *arg, va_list *ap)
{
	int		available_type;

	arg->i = (int)*i;
	*i += 1;
	parce_flag(i, arg, format);
	parce_width(i, arg, format, ap);
	parce_precision(i, arg, format, ap);
	parce_length(i, arg, format);
	available_type = parce_type(i, arg, format);
	if (available_type == 1)
	{
		wildcard_processing(arg);
		type_processing(arg, ap);
	}
	if (arg->bitmap & BIG_C || arg->bitmap & BIG_S || \
				(arg->bitmap & SMALL_C && arg->bitmap & L) || \
				(arg->bitmap & SMALL_S && arg->bitmap & L))
		return (arg->content_len);
	else
	{
		if (arg->bitmap & JOPA)
			return (arg->content_len);
		else
			return (write(1, arg->content, arg->content_len));
	}
}

void	type_processing(t_arg *arg, va_list *ap)
{
	if (arg->bitmap & SMALL_D || arg->bitmap & BIG_D)
		arg->bitmap & SMALL_D ? processing_d(arg, ap) : processing_b_d(arg, ap);
	else if (arg->bitmap & SMALL_S || arg->bitmap & BIG_S)
		helper_1(arg, ap);
	else if (arg->bitmap & SMALL_O || arg->bitmap & BIG_O)
		arg->bitmap & SMALL_O ? processing_o(arg, ap) : processing_b_o(arg, ap);
	else if (arg->bitmap & SMALL_U || arg->bitmap & BIG_U)
		arg->bitmap & SMALL_U ? processing_u(arg, ap) : processing_b_u(arg, ap);
	else if (arg->bitmap & SMALL_X || arg->bitmap & BIG_X)
		arg->bitmap & SMALL_X ? processing_x(arg, ap) : processing_b_x(arg, ap);
	else if (arg->bitmap & SMALL_C || arg->bitmap & BIG_C)
		helper_2(arg, ap);
	else if (arg->bitmap & P || arg->bitmap & I)
		arg->bitmap & P ? processing_p(arg, ap) : processing_i(arg, ap);
	else if (arg->bitmap & PERCENT || arg->bitmap & BINARY)
		arg->bitmap & PERCENT ? processing_percent(arg) : proc_binary(arg, ap);
}
