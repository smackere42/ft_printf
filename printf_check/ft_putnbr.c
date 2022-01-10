/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smackere <smackere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 11:14:53 by smackere          #+#    #+#             */
/*   Updated: 2022/01/10 21:13:33 by smackere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	write_nbr(unsigned int nb)
{
	char	ch;

	if (nb < 10)
	{
		ch = nb + '0';
		write(1, &ch, 1);
	}
	else
	{
		write_nbr(nb / 10);
		write_nbr(nb % 10);
	}
}

int	ft_putnbr_di(int nb)
{
	unsigned int	nbr;
	int				ret;

	ret = 0;
	if (!nb)
		return (write(1, "0", 1));
	if (nb < 0)
	{
		ret += write(1, "-", 1);
		nb *= -1;
	}
		nbr = nb;
	write_nbr(nbr);
	while (nb)
	{
		ret++;
		nb /= 10;
	}
	return (ret);
}

int	ft_putnbr_u(unsigned int nb)
{
	int	ret;

	ret = 0;
	if (!nb)
		return (write(1, "0", 1));
	write_nbr(nb);
	while (nb)
	{
		ret++;
		nb /= 10;
	}
	return (ret);
}
