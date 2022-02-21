/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexademical.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smackere <smackere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 18:44:17 by smackere          #+#    #+#             */
/*   Updated: 2022/01/10 21:11:29 by smackere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_hex_print(unsigned long nb, int type)
{
	char	*base;

	if (type)
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	if (nb >= 16)
	{
		ft_hex_print(nb / 16, type);
		ft_hex_print(nb % 16, type);
	}
	else
		ft_putchar(base[nb]);
}

int	ft_hex_x(unsigned long nb, int x)
{
	int	ret;

	ret = 0;
	if (!nb)
		return (ft_putchar('0'));
	if (x)
		ft_hex_print(nb, 1);
	else
		ft_hex_print(nb, 0);
	while (nb)
	{
		ret++;
		nb /= 16;
	}
	return (ret);
}

int	ft_hex_p(unsigned long nb)
{
	int	ret;

	ret = 0;
	ft_hex_print(nb, 1);
	if (nb == 0)
		return (1);
	while (nb > 0)
	{
		ret++;
		nb /= 16;
	}
	return (ret);
}
