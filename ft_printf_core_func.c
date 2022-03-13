/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_core_func.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapulask <tapulask@21.school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 16:27:27 by tapulask          #+#    #+#             */
/*   Updated: 2022/03/13 16:27:37 by tapulask         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_num_handler(long int next_arg, const char **str_val, int *count)
{
	if ((**str_val == 'd') || (**str_val == 'i'))
		ft_putint(next_arg, &(*count));
	(*str_val)++;
}

void	ft_symb_handler(char *next_arg, const char **str_val, int *count)
{
	if (**str_val == 'c')
		ft_putchar(next_arg, &(*count));
	else if (**str_val == 's')
		ft_putstr(next_arg, &(*count));
	(*str_val)++;
}

int	ft_printf(const	char *ptr, ...)
{
	int		count;
	va_list	ap;

	if (ptr == NULL)
		return (0);
	va_start(ap, ptr);
	count = 0;
	while (*ptr)
	{
		if (*ptr == '%')
		{
			ptr++;
			if ((*ptr == 'c') || (*ptr == 's'))
				ft_symb_handler(va_arg(ap, char *), &ptr, &count);
			else if ((*ptr == 'i') || (*ptr == 'd') || (*ptr == 'u'))
				ft_num_handler(va_arg(ap, long int), &ptr, &count);
			ft_print_percent(&ptr, &count);
		}
		else
			ft_print_other_chrs(&ptr, &count);
	}
	va_end(ap);
	return (count);
}