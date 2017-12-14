/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelehov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/17 18:51:54 by dmelehov          #+#    #+#             */
/*   Updated: 2016/12/17 21:00:03 by dmelehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	ft_printnum(long int temp, int size)
{
	char	res;

	while (size >= 1)
	{
		res = temp / size + 48;
		write(1, &res, 1);
		temp = temp - (temp / size) * size;
		size = size / 10;
	}
}

void			ft_putnbr(int n)
{
	int			neg;
	long int	temp;
	int			size;

	temp = n;
	neg = 0;
	size = 1;
	if (temp < 0)
	{
		neg = 1;
		temp *= -1;
		write(1, "-", 1);
	}
	while (temp >= 10)
	{
		temp = temp / 10;
		size *= 10;
	}
	temp = n;
	if (temp < 0)
		temp *= -1;
	ft_printnum(temp, size);
}
