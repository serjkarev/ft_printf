/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dop_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarev <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 22:16:50 by skarev            #+#    #+#             */
/*   Updated: 2018/09/13 22:16:50 by skarev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print(const char *format, int i, int i2)
{
	int		byte;
	int		len;

	len = i2 - i;
	byte = write(1, &format[i], len);
	return (byte);
}

void	zero_width_mod(t_arg *arg)
{
	long long	i;
	char		*buf;

	buf = ft_strnew(arg->width);
	buf[0] = arg->content[0];
	buf[1] = arg->content[1];
	i = 2;
	while (i < arg->width - arg->content_len + 2)
	{
		buf[i] = '0';
		i++;
	}
	buf = ft_strjoin(buf, \
	ft_strsub(arg->content, arg->content_len - 2, arg->content_len - 2));
	free(arg->content);
	arg->content = ft_strdup(buf);
	free(buf);
}

void	minus_width_mod(t_arg *arg)
{
	int		i;
	int		len;
	char	*buf;

	i = 0;
	len = arg->width - 1;
	buf = ft_strnew(len);
	while (i < len)
	{
		buf[i] = ' ';
		i += 1;
	}
	arg->content = ft_strjoin(arg->content, buf);
	free(buf);
}

void	only_width_mod(t_arg *arg)
{
	int		i;
	int		len;
	char	*buf;

	i = 0;
	len = arg->width - 1;
	buf = ft_strnew(len);
	while (i < len)
	{
		buf[i] = ' ';
		i += 1;
	}
	arg->content = ft_strjoin(buf, arg->content);
	free(buf);
}

void	free_struct(t_arg *arg)
{
	if (arg->content)
		free(arg->content);
	free(arg);
}