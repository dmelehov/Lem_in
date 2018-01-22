/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mylist_cell_count.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelehov <dmelehov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 19:47:51 by dmelehov          #+#    #+#             */
/*   Updated: 2018/01/17 19:48:29 by dmelehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libft.h"

size_t	ft_list_cell_count(const t_mylist_cell *other_begin,
					const t_mylist_cell *other_end)
{
	size_t	count;

	count = 0;
	if (other_end != NULL)
	{
		while (other_begin != NULL)
		{
			if (other_begin == other_end)
			{
				count = count + 1;
				break ;
			}
			count = count + 1;
			other_begin = other_begin->v_next;
		}
	}
	return (count);
}
