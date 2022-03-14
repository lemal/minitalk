/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_srvr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapulask <tapulask@21.school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 16:27:27 by tapulask          #+#    #+#             */
/*   Updated: 2022/03/13 16:27:37 by tapulask         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "srvr_header.h"

void	ft_remalloc(char **built_str, int *i)
{
	char	*temp;
	int		j;

	j = -1;
	(*i)++;
	temp = (char *)malloc(sizeof(char *) * *i);
	while (++j < *i)
		temp[j] = (*built_str)[j];
	free(*built_str);
	*built_str = temp;
}

void	ft_sig_converter(int sig_num, pid_t *client_pid, char **built_str, int *str_i)
{
	static int	i;

	ft_check_sig(sig_num, &i, *(built_str)[*str_i]);
	if (i == 8)
	{
		i = 0;
		if ((*built_str)[*str_i])
			ft_remalloc(*built_str, str_i);
	}
}

void	ft_zero_state(char **built_str, pid_t *client_pid, int *num_elem)
{
	ft_printf("Passed string is: %s", *built_str);
	free(*built_str);
	*built_str = NULL;
	kill(client_pid, SIGUSR2);
	*client_pid = 0;
	*num_elem = 0;
}

void	ft_sig_handler(int	sig_num)
{
	static pid_t 	client_pid;
	static char		*built_str;
	static int		i;

	if (!built_str)
	{
		built_str = (char *)malloc(sizeof(char *));
	}
	if (!client_pid)
	{
		client_pid = ft_pid_sig_converter(sig_num);
		if (client_pid)
			kill(client_pid, SIGUSR1);
	}
	else
	{
		ft_sig_converter(sig_num, &client_pid, &built_str, &i);
		if (built_str[i])
			kill(client_pid, SIGUSR1);//if broken, remove. Set the client to exit when the last is sent.
		write(1, "Got a bit\n", 13);
		if (!built_str[i])
			ft_zero_state(&built_str, &client_pid, &i);
	}
}

int	main(void)
{
	static bool on_check;

	if (!on_check)
	{
		ft_printf("Server PID is:%d\n", (int)getpid());
		on_check = true;
	}
	signal(SIGUSR1, ft_sig_handler);
	signal(SIGUSR2, ft_sig_handler);
	while (1);
	return (0);
}
