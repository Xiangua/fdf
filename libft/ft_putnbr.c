/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: folier <folier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/11 22:31:08 by folier            #+#    #+#             */
/*   Updated: 2015/05/19 09:29:07 by folier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static void		ft_putnbr_neg(int n)
{
	if (n <= 9)
		ft_putchar(n + '0');
	else
	{
		ft_putnbr_neg(n / 10);
		ft_putchar(n % 10 + '0');
	}
}

void			ft_putnbr(int n)
{
	if (n < 0)
	{
		ft_putchar('-');
		if (n == -2147483648)
			ft_putstr("2147483648");
		else
			ft_putnbr(-n);
	}
	else
		ft_putnbr_neg(n);
}
