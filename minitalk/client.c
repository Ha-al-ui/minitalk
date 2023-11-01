/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halaoui <halaoui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 14:43:05 by halaoui           #+#    #+#             */
/*   Updated: 2023/11/01 16:28:52 by halaoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_msg(char *msg, int pid)
{
	int	i;
	int	s;

	i = -1;
	while (++i < ft_strlen(msg))
	{
		s = -1;
		while (++s < 8)
		{
			if (msg[i] & (128 >> s))
			{
				if (kill(pid, SIGUSR1) == -1)
					exit(1);
			}
			else
			{
				if (kill(pid, SIGUSR2) == -1)
					exit(1);
			}
			usleep(500);
		}
	}
}

int	check_pid(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (1);
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int		ppid;

	if (argc != 3)
		ft_error("Error\n");
	if (check_pid(argv[1]))
		ft_error("Error\n");
	ppid = ft_atoi(argv[1]);
	if (ppid <= 0)
		exit(1);
	send_msg(argv[2], ppid);
}
