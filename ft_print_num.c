/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_num.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybahmaz <ybahmaz@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 15:45:05 by ybahmaz           #+#    #+#             */
/*   Updated: 2024/12/05 16:51:13 by ybahmaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_num(int n)
{
	int	size;

	size = 0;
	if (n == -2147483648)
	{
		size += ft_print_char('-');
		size += ft_print_num(214748364);
		size += ft_print_char('8');
	}
	else
	{
		if (n < 0)
		{
			size += ft_print_char('-');
			n *= -1;
		}
		if (n >= 0 && n <= 9)
			size += ft_print_char(n + '0');
		if (n >= 10)
		{
			size += ft_print_num(n / 10);
			size += ft_print_char(n % 10 + '0');
		}
	}
	return (size);
}
