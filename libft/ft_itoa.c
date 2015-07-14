/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: folier <folier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/11 22:27:39 by folier            #+#    #+#             */
/*   Updated: 2015/05/19 09:25:35 by folier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static char		*ft_reverse(char *src)
{
	char	*tmp;
	int		i;
	int		cnt;

	i = ft_strlen(src) - 1;
	cnt = 0;
	tmp = (char *)malloc(sizeof(char*) * (i + 1));
	while (i > 0)
	{
		tmp[cnt] = src[i];
		cnt++;
		i--;
	}
	tmp[cnt] = src[i];
	cnt++;
	tmp[cnt] = '\0';
	return (tmp);
}

static char		*ft_itoa_res(int n, int result, char *dest, int neg)
{
	int		i;
	int		test;

	i = 0;
	test = 1;
	while (n)
	{
		if (neg < 0 && test > 0)
		{
			dest[i] = (n % 10) + 1 + '0';
			n = n / 10;
			i++;
		}
		else
		{
			result = n % 10;
			dest[i] = '0' + result;
			n = n / 10;
			i++;
		}
		test = 0;
	}
	if (neg < 0)
		dest[i] = '-';
	return (dest);
}

static char		*ft_itoa_real(int n, char *dest)
{
	int		result;
	int		neg;
	int		i;

	i = 0;
	result = 0;
	neg = n;
	if (n == -1)
	{
		dest[i] = '-';
		dest[i + 1] = '1';
		dest[i + 2] = '\0';
		return (dest);
	}
	if (n < 0)
	{
		n = -n;
		n--;
	}
	dest = ft_itoa_res(n, result, dest, neg);
	dest[13] = '\0';
	dest = ft_reverse(dest);
	return (dest);
}

char			*ft_itoa(int n)
{
	int		i;
	char	*dest;

	i = 0;
	dest = (char*)malloc(sizeof(char*) * 13);
	if (dest == NULL)
		return (NULL);
	if (n == 0)
	{
		dest[i] = '0';
		dest[i + 1] = '\0';
		return (dest);
	}
	dest = ft_itoa_real(n, dest);
	return (dest);
}
