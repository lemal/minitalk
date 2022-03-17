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

void	ft_bit_stuffer(bool choice, char *built_char, bool reset)
{
	static int	bit_index;

	if (reset)
	{
		bit_index = 7;
		*built_char = 0;
	}
	if (choice)
		*built_char |= (1 << bit_index);
	bit_index--;
}

void	ft_check_sig(int sig_num, int *i, char *built_char)
{
	if (*i < 8 && sig_num == SIGUSR1)
	{
		if (*i == 0)
			ft_bit_stuffer(0, built_char, true);
		else
			ft_bit_stuffer(0, built_char, false);
		(*i)++;
	}
	else if (*i < 8 && sig_num == SIGUSR2)
	{
		if (*i == 0)
			ft_bit_stuffer(1, built_char, true);
		else
			ft_bit_stuffer(1, built_char, false);
		(*i)++;
	}
}

void	ft_sig_handler(int sig_num, siginfo_t *info, void *context)
{
	static char	built_char;
	static int	i;

	(void) context;
	ft_check_sig(sig_num, &i, &built_char);
	if (i == 8)
	{
		if (built_char)
			write(1, &built_char, 1);
		if (!built_char)
			write(1, "\0\n", 2);
		i = 0;
	}
	kill(info->si_pid, SIGUSR2);
}

int	main(void)
{
	static bool	on_check;
	t_sig		sa;

	if (!on_check)
	{
		ft_printf("%d\n", getpid());
		on_check = true;
	}
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = ft_sig_handler;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		;
	return (0);
}
