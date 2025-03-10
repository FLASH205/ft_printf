/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybahmaz <ybahmaz@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 16:03:56 by ybahmaz           #+#    #+#             */
/*   Updated: 2024/12/07 09:19:43 by ybahmaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check_conv(char c)
{
	if (c == 'c' || c == 'd' || c == 'i'
		|| c == 'u' || c == 's' || c == 'x'
		|| c == 'X' || c == 'p')
		return (1);
	return (0);
}

int	ft_conversion(char c, void *v)
{
	int	size;

	size = 0;
	if (c == 'c')
		size += ft_print_char((char)v);
	else if (c == 's')
		size += ft_print_str((char *)v);
	else if (c == 'd' || c == 'i')
		size += ft_print_num((int)v);
	else if (c == 'u')
		size += ft_print_unum((unsigned int)v);
	else if (c == 'x' || c == 'X')
		size += ft_print_hex((unsigned int)v, c);
	else if (c == 'p')
		size += ft_print_ptr(v);
	return (size);
}

int	ft_printf(const char *str, ...)
{
	va_list	arg;
	int		size;

	if (write(1, 0, 0) == -1)
		return (-1);
	size = 0;
	va_start(arg, str);
	while (*str != '\0')
	{
		if (*str == '%')
		{
			str++;
			if (*str == '%')
				size += ft_print_char('%');
			else if (ft_check_conv(*str) == 1)
				size += ft_conversion(*str, va_arg(arg, void *));
			else
				str--;
		}
		else
			size += write(1, str, 1);
		str++;
	}
	va_end(arg);
	return (size);
}
