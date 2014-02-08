/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kube <kube@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/07 22:56:56 by kube              #+#    #+#             */
/*   Updated: 2014/02/08 00:10:38 by kube             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>

static void		send_char(int pid, char c, int sleep_duration)
{
	int			i;
	int			bit;

	i = 0;
	ft_putchar('\n');
	while (i < 8)
	{
		bit = (c >> (7 - i)) & 1;
		ft_putchar('0' + bit);
		if (bit)
			kill(pid, SIGUSR1);	
		else
			kill(pid, SIGUSR2);	
		usleep(sleep_duration);
		i++;
	}
}

static void		send_message(int pid, char *message, int sleep_duration)
{
	while (*message)
	{
		ft_putchar(*message);
		send_char(pid, *message, sleep_duration);
		message++;
	}
}

int				main(int argc, char **argv)
{
	int		pid;

	if (argc == 4)
	{
		pid = ft_atoi(argv[1]);
		send_message(pid, argv[2], ft_atoi(argv[3]));
	}
	return (0);
}
