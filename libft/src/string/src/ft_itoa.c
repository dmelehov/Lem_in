/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelehov <dmelehov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 17:09:12 by dmelehov          #+#    #+#             */
/*   Updated: 2018/01/05 09:54:23 by dmelehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libft.h"

static	int		find_num_len(int n, int i)
{
	if (n != 0)
		i += find_num_len(n / 10, 1);
	return (i);
}

static	void	get_num_str(char *s, long int n, int len)
{
	n = n < 0 ? -n : n;
	while (len >= 0)
	{
		s[len--] = n % 10 + '0';
		n = n / 10;
	}
}

char			*ft_itoa(int n)
{
	int		len;
	char	*s;

	len = n < 0 ? find_num_len(n / 10, 1) + 1 : find_num_len(n / 10, 1);
	if (!(s = ft_strnew(len--)))
		return (NULL);
	get_num_str(s, n, len);
	if (n < 0)
		s[0] = '-';
	return (s);
}
