/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kube <kube@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/09 19:45:31 by kube              #+#    #+#             */
/*   Updated: 2014/02/09 23:19:30 by kube             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H
# define BIT_LATENCY 100

typedef struct				s_env
{
	int						server;
	int						i;
	char					*message;
}							t_env;

t_env		env;

#endif