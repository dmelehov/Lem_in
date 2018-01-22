/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelehov <dmelehov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/17 18:51:54 by dmelehov          #+#    #+#             */
/*   Updated: 2017/12/29 18:55:32 by dmelehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libft.h"

void			ft_putnbr(int n)
{
	long	num;
	char	res;

	num = n;
	if (n < 0)
		write(1, "-", 1);
	num = (n < 0 ? -num : num);
	if (num >= 10)
		ft_putnbr(num / 10);
	res = (num % 10) + '0';
	write(1, &res, 1);
}
