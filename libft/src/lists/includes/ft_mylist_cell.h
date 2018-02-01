/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mylist_cell.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelehov <dmelehov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 18:49:33 by dmelehov          #+#    #+#             */
/*   Updated: 2018/01/23 18:57:07 by dmelehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MYLIST_CELL_H
# define FT_MYLIST_CELL_H

typedef struct				s_mylist_cell
{
	struct s_mylist_cell	*v_next;
	struct s_mylist_cell	*v_prev;
	void					*v_data;
}							t_mylist_cell;

# define D_LIST_CELL(funct)	ft_list_cell_##funct

/*
** ft_list_cell.c
*/

size_t						ft_list_cell_count(const t_mylist_cell *other_begin,
								const t_mylist_cell *other_end);
t_mylist_cell				*ft_list_cell_next(const t_mylist_cell *cur);
t_mylist_cell				*ft_list_cell_prev(const t_mylist_cell *cur);
t_mylist_cell				*ft_list_cell_create(t_mylist_cell *prv,
								t_mylist_cell *nxt, void *data);
#endif
