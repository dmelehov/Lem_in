/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mylist.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelehov <dmelehov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 18:22:22 by dmelehov          #+#    #+#             */
/*   Updated: 2018/01/28 16:55:38 by dmelehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MYLIST_H
# define FT_MYLIST_H

# include "ft_mylist_cell.h"
# include "ft_mylist_interval.h"

typedef struct		s_mylist
{
	t_mylist_cell	*v_begin;
	t_mylist_cell	*v_end;
	size_t			v_size;
	void			(*ft_destroy)(void *data);
}					t_mylist;

# define D_LIST(funct)	ft_list_##funct

/*
**	ft_mylist.c
*/

void				ft_list_init(t_mylist *v_this,
							void (*v_funct_destroy)(void *data));
void				ft_list_clear(t_mylist *v_this);
void				ft_list_destroy(t_mylist *v_this);
void				ft_list_print_addr(const t_mylist *v_this);

/*
**	ft_mylist_access.c
*/

t_mylist_cell		*ft_list_begin(const t_mylist *v_this);
t_mylist_cell		*ft_list_end(const t_mylist *v_this);
void				*ft_list_back(t_mylist *v_this);
void				*ft_list_front(t_mylist *v_this);
t_mylist_cell		*ft_list_get_cell(t_mylist *list, size_t cell_at);

/*
**	ft_mylist_capacity.c
*/

bool				ft_list_empty(const t_mylist *v_this);
size_t				ft_list_size(const t_mylist *v_this);

/*
**	ft_mylist_find.c
*/

t_mylist_cell		*ft_list_find(t_mylist *v_this, bool (*cmp)(void *, void *),
							void *d);

/*
**	ft_mylist_insert.c
*/

t_mylist_cell		*ft_list_insert(t_mylist *v_this, t_mylist_cell *position,
							void *data);

/*
**	ft_mylist_modifier.c
*/

t_mylist_cell		*ft_list_erase(t_mylist *v_this,
							t_mylist_cell *erase, void **data);
bool				ft_list_push_back(t_mylist *v_this, void *data);
void				ft_list_pop_back(t_mylist *v_this);
bool				ft_list_push_front(t_mylist *v_this, void *data);
void				ft_list_pop_front(t_mylist *v_this);

/*
**	ft_mylist_operator.c
*/

bool				ft_list_foreach_if(t_mylist *v_this,
							bool (*cmp)(void *data, void *value), void *value);
bool				ft_list_foreach(t_mylist *v_this,
							bool (*funct)(void *value));
void				ft_list_reverse(t_mylist *v_this);
t_mylist_cell		*ft_list_delete(t_mylist *v_this, t_mylist_cell *mb_delete);
void				ft_list_delete_if(t_mylist *v_this,
						bool (*cmp)(void *data, void *value), void *value);

/*
**	ft_mylist_splice.c
*/

void				ft_list_splice(t_mylist *v_this, t_mylist_cell *position,
						t_mylist *other_list,
						t_mylist_interval *other_interval);

/*
**	ft_mylist_split.c
*/

void				ft_list_split(t_mylist *v_this, t_mylist_cell *split_at,
						t_mylist *new_list);

#endif
