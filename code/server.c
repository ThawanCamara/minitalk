/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 15:10:24 by tde-souz          #+#    #+#             */
/*   Updated: 2022/10/19 20:37:15 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	sighandler(int sig, siginfo_t *info, void *context)
{
	static int	c;
	static int	index;

	(void)context;
	if (sig == SIGUSR1)
			c += 128 >> index; 
	if (index == 7)
	{
		ft_putchar_fd(c, 1);
		if (c == 0)
			kill(info->si_pid, SIGUSR1);
		c = 0;
		index = -1;
	}
	index++;
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = &sighandler;
	sa.sa_flags = SA_RESTART | SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	ft_printf("\e[38;5;118mProcess Started\e[0m\n");
	ft_printf("PID: \e[38;5;118m%d\e[0m\n", getpid());
	while (1)
		pause();
	return (0);
}
