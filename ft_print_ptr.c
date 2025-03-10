/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybahmaz <ybahmaz@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 09:20:25 by ybahmaz           #+#    #+#             */
/*   Updated: 2024/12/04 17:03:32 by ybahmaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_ptr(void *ptr)
{
	int				size;
	unsigned long	adress;

	adress = (unsigned long)ptr;
	size = 0;
	if (!ptr)
		size += write(1, "0x0", 3);
	else
	{
		size += write(1, "0x", 2);
		size += ft_print_hex(adress, 'x');
	}
	return (size);
}
