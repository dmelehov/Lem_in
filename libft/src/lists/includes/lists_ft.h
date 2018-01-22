/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists_ft.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelehov <dmelehov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 11:18:42 by dmelehov          #+#    #+#             */
/*   Updated: 2017/12/29 18:39:52 by dmelehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LISTS_FT_H
# define LISTS_FT_H

typedef	struct			s_list
{
	void				*content;
	size_t				content_size;
	struct s_list		*next;
}						t_list;

/*
** Allocates memory and returns a “fresh” link. The
** variables content and content_size of the new link are initialized
** by copy of the parameters of the function. If the parameter
** content is nul, the variable content is initialized to
** NULL and the variable content_size is initialized to 0 even
** if the parameter content_size isn’t. The variable next is
** initialized
*/

t_list					*ft_lstnew(void const *content, size_t content_size);

/*
** Adds the element new at the beginning of the list.
*/

void					ft_lstadd(t_list **alst, t_list *new);

/*
** Free the memory of the first
** link of a list with free and content memory with del function
*/

void					ft_lstdel(t_list **alst, void (*del)(void*, size_t));

/*
** Free the memory of link with free and content memory with del function
*/

void					ft_lstdelone(t_list **alst, void (*del)(void*, size_t));

/*
** Iterates the list lst and applies the function f to each link.
*/

void					ft_lstiter(t_list *lst, void (*f)(t_list *elem));

/*
** Applyes a function f() and returns a fresh copy list
*/

t_list					*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

#endif
