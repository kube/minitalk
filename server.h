/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kube <kube@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/09 18:48:12 by kube              #+#    #+#             */
/*   Updated: 2014/02/09 23:20:23 by kube             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H
# define CHECK_DELAY 1000
# define MAX_BIT_DELAY 7000

typedef struct			s_char
{
	int					i;
	char				data;
	struct s_char		*next;
}						t_char;

typedef struct			s_env
{
	int					client;
	int					i;
	t_char				*string;
	t_char				*c;
	int					last_time;
	int					elapsed;
}						t_env;

t_env					env;

#endif