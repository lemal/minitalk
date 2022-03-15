/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_cl.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapulask <tapulask@21.school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 16:27:27 by tapulask          #+#    #+#             */
/*   Updated: 2022/03/13 16:27:37 by tapulask         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cl_header.h"

void	ft_send_bit(pid_t server_pid, char my_str_char, int *bit_index)//could be bool?
{
	unsigned int		key;

	(*bit_index)--;
	key = 1;
	key <<= *bit_index;
	if (my_str_char & key)
		kill(server_pid, SIGUSR2);
	else
		kill(server_pid, SIGUSR1);
	sleep(1);
}

void	ft_control(pid_t server_pid, char *my_str, bool set)
{
	static pid_t	stored_srvr_pid;
	static char		*stored_my_str;
	static int		i;
	static int		j = 8;

	if (set)
	{
		stored_srvr_pid = server_pid;
		stored_my_str = my_str;
	}
	else if (!set)
	{
		ft_send_bit(stored_srvr_pid, stored_my_str[i], &j);
		if (j == 0)
		{
			i++;
			j = 8;
		}
	}
}

void	ft_sig_handler(int	sig_num)
{
	write(1, "in client!", 11);
	if (sig_num == SIGUSR1)
		ft_control(0, NULL, false);
}

int	main(int argc, char **argv)
{
	if (argc == 3)
	{
		ft_control((pid_t)ft_atoi(argv[1]), argv[2], true);
	}
	ft_printf("%s", "ERROR. Check parameter count.\n");
	return (0);
}
