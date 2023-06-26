/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 15:09:20 by tde-souz          #+#    #+#             */
/*   Updated: 2022/10/10 16:39:25 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	atobin(char c, pid_t pid)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if (c & (1 << i))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		i--;
		usleep(300);
	}
}

void	sighandler(int sig)
{
	if (sig == SIGUSR1)
		ft_putstr_fd("\e[38;5;118mMessage delivered.\e[0m\n", 1);
}

int	main(int argc, char *argv[])
{
	pid_t				pid;
	struct sigaction	sa;

	sa.sa_handler = &sighandler;
	sa.sa_flags = SA_RESTART;
	sigaction(SIGUSR1, &sa, NULL);
	if (argc > 1)
	{
		pid = (pid_t) ft_atoi(argv[1]);
		if (argc != 3)
			return (-1);
		if (argv[2])
			while (*argv[2])
				atobin(*argv[2]++, pid);
		atobin(0, pid);
	}
	return (0);
}
