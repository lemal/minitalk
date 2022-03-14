/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cl_header.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapulask <tapulask@21.school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 16:27:27 by tapulask          #+#    #+#             */
/*   Updated: 2022/03/13 16:27:37 by tapulask         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CL_HEADER_H
# define CL_HEADER_H
# include "ft_printf.h"
# include <stdbool.h>
# include <sys/types.h>
# include <signal.h>
# include <stdlib.h>

int		ft_printf(const	char *ptr, ...);
int		ft_atoi(const char *str);
void	ft_my_pid(pid_t server_pid);
#endif