/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pakopian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 20:16:33 by pakopian          #+#    #+#             */
/*   Updated: 2025/03/29 20:16:43 by pakopian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

static void	check_modifier(char c, int *result, va_list args)
{
	if (c == '%')
		*result += ft_putchar('%');
	else if (c == 'c')
		*result += ft_putchar(va_arg(args, int));
	else if (c == 's')
		*result += print_string(va_arg(args, char *));
	else if (c == 'p')
		print_pointer(va_arg(args, unsigned long), result);
	else if (c == 'i' || c == 'd')
		print_int(va_arg(args, int), result);
	else if (c == 'u')
		print_unsigned(va_arg(args, unsigned int), result);
	else if (c == 'x' || c == 'X')
		print_hex(va_arg(args, unsigned int), c, result);
}

int	ft_printf(const char *str, ...)
{
	int		result;
	va_list	args;

	va_start(args, str);
	result = 0;
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			check_modifier(*str, &result, args);
		}
		else
			result += ft_putchar(*str);
		str++;
	}
	va_end(args);
	return (result);
}
