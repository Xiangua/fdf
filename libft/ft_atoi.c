/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: folier <folier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/11 22:23:59 by folier            #+#    #+#             */
/*   Updated: 2015/05/19 09:24:27 by folier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int		ft_atoi(const char *str)
{
	int		i;
	int		compt;
	int		min;

	i = 0;
	compt = 0;
	min = 0;
	while (str[i] == ' ' || (str[i] >= 8 && str[i] <= 14))
		i++;
	if (str[i] == '-')
	{
		i++;
		min++;
	}
	else if (str[i] == '+')
		i++;
	while (ft_isdigit(str[i]))
	{
		compt = compt * 10;
		compt = compt + str[i] - '0';
		i++;
	}
	if (min > 0)
		return (-compt);
	return (compt);
}
