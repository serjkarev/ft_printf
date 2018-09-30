/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dop_1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarev <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 18:46:18 by skarev            #+#    #+#             */
/*   Updated: 2018/09/11 18:46:18 by skarev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	negative_content(t_arg *arg)
{
	int		i;
	int		len;
	int		precision;
	char	*buf;

	i = 0;
	if (arg->content_len > 0)
	{
		len = arg->content_len - 1;
		precision = arg->precision;
		buf = ft_strnew(len + precision);
		buf[i] = '-';
		i++;
		while (precision > len)
		{
			buf[i] = '0';
			i++;
			precision -= 1;
		}
		buf = ft_strjoin(buf, ft_strsub(arg->content, 1, arg->content_len - 1));
		free(arg->content);
		arg->content = ft_strdup(buf);
		arg->content_len = ft_strlen(arg->content);
		free(buf);
	}
}

void	positive_content(t_arg *arg)
{
	int		i;
	int		len;
	int		precision;
	char	*buf;
	// char	*tmp;

	i = 0;
	if (arg->content_len > 0)
	{
		len = arg->content_len;
		precision = arg->precision;
		buf = ft_strnew(len + precision);
		while (precision > len)
		{
			buf[i] = '0';
			i++;
			precision -= 1;
		}
		// tmp = ft_strsub(arg->content, 0, arg->content_len);
		// buf = ft_strjoin(buf, tmp);
		// free(tmp);
		buf = ft_strjoin(buf, ft_strsub(arg->content, 0, arg->content_len));//ЛИК
		free(arg->content);
		arg->content = ft_strdup(buf);
		arg->content_len = ft_strlen(arg->content);
		free(buf);
	}
}

void	minus_width(t_arg *arg)
{
	int		i;
	char	*buf;

	i = 0;
	buf = ft_strnew(arg->width - arg->content_len);
	while (i < arg->width - arg->content_len)
	{
		buf[i] = ' ';
		i++;
	}
	buf = ft_strjoin(arg->content, buf);
	free(arg->content);
	arg->content = ft_strdup(buf);
	free(buf);
}

void	zero_width(t_arg *arg)
{
	int		i;
	int		len;
	char	*buf;

	i = 0;
	len = arg->width - arg->content_len;
	if (arg->content[0] == '-' || arg->content[0] == '+')
	{
		len += 1;
		buf = ft_strnew(len);
		arg->content[0] == '-' ? (buf[i] = '-') : (buf[i] = '+');
		i += 1;
	}
	else
		buf = ft_strnew(len);
	while (i < len)
		buf[i++] = '0';
	if (buf[0] == '-' || buf[0] == '+')
		buf = ft_strjoin(buf, ft_strsub(arg->content, 1, arg->content_len - 1));
	else if (arg->bitmap & SPACE)
		buf = ft_strjoin(arg->content, buf);
	else
		buf = ft_strjoin(buf, arg->content);
	free(arg->content);
	arg->content = ft_strdup(buf);
	free(buf);
}

void	only_width(t_arg *arg)
{
	int		i;
	char	*buf;

	i = 0;
	buf = ft_strnew(arg->width - arg->content_len);
	while (i < arg->width - arg->content_len)
		buf[i++] = ' ';
	if (arg->non_valid != 228)//ОПА ПАСХАЛОЧКА
		buf = ft_strjoin(buf, arg->content);
	free(arg->content);
	arg->content = ft_strdup(buf);
	free(buf);
}
