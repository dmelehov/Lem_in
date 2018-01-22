/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelehov <dmelehov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 17:07:59 by dmelehov          #+#    #+#             */
/*   Updated: 2017/10/17 06:24:00 by dmelehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/includes/libft.h"

int 	main(void)
{
	int i;

	i = ft_atoi("-123");
//	ft_bzero((void *)&i, sizeof(i));
//	for (int j = 0; j < 5; j++)
		printf("%d\n", i);
	return (0);
}