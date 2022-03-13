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

void	ft_send_one()
{

}

void	ft_send_zero()
{

}

bool	ft_wait(some_signal_thing)
{
	while (signal_received != sig_value);
}

void	ft_byte_act(char	alnum, int	pid)
{
	short int	i;
	char		mask;

	i = 7;
	while (i <= 0)
	{
		mask = 1;
		mask <<= i;
		if (alnum & mask)
			ft_send_one(pid);
		else
			ft_send_zero(pid);
		i--;
	}
}

int	main(int argc, char **argv)
{
	unsigned int	pid;
	int				i;

	i = 0;
	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		while (argv[2][i])
		{
			ft_byte_act(argv[2][i], pid);
			i++;
		}
		return (0);
	}
	ft_printf("%s", "ERROR. Check parameter count.\n");
	return (0);
}
