/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mylist_capacity.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelehov <dmelehov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 19:39:48 by dmelehov          #+#    #+#             */
/*   Updated: 2018/01/17 19:40:25 by dmelehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libft.h"

bool			ft_list_empty(const t_mylist *v_this)
{
	return (v_this->v_size == 0);
}

size_t			ft_list_size(const t_mylist *v_this)
{
	return (v_this->v_size);
}
