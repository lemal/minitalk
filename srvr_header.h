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
# include "ft_printf.h"
# include <sys/types.h>
# include <signal.h>
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>

unsigned int	ft_pid_sig_converter(int sig_num);
#endif