/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kube <kube@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/07 22:57:31 by kube              #+#    #+#             */
/*   Updated: 2014/02/09 23:21:42 by kube             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include <libft.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>

static void				display_line()
{
	t_char				*current;
	t_char				*last;

	current = env.string;
	ft_putnbr(env.client);
	ft_putstr(" : ");
	while (current)
	{
		write(1, &current->data, 1);
		last = current;
		current = current->next;
		free(last);
	}
}

static void				check_integrity()
{
	if (env.client && env.elapsed - env.last_time > MAX_BIT_DELAY)
	{
		env.i = 0;
		kill(env.client, SIGUSR2);
	}
}

static void				add_bit(int sig, siginfo_t *siginfo, void *context)
{
	(void)context;
	if ((siginfo->si_pid == env.client || !env.client)
		&& siginfo->si_pid != getpid())
		env.client = siginfo->si_pid;
	else
		return ;
	env.i++;
	env.c->data = env.c->data << 1;
	if (sig == SIGUSR1)
		env.c->data += 1;
	env.last_time = env.elapsed;
	if (env.i == 8)
	{
		env.i = 0;
		kill(env.client, SIGUSR1);
		if (!env.c->data)
		{
			display_line();
			write(1, "\n", 1);
			env.client = 0;
			env.c = (t_char*)malloc(sizeof(t_char));
			env.string = env.c;
		}
		else
		{
			env.c->next = (t_char*)malloc(sizeof(t_char));
			env.c = env.c->next;
		}
	}
}

int						main(void)
{
	struct sigaction	act;

	env.elapsed = 0;
	ft_bzero(&act, sizeof(act));
	act.sa_sigaction = &add_bit;
	act.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &act, NULL) < 0
		|| sigaction(SIGUSR2, &act, NULL) < 0)
		return 1;
	env.i = 0;
	env.client = 0;
	env.c = (t_char*)malloc(sizeof(t_char));
	env.string = env.c;
	ft_putnbr(getpid());
	ft_putstr("\n");
	while (1)
	{
		check_integrity();
		usleep(CHECK_DELAY);
		env.elapsed += CHECK_DELAY;
	}
	return (0);
}
