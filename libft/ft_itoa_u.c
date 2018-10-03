/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarev <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 18:43:47 by skarev            #+#    #+#             */
/*   Updated: 2018/09/14 18:43:47 by skarev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_u(long long int n)
{
	size_t	i;
	size_t	n_size;
	char	*str;

	i = 0;
	if (n < 0)
		return (ft_itoa_u(n - 4294967295));
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
