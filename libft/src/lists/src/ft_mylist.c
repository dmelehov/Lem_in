/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mylist.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelehov <dmelehov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 19:16:20 by dmelehov          #+#    #+#             */
/*   Updated: 2018/01/30 20:59:52 by dmelehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libft.h"

static void	ft_list_funct_destroy(void *data)
{
	(void)data;
}

void		ft_list_init(t_mylist *v_this, void (*uf_funct_destroy)(void *data))
{
	v_this->v_begin = NULL;
	v_this->v_end = NULL;
	v_this->v_size = 0;
	v_this->ft_destroy = ft_list_funct_destroy;
	if (uf_funct_destroy != NULL)
		v_this->ft_destroy = uf_funct_destroy;
}

void		ft_list_clear(t_mylist *v_this)
{
	t_mylist_cell	*cur;
	t_mylist_cell	*del;

	cur = v_this->v_begin;
	while (cur != NULL)
	{
		del = cur;
		cur = cur->v_next;
		v_this->ft_destroy(del->v_data);
		ft_free_s((void **)&del);
	}
	D_LIST(init)(v_this, v_this->ft_destroy);
}

void		ft_list_destroy(t_mylist *v_this)
{
	D_LIST(clear)(v_this);
	v_this->v_begin = NULL;
	v_this->v_end = NULL;
	v_this->v_size = 0;
	v_this->ft_destroy = NULL;
}

void		ft_list_print_addr(const t_mylist *v_this)
{
	t_mylist_cell	*current;

	ft_putstr("\033[1;34mBegin\033[0m : ");
	ft_putaddr(v_this->v_begin);
	ft_putstr("\t\t\t\033[1;35mEnd\033[0m : ");
	ft_putaddr(v_this->v_end);
	ft_putstr("\n");
	current = v_this->v_begin;
	while (current != NULL)
	{
		ft_putaddr(current->v_prev);
		if (current->v_prev == NULL)
			ft_putchar('\t');
		ft_putstr("\t<- ");
		ft_putaddr(current);
		ft_putstr(" ->\t");
		ft_putaddr(current->v_next);
		ft_putstr("\n\033[0m");
		current = current->v_next;
	}
}
