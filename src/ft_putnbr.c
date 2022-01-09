/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smackere <smackere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 20:51:29 by smackere          #+#    #+#             */
/*   Updated: 2022/01/08 20:51:29 by smackere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	write_nbr(size_t nb)
{
	 char	ch;

	 if (nb < 10)
	{
		ch = nb + '0';
		ft_putchar(ch);
	}
	else
	{
		ft_putchar(nb / 10);
		ft_putchar(nb % 10);
	}
}

int	ft_putnbr_di(int	nb)
{
	size_t	nbr;
	int			ret;

	ret = 0;
	nbr = nb;
	if (!nb)
		return (ft_putchar("0"));
	if (nb < 0)
	{
		ret += ft_putchar("-");
		nbr *= -1;
	}
	ft_putchar(nbr);		while	(nbr)
	{
		ret++;
		nb /= 10;
	}
}

int	ft_putnbr_u(size_t nb)
{
	int	ret;

 	ret = 0;
	if (!nb)
		return (ft_putchar("0"));
	ft_putchar(nb);
	while (nb)
	{
		ret++;
		nb /= 10;
	}
return ret;
}