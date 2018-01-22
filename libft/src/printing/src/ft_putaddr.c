/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelehov <dmelehov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 20:39:21 by dmelehov          #+#    #+#             */
/*   Updated: 2018/01/17 20:51:57 by dmelehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libft.h"
#define BASE "0123456789abcdef"

void	ft_putaddr(void *addr)
{
	size_t	nbr;
	size_t	digit;

	digit = 1;
	nbr = (size_t)addr;
	while ((nbr / digit) >= 16)
		digit = digit * 16;
	ft_putstr("0x");
	while (digit > 0)
	{
		ft_putchar(BASE[nbr / digit % 16]);
		digit = digit / 16;
	}
	ft_putchar('\n');
}

#undef BASE
