/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_capacity.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelehov <dmelehov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 17:13:35 by dmelehov          #+#    #+#             */
/*   Updated: 2018/01/17 17:14:15 by dmelehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libft.h"

bool	ft_array_empty(const t_array *v_this)
{
	return (v_this->v_size == 0);
}

size_t	ft_array_capacity(const t_array *v_this)
{
	return (v_this->v_capacity);
}

size_t	ft_array_size(const t_array *v_this)
{
	return (v_this->v_size);
}
