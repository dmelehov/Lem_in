/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mylist_interval.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelehov <dmelehov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 18:49:33 by dmelehov          #+#    #+#             */
/*   Updated: 2018/01/17 19:11:41 by dmelehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MYLIST_INTERVAL_H
# define FT_MYLIST_INTERVAL_H

typedef struct			s_mylist_interval
{
	t_mylist_cell		*v_begin;
	t_mylist_cell		*v_end;
}						t_mylist_interval;

# define D_LIST_INTERVAL(funct)	ft_list_interval_##funct

void					ft_list_interval_init(t_mylist_interval *v_this,
							t_mylist_cell *begin, t_mylist_cell *end);
t_mylist_cell			*ft_list_interval_begin
							(const t_mylist_interval *v_this);
t_mylist_cell			*ft_list_interval_end(const t_mylist_interval *v_this);

#endif
