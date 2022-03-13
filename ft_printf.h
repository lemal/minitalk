/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapulask <tapulask@21.school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 16:27:53 by tapulask          #+#    #+#             */
/*   Updated: 2022/03/13 16:27:57 by tapulask         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>
void	ft_putchar(char	*c, int	*count);
void	ft_putstr(char	*str, int	*count);
void	ft_puthex(long	int	n, char	shift, int *count);
void	ft_putint(int	n, int *count);
void	ft_putuint(unsigned int	n, int *count);
void	ft_print_other_chrs(const char **ptr, int *count);
void	ft_print_percent(const char **ptr, int *count);
int		ft_printf(const	char *ptr, ...);
#endif