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

bool	ft_send_bit(pid_t server_pid, char my_str_char, int *bit_index)
{
	unsigned int		key;

	(*bit_index)--;
	key = 1;
	key <<= *bit_index;
	if (my_str_char & key)
		kill(server_pid, SIGUSR2);
	else
		kill(server_pid, SIGUSR1);
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
		ft_my_pid(server_pid);
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
	if (sig_num == SIGUSR1)
		ft_control(0, NULL, false);
	else if (sig_num == SIGUSR2)
		exit(0);
}

int	main(int argc, char **argv)
{
	unsigned int	i;

	i = 0;
	if (argc == 3)
	{
		ft_control(ft_atoi(argv[1]), argv[2], true);
		signal(SIGUSR1, ft_sig_handler);
		signal(SIGUSR2, ft_sig_handler);
		while (1);
	}
	ft_printf("%s", "ERROR. Check parameter count.\n");
	return (0);
}
