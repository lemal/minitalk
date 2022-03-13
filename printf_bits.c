/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_bits.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapulask <tapulask@21.school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 16:28:31 by tapulask          #+#    #+#             */
/*   Updated: 2022/03/13 16:28:33 by tapulask         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char	*c, int	*count)
{
	write (1, &c, 1);
	(*count)++;
}

void	ft_putstr(char	*str, int	*count)
{
	while (*str)
	{
		write(1, &(*str), 1);
		str++;
		(*count)++;
	}
}

void	ft_putint(int n, int *count)
{
	unsigned int	num;

	if (n < 0)
	{
		write(1, "-", 1);
		(*count)++;
		n *= -1;
	}
	num = (unsigned int)n;
	if ((num / 10) != 0)
		ft_putint(num / 10, &(*count));
	num = (num % 10) + '0';
	write(1, &num, 1);
	(*count)++;
}

void	ft_putuint(unsigned int	n, int *count)
{
	unsigned int	num;

	num = (unsigned int)n;
	if ((num / 10) != 0)
		ft_putint(num / 10, &(*count));
	num = (num % 10) + '0';
	write(1, &num, 1);
	(*count)++;
}