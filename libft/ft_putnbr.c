/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 02:46:45 by cfeijoo           #+#    #+#             */
/*   Updated: 2013/12/18 10:59:47 by cfeijoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void		ft_putnbr(int n)
{
	char	a;

	if (n < 0)
		write(1, "-", 1);
	if (n / 10)
		ft_putnbr(ft_abs(n / 10));
	a = '0' + ft_abs(n % 10);
	write(1, &a, 1);
}
