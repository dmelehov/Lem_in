/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_latoi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelehov <dmelehov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 15:54:40 by dmelehov          #+#    #+#             */
/*   Updated: 2018/02/01 15:56:13 by dmelehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libft.h"
#define SKIPCHAR "\t\v\n\r\f "

intmax_t	ft_latoi(const char *str)
{
	size_t		i;
	intmax_t	nb;
	int			neg;

	i = 0;
	nb = 0;
	neg = 0;
	while (ft_strchr(SKIPCHAR, str[i]) ||
		(str[i] == '+' && ft_isdigit(str[i + 1])))
		i++;
	if (str[i] == '-' && ft_isdigit(str[i + 1]) && ++i)
		neg = 1;
	while (ft_isdigit(str[i]))
		nb = nb * 10 + ((int)str[i++] - 48);
	return (neg == 1 ? -nb : nb);
}

#undef SKIPCHAR
