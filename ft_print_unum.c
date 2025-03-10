/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unum.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybahmaz <ybahmaz@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 09:59:00 by ybahmaz           #+#    #+#             */
/*   Updated: 2024/11/25 14:26:11 by ybahmaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_unum(unsigned int n)
{
	int	size;

	size = 0;
	if (n >= 0 && n <= 9)
		size += ft_print_char(n + '0');
	if (n >= 10)
	{
		size += ft_print_unum(n / 10);
		size += ft_print_char(n % 10 + '0');
	}
	return (size);
}
