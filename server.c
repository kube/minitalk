/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kube <kube@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/07 22:57:31 by kube              #+#    #+#             */
/*   Updated: 2014/02/08 00:05:16 by kube             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>

static void				add_bit(int sig)
{
	static int			i = 0;
	static char			c;

	i++;
	c = c << 1;
	if (sig == SIGUSR1)
		c += 1;
	if (i == 8)
	{
		i = 0;
		ft_putchar(c);
	}
	// static t_message	*message;
}

int						main(void)
{
	ft_putnbr(getpid());
	ft_putstr("\n");
	signal(SIGUSR1, add_bit);
	signal(SIGUSR2, add_bit);
	while (1)
		sleep(100000);
	return (0);
}
