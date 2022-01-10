/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smackere <smackere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 13:12:10 by smackere          #+#    #+#             */
/*   Updated: 2022/01/10 21:12:07 by smackere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <fcntl.h>

int		ft_check(const	char ch, va_list args);
void	ft_hex_print(unsigned long nb, int type);
int		ft_hex_x(unsigned long nb, int x);
int		ft_hex_p(unsigned long nb);
void	write_nbr(unsigned int nb);
int		ft_putnbr_di(int nb);
int		ft_putnbr_u(unsigned int nb);
int		ft_putchar(char c);
int		ft_putstr(char *str);
int		ft_printf(const char *str, ...);

#endif