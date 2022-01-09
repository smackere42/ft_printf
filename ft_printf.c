/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smackere <smackere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 16:58:14 by smackere          #+#    #+#             */
/*   Updated: 2022/01/08 16:58:14 by smackere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>

int ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int ft_putstr(char *str)
{
	int i;

	i = 0;
	if (!str)
	{
		return (write(1, "(null)", 6));
	}
	while(str[i])
		i++;
	return (write(1, str, i));
}

int	ft_printf(const char *str, ...)
{
	va_list		args;
	int				i;
	int				ret;

	va_start (args, str);
	i = -1;
	ret = 0;

	while (str[i++])
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