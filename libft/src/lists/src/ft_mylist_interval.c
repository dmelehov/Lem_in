/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mylist_interval.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelehov <dmelehov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 20:17:39 by dmelehov          #+#    #+#             */
/*   Updated: 2018/01/26 20:09:49 by dmelehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libft.h"

void			ft_list_interval_init(t_mylist_interval *v_this,
						t_mylist_cell *begin, t_mylist_cell *end)
{
	v_this->v_begin = begin;
	v_this->v_end = end;
}

t_mylist_cell	*ft_list_interval_begin(const t_mylist_interval *v_this)
{
	return (v_this->v_begin);
}

t_mylist_cell	*ft_list_interval_end(const t_mylist_interval *v_this)
{
	return (v_this->v_end);
}
