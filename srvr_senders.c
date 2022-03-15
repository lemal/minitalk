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
