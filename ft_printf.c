/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smackere <smackere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 16:18:45 by smackere          #+#    #+#             */
/*   Updated: 2022/01/10 21:10:32 by smackere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (write(1, "(null)", 6));
	while (str[i])
		i++;
	return (write(1, str, i));
}

int	ft_printf(const char *str, ...)
{
	va_list		args;
	int			i;
	int			ret;

	va_start (args, str);
	i = -1;
	ret = 0;
	while (str[++i])
	{
		if (str[i] == '%')
		{
			ret += ft_check(str[i + 1], args);
			i++;
		}
		else
			ret += ft_putchar(str[i]);
	}
	va_end (args);
	return (ret);
}

int	ft_check(const	char ch, va_list args)
{
	if (ch == 'c')
		return (ft_putchar(va_arg(args, int)));
	if (ch == 's')
		return (ft_putstr(va_arg(args, char *)));
	if (ch == '%')
		return (ft_putchar(ch));
	if (ch == 'p')
		return (write(1, "0x", 2) + ft_hex_p(va_arg(args, unsigned long)));
	if (ch == 'x')
		return (ft_hex_x(va_arg(args, unsigned int), 1));
	if (ch == 'X')
		return (ft_hex_x(va_arg(args, unsigned int), 0));
	if (ch == 'd' || ch == 'i')
		return (ft_putnbr_di(va_arg(args, int)));
	if (ch == 'u')
		return (ft_putnbr_u(va_arg(args, unsigned int)));
	return (0);
}
