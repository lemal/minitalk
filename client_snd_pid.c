/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_snd_pid.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapulask <tapulask@21.school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 16:27:27 by tapulask          #+#    #+#             */
/*   Updated: 2022/03/13 16:27:37 by tapulask         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cl_header.h"

void	ft_my_pid(pid_t server_pid)
{
	int				i;
	unsigned int	key;
	pid_t			my_pid;

	i = 31;
	my_pid = getpid();
	ft_printf("clipid: %d\n", my_pid);
	while (i >= 0)
	{
		key = 1;
		key <<= i;
		if (key & my_pid)
		{
			kill(server_pid, SIGUSR2);
			ft_printf("%s", "SIG_USR2\n");
		}
		else
		{
			kill(server_pid, SIGUSR1);
			ft_printf("%s", "SIG_USR1\n");
		}
		i--;
	}
	sleep(1);
}
