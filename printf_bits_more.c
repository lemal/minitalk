/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_bits_more.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapulask <tapulask@21.school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 16:28:11 by tapulask          #+#    #+#             */
/*   Updated: 2022/03/13 16:28:14 by tapulask         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_other_chrs(const char **ptr, int *count)
{
	write(1, &(**ptr), 1);
	(*ptr)++;
	(*count)++;
}

void	ft_print_percent(const char **ptr, int *count)
{
	if ((**ptr == '%') && (*((*ptr) - 1) == '%'))
	{
		write(1, "%", 1);
		(*count)++;
		(*ptr)++;
	}
}