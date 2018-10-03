/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dop_3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarev <skarev@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 01:43:22 by skarev            #+#    #+#             */
/*   Updated: 2018/10/03 01:43:23 by skarev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	zero_width_begin(t_arg *arg, char *buf)
{
	char	*tmp;
	char	*tmp2;

	if (buf[0] == '-' || buf[0] == '+')
	{
		tmp = ft_strdup(buf);
		free(buf);
		tmp2 = ft_strsub(arg->content, 1, arg->content_len - 1);
		buf = ft_strjoin(tmp, tmp2);
		free(tmp2);
	}
	else if (arg->bitmap & SPACE)
	{
		tmp = ft_strdup(buf);
		free(buf);
		buf = ft_strjoin(arg->content, tmp);
	}
	else
	{
		tmp = ft_strdup(buf);
		free(buf);
		buf = ft_strjoin(tmp, arg->content);
	}
	helper_free(arg, buf, tmp);
}

void	helper_free(t_arg *arg, char *buf, char *tmp)
{
	free(arg->content);
	arg->content = ft_strdup(buf);
	free(buf);
	free(tmp);
}

void	helper_1(t_arg *arg, va_list *ap)
{
	if (arg->bitmap & BIG_S || (arg->bitmap & SMALL_S && arg->bitmap & L))
		processing_b_s(arg, ap);
	else
		processing_s(arg, ap);
}

void	helper_2(t_arg *arg, va_list *ap)
{
	if (arg->bitmap & BIG_C || (arg->bitmap & SMALL_C && arg->bitmap & L))
		processing_b_c(arg, ap);
	else
		processing_c(arg, ap);
}

void	fill_and_free(char *buf, t_arg *arg)
{
	char	*tmp;
	char	*tmp2;

	tmp = ft_strsub(arg->content, 0, arg->content_len);
	tmp2 = ft_strdup(buf);
	free(buf);
	buf = ft_strjoin(tmp2, tmp);
	free(arg->content);
	arg->content = ft_strdup(buf);
	arg->content_len = ft_strlen(arg->content);
	free(buf);
	free(tmp);
	free(tmp2);
}
