/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halaoui <halaoui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 14:43:26 by halaoui           #+#    #+#             */
/*   Updated: 2023/11/01 14:54:37 by halaoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_print(char c)
{
	write(1, &c, 1);
	c = 0;
}

void	ft_action(int signum, siginfo_t *info, void *context)
{
	static char	character;
	static int	bits;
	static int	id_client;
	int			x;

	(void)context;
	if (id_client != info->si_pid)
	{
		id_client = info->si_pid;
		bits = 0;
		character = 0;
	}
	if (signum == SIGUSR1)
		x = 1;
	else
		x = 0;
	character += x;
	bits++;
	if (bits == 8)
	{
		ft_print(character);
		bits = 0;
	}
	character <<= 1;
}

int	main(int ac, char **av)
{
	struct sigaction	sa;
	int					pid;

	(void) av;
	if (ac == 1)
	{
		pid = getpid();
		ft_putnbr(pid);
		ft_putchar('\n');
		sa.sa_sigaction = ft_action;
		sa.sa_flags = SA_SIGINFO;
		while (1)
		{
			sigaction(SIGUSR1, &sa, 0);
			sigaction(SIGUSR2, &sa, 0);
			pause();
		}
	}
	else
		ft_error("Error\n");
	return (0);
}
