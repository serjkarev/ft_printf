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
	int			byte;
	va_list		ap;

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
			// if (arg->content)
			// 	free(arg->content);
			// free(arg);
		}
		else
		{
			i2 += 1;
		}
	}
	len += print(format, i, i2);
	return (len);
}

t_arg		*create_new_arg(void)
{
	t_arg	*new_arg;

	if(!(new_arg = (t_arg*)malloc(sizeof(t_arg))))
		return (NULL);
	new_arg->bitmap = 0;
	new_arg->i = 0;
	new_arg->width = 0;
	new_arg->precision = 0;
	new_arg->d_content = 0;
	new_arg->x_content = 0;
	new_arg->content = NULL;
	new_arg->content_len = 0;
	return (new_arg);
}

int		fill_arg(int *i, const char *format, t_arg *arg, va_list *ap)
{
	int		available_type;

	available_type = 0;
	arg->i = (int)*i;
	*i += 1;
	parce_flag(i, arg, format);
	parce_width(i, arg, format, ap);
	parce_precision(i, arg, format, ap);
	parce_length(i, arg, format);
	available_type = parce_type(i, arg, format);
	if (available_type == 1)
	{
		type_processing(arg, ap);
	}
	// printf("/////////////////////////////////////////////////////////////\n");
	// printf("bitmap = %x\n", arg->bitmap);
	// printf("d_content = %lld\n", arg->d_content);
	// printf("content = |%s|\n", arg->content);
	// printf("i = %d\n", arg->i);
	// printf("content_len = %lld\n", arg->content_len);
	return (write(1, arg->content, arg->content_len));
}

void	type_processing(t_arg *arg, va_list *ap)
{
	if (arg->bitmap & SMALL_D || arg->bitmap & BIG_D)
		arg->bitmap & SMALL_D ? processing_d(arg, ap) : processing_D(arg, ap);
	else if (arg->bitmap & SMALL_S || arg->bitmap & BIG_S)
		arg->bitmap & SMALL_S ? processing_s(arg, ap) : processing_S(arg, ap);
	else if (arg->bitmap & SMALL_O || arg->bitmap & BIG_O)
		processing_o(arg, ap);
	// 	arg->bitmap & SMALL_O ? processing_o(arg, ap) : processing_O(arg, ap);
	else if (arg->bitmap & SMALL_U || arg->bitmap & BIG_U)
		processing_u(arg, ap);
	// 	arg->bitmap & SMALL_U ? processing_u(arg, ap) : processing_U(arg, ap);
	else if (arg->bitmap & SMALL_X || arg->bitmap & BIG_X)
		processing_x(arg, ap);
		// arg->bitmap & SMALL_X ? processing_x(arg, ap) : processing_X(arg, ap);
	else if (arg->bitmap & SMALL_C || arg->bitmap & BIG_C)
		processing_c(arg, ap);
		// arg->bitmap & SMALL_C ? processing_c(arg, ap) : processing_C(arg, ap);
	else if (arg->bitmap & P || arg->bitmap & I)
		arg->bitmap & P ? processing_p(arg, ap) : processing_i(arg, ap);
	else if (arg->bitmap & PERCENT)
		processing_percent(arg);
}