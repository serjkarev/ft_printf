/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_ll.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarev <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 13:56:13 by skarev            #+#    #+#             */
/*   Updated: 2018/09/11 13:56:13 by skarev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char        *ft_itoa_ll(long long n)
{
	long long	i;
	long long   n_size;
	char	*str;

	i = 0;
	if (n < -9223372036854775807)//какой тут взять предел????????????
		return (ft_strjoin("-","9223372036854775808"));//КОСТЫЫЫЛЬ
	n_size = ft_nbrlen_ll(n);
	str = (char *)malloc(sizeof(char) * (n_size + 1));
	if (!str)
		return (NULL);
	str[n_size] = '\0';
	if (n < 0)
	{
		str[0] = '-';
		n *= -1;
		i++;
	}
	while (i < n_size--)
	{
		str[n_size] = (n % 10) + '0';
		n /= 10;
	}
	return (str);
}
