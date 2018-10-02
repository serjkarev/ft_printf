/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarev <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 12:32:37 by skarev            #+#    #+#             */
/*   Updated: 2018/07/18 12:32:38 by skarev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "./libft/libft.h"
# include <fcntl.h>
# include <stdarg.h>
# include <stdio.h>
# include <locale.h>

# define PERCENT		0X80000000

# define HESH			0X40000000
# define ZERO			0X20000000
# define MINUS			0X10000000
# define PLUS			0X8000000
# define SPACE			0X4000000

# define WIDTH			0X2000000
# define PRECISION		0X1000000

# define H				0X800000
# define HH				0X400000
# define L				0X200000
# define LL				0X100000
# define J				0X80000
# define Z				0X40000

# define SMALL_S		0X20000
# define BIG_S			0X10000
# define P				0X8000
# define SMALL_D		0X4000
# define BIG_D			0X2000
# define I				0X1000
# define SMALL_O		0X800
# define BIG_O			0X400
# define SMALL_U		0X200
# define BIG_U			0X100
# define SMALL_X		0X80
# define BIG_X			0X40
# define SMALL_C		0X20
# define BIG_C			0X10
# define JOPA			0X8
# define BINARY			0X4

typedef struct		s_arg
{
	unsigned long long	x_content;
	long long			d_content;
	long long			content_len;
	unsigned int		bitmap;
	char				*content;
	int					i;
	int					width;
	int					precision;
	int					non_valid;
	char				content_char;
}					t_arg;

int		ft_printf(const char *format, ...);
int		start_parce(va_list *ap, const char *format);
t_arg	*create_new_arg();
int		fill_arg(int *i, const char *format, t_arg *arg, va_list *ap);
void	parce_flag(int *i, t_arg *arg, const char *format);
void	parce_width(int *i, t_arg *arg, const char *format, va_list *ap);
void	parce_precision(int *i, t_arg *arg, const char *format, va_list *ap);
void	parce_length(int *i, t_arg *arg, const char *format);
int		parce_type(int *i, t_arg *arg, const char *format);
void	type_processing(t_arg *arg, va_list *ap);
void	wildcard_processing(t_arg *arg);

void	processing_d(t_arg *arg, va_list *ap);
void	d_processing_type(t_arg *arg, va_list *ap);
void	d_processing_precision(t_arg *arg);
void	d_processing_flags(t_arg *arg);
void	d_processing_width(t_arg *arg);

void	processing_u(t_arg *arg, va_list *ap);
void	u_processing_type(t_arg *arg, va_list *ap);
void	u_processong_precision(t_arg *arg);
void	u_processing_width(t_arg *arg);

void	processing_s(t_arg *arg, va_list *ap);
void	s_processing_type(t_arg *arg, va_list *ap);
void	s_processing_precision(t_arg *arg);
void	s_processing_width(t_arg *arg);

void	processing_x(t_arg *arg, va_list *ap);
void	x_processing_type(t_arg *arg, va_list *ap);
void	x_processing_width(t_arg *arg);

void	processing_o(t_arg *arg, va_list *ap);
void	o_processing_type(t_arg *arg, va_list *ap);
void	o_processing_precision(t_arg *arg);
void	o_processing_flags(t_arg *arg);
void	o_processing_width(t_arg *arg);

void	processing_c(t_arg *arg, va_list *ap);
void	c_processing_type(t_arg *arg, va_list *ap);
void	c_processing_width(t_arg *arg);
void	c_processing_flags(t_arg *arg);

void	processing_percent(t_arg *arg);
void	percent_processing_type(t_arg *arg);
void	percent_processing_width(t_arg *arg);
void	percent_processing_flags(t_arg *arg);

void	processing_p(t_arg *arg, va_list *ap);
void	p_processing_width(t_arg *arg);

void	processing_b_d(t_arg *arg, va_list *ap);
void	d_big_processing_type(t_arg *arg, va_list *ap);
void	d_big_processing_precision(t_arg *arg);
void	d_big_processing_flags(t_arg *arg);
void	d_big_processing_width(t_arg *arg);

void	processing_i(t_arg *arg, va_list *ap);
void	i_processing_type(t_arg *arg, va_list *ap);
void	i_processing_precision(t_arg *arg);
void	i_processing_flags(t_arg *arg);
void	i_processing_width(t_arg *arg);

void	processing_b_s(t_arg *arg, va_list *ap);
void	s_big_processing_width(t_arg *arg);
void    s_big_processing_precision(t_arg *arg);
void	s_big_processing_flags(t_arg *arg, int *buf);
void	print_unicode(t_arg *arg, int *buf);

void	processing_b_x(t_arg *arg, va_list *ap);
void	x_big_processing_type(t_arg *arg, va_list *ap);

void	processing_b_u(t_arg *arg, va_list *ap);
void	u_big_processing_type(t_arg *arg, va_list *ap);
void	u_big_processong_precision(t_arg *arg);
void	u_big_processing_width(t_arg *arg);

void	processing_b_o(t_arg *arg, va_list *ap);
void	o_big_processing_type(t_arg *arg, va_list *ap);

void	processing_C(t_arg *arg, va_list *ap);
int		count_bytes(int num);
void	print_bytes(int byte, wchar_t buf);

void	invalid_conversion_specifier(t_arg *arg, const char *format, int *i);

void	proc_binary(t_arg *arg, va_list *ap);

///////////////////DOP_1///////////////////////////////
void	negative_content(t_arg *arg);
void	positive_content(t_arg *arg);
void	minus_width(t_arg *arg);
void	zero_width(t_arg *arg);
void	only_width(t_arg *arg);
///////////////////DOP_2///////////////////////////////
int		print(const char *format, int i, int i2);
void	zero_width_mod(t_arg *arg);
void	minus_width_mod(t_arg *arg);
void	only_width_mod(t_arg *arg);
void	free_struct(t_arg *arg);

#endif
