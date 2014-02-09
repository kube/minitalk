/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kube <kube@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/07 22:56:56 by kube              #+#    #+#             */
/*   Updated: 2014/02/09 23:17:28 by kube             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"
#include <libft.h>
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>

static void				send_char()
{
	int					i;
	int					bit;

	i = 0;
	while (i < 8)
	{
		bit = (env.message[env.i] >> (7 - i)) & 1;
		if (bit)
			kill(env.server, SIGUSR1);
		else
			kill(env.server, SIGUSR2);	
		usleep(BIT_LATENCY);
		i++;
	}
}

static void				update_send(int sig, siginfo_t *siginfo, void *context)
{
	(void)context;
	if ((int)siginfo->si_pid == env.server && sig == SIGUSR1)
		env.i++;
	send_char();
	if (!env.message[env.i])
		exit (0);
}

int						main(int argc, char **argv)
{
	struct sigaction	act;

	if (argc == 3)
	{
		ft_bzero(&act, sizeof(act));
		act.sa_sigaction = &update_send;
		act.sa_flags = SA_SIGINFO;
		if (sigaction(SIGUSR1, &act, NULL) < 0
			|| sigaction(SIGUSR2, &act, NULL) < 0)
			return 1;
		env.server = ft_atoi(argv[1]);
		env.i = 0;
		env.message = argv[2];
		send_char();
		while (1)
			usleep(1000);
	}
	return (0);
}
