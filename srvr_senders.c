/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   srvr_get_pid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapulask <tapulask@21.school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 16:27:27 by tapulask          #+#    #+#             */
/*   Updated: 2022/03/13 16:27:37 by tapulask         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "srvr_header.h"

void	ft_pid_bit_stuffer(bool choice, pid_t *built_int, bool reset)
{
	static pid_t	bit_index;
	pid_t			key;

	key = 1;
	if (reset)
	{
		bit_index = 31;
		*built_int = 0;
	}
	if (choice)
	{
		key <<= bit_index;
		*built_int |= key;
	}
	bit_index--;
}

pid_t	ft_pid_sig_converter(int sig_num)
{
	static int	i;
	pid_t		client_pid;

	if (i < 32 && sig_num == SIGUSR1)//if pid not received, change this 32 to sizeof(pid_t) * 8
	{
		if (i == 0)
			ft_bit_stuffer(0, &client_pid, true);
		else
			ft_bit_stuffer(0, &client_pid, false);
		i++;
	}
	else if (i < 32 && sig_num == SIGUSR2)
	{
		if (i == 0)
			ft_bit_stuffer(1, &client_pid, true);
		else
			ft_bit_stuffer(1, &client_pid, false);
		i++;
	}
	else if (i == 32)
		return (client_pid);
	return (0);
}

void	ft_bit_stuffer(bool choice, char *built_char, bool reset)
{
	static int	bit_index;
	char		key;

	key = 1;
	if (reset)
	{
		bit_index = 7;
		*built_char = 0;
	}
	if (choice)
	{
		key <<= bit_index;
		*built_char |= key;
	}
	bit_index--;
}

void	ft_check_sig(int sig_num, int *i, char *built_char)
{
	if (*i < 8 && sig_num == 10)
	{
		if (*i == 0)
			ft_bit_stuffer(0, built_char, true);
		else
			ft_bit_stuffer(0, built_char, false);
		(*i)++;
	}
	else if (*i < 8 && sig_num == 12)
	{
		if (*i == 0)
			ft_bit_stuffer(0, built_char, true);
		else
			ft_bit_stuffer(0, built_char, false);
		(*i)++;
	}
}
