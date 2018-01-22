/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelehov <dmelehov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/17 20:09:37 by dmelehov          #+#    #+#             */
/*   Updated: 2017/12/29 19:18:47 by dmelehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libft.h"

void			ft_putnbr_fd(int n, int fd)
{
	long	num;
	char	res;

	num = n;
	if (n < 0)
		write(fd, "-", 1);
	num = (n < 0 ? -num : num);
	if (num >= 10)
		ft_putnbr_fd(num / 10, fd);
	res = (num % 10) + '0';
	write(fd, &res, 1);
}
