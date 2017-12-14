/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelehov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 17:09:12 by dmelehov          #+#    #+#             */
/*   Updated: 2016/12/17 20:04:24 by dmelehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_lencount(long int temp)
{
	int i;

	i = 0;
	if (temp == 0)
		i++;
	while (temp != 0)
	{
		temp = temp / 10;
		i++;
	}
	return (i);
}

char			*ft_itoa(int n)
{
	int			i;
	int			neg;
	long int	temp;
	long int	r;
	char		*res;

	neg = 0;
	if (n < 0)
		neg = 1;
	i = ft_lencount(n);
	if (!(res = (char *)malloc(sizeof(char) * (i + neg + 1))))
		return (NULL);
	res[i-- + neg] = '\0';
	temp = (long int)n;
	if (temp < 0)
		temp *= -1;
	if (neg == 1)
		res[0] = 45;
	while (i >= 0)
	{
		r = temp - (temp / 10) * 10;
		res[i-- + neg] = (char)r + 48;
		temp = temp / 10;
	}
	return (res);
}
