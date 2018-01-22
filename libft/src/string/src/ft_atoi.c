/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelehov <dmelehov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 17:07:59 by dmelehov          #+#    #+#             */
/*   Updated: 2017/12/29 09:35:06 by dmelehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libft.h"
#define SKIPCHAR "\t\v\n\r\f "

int		ft_atoi(const char *str)
{
	size_t	i;
	int		nb;
	int		neg;

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
