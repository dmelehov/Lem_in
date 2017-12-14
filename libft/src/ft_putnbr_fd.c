/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelehov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/17 20:09:37 by dmelehov          #+#    #+#             */
/*   Updated: 2016/12/17 20:11:05 by dmelehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	ft_printnum_fd(long int temp, int size, int fd)
{
	char	res;

	while (size >= 1)
	{
		res = temp / size + 48;
		write(fd, &res, 1);
		temp = temp - (temp / size) * size;
		size = size / 10;
	}
}

void			ft_putnbr_fd(int n, int fd)
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
		write(fd, "-", 1);
	}
	while (temp >= 10)
	{
		temp = temp / 10;
		size *= 10;
	}
	temp = n;
	if (temp < 0)
		temp *= -1;
	ft_printnum_fd(temp, size, fd);
}
