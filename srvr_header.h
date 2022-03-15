/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   srvr_header.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapulask <tapulask@21.school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 16:27:27 by tapulask          #+#    #+#             */
/*   Updated: 2022/03/13 16:27:37 by tapulask         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SRVR_HEADER_H
# define SRVR_HEADER_H
# define _POSIX_C_SOURCE 199309L
# include "ft_printf.h"
# include <sys/types.h>
# include <signal.h>
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>

void	ft_check_sig(int sig_num, int *i, char *built_char);
int		ft_printf(const	char *ptr, ...);
#endif