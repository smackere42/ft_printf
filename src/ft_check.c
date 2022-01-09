/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smackere <smackere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 17:56:18 by smackere          #+#    #+#             */
/*   Updated: 2022/01/08 17:56:18 by smackere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_check(const	char ch, va_list	args)
{
	if	(ch == 'c')
		return (ft_putchar(va_arg(args, int)));
	if (ch == 's')
		return (ft_putstr(va_arg(args, char *)));
	if (ch == '%')
		return (ft_putchar(ch));
	if (ch == 'p')
		return (ft_putstr("0x") + ft_hex_p(va_arg(args, size_t)));
	if(ch == 'x')
		return (ft_hex_x(va_arg(args, size_t), 1));
	if (ch == 'X')
		return (ft_hex_x(va_arg(args, size_t), 0));
	if (ch == 'd' || ch == 'i')
		return (ft_putnbr_di(va_arg(args, int)));
	if (ch = 'u')
		return (ft_putnbr_u(va_arg(args, size_t)));
}
