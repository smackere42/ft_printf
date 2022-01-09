/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smackere <smackere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 18:44:17 by smackere          #+#    #+#             */
/*   Updated: 2022/01/08 18:44:17 by smackere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_hex_print(size_t nb, int	type)
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
		write(1, &base[nb], 1); 
}

int	ft_hex_x(size_t nb, int x)
{
	int	ret;

	ret = 0;
	if (!nb)
		return(write(1, '0', 1));
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

int	ft_hex_p(size_t nb, int x)
{
	int	ret,

	ret = 0;
	ft_hex_print(nb, 1);
	while (nb)
	{
		ret++;
		nb /= 16;
	}
	return (ret);
}