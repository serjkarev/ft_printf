/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarev <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 15:07:05 by skarev            #+#    #+#             */
/*   Updated: 2018/09/05 15:07:06 by skarev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>

int		main(void)
{
	setlocale (LC_ALL,"");

	//52 undefined behavior
	// printf("|%d", printf("{%05s}", "abc"));
	// printf("\n");
	// printf("|%d", ft_printf("{%05s}", "abc"));
	// printf("\n//////////////////////////////////\n");
	// printf("|%d", printf("{%05p}", 0));
	// printf("\n");
	// printf("|%d", ft_printf("{%05p}", 0));
	// printf("\n//////////////////////////////////\n");

//72 возможно проблема в том что ширина меньше за количество байт занимаемых символами

	//72 undefinded behavior
	// printf("|%d", printf("%.4S", L"我是一只猫。"));
	// printf("\n");
	// printf("|%d", ft_printf("%.4S", L"我是一只猫。"));
	// printf("\n//////////////////////////////////\n");
	// printf("|%d", printf("%15.4S", L"我是一只猫。"));
	// printf("\n");
	// printf("|%d", ft_printf("%15.4S", L"我是一只猫。"));
	// printf("\n//////////////////////////////////\n");
	// printf("|%d", printf("%4.15S", L"我是一只猫。"));
	// printf("\n");
	// printf("|%d", ft_printf("%4.15S", L"我是一只猫。"));
	// printf("\n//////////////////////////////////\n");
	// printf("|%d", printf("%4.S", L"我是一只猫。"));
	// printf("\n");
	// printf("|%d", ft_printf("%4.S", L"我是一只猫。"));
	// printf("\n//////////////////////////////////\n");
	// printf("|%d", printf("%4.1S", L"Jambon"));
	// printf("\n");
	// printf("|%d", ft_printf("%4.1S", L"Jambon"));
	// printf("\n//////////////////////////////////\n");

	//79
	// printf("|%d", printf("{%05.s}", 0));
	// printf("\n");
	// printf("|%d", ft_printf("{%05.s}", 0));
	// printf("\n//////////////////////////////////\n");
	// printf("|%d", printf("{%05.S}", L"42 c est cool"));
	// printf("\n");
	// printf("|%d", ft_printf("{%05.S}", L"42 c est cool"));
	// printf("\n//////////////////////////////////\n");

//====================================================================

	//50
	printf("|%d", printf("{%10R}"));
	printf("\n");
	printf("|%d", ft_printf("{%10R}"));
	printf("\n//////////////////////////////////\n");

	//53
	printf("|%d", printf("{%-15Z}", 123));
	printf("\n");
	printf("|%d", ft_printf("{%-15Z}", 123));
	printf("\n//////////////////////////////////\n");

	//79
	printf("|%d", printf("{%05.Z}", 0));
	printf("\n");
	printf("|%d", ft_printf("{%05.Z}", 0));
	printf("\n//////////////////////////////////\n");
	return (0);
}
