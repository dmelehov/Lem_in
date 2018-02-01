/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_output.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelehov <dmelehov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 15:45:19 by dmelehov          #+#    #+#             */
/*   Updated: 2018/01/31 21:02:31 by dmelehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

static int		they_are_all_there(t_path *ants, char *s)
{
	while (ants)
	{
		if (ft_strequ(ants->from, s))
			ants = ants->next;
		else
			return (1);
	}
	return (0);
}

static t_path	*create_ants_list(int num, char *s)
{
	t_path	*ants;
	t_path	*lst;
	int		i;

	i = 1;
	ants = (t_path *)malloc(sizeof(t_path));
	*ants = (t_path){ft_itoa(i++), s, NULL, NULL};
	lst = ants;
	num -= 1;
	while (num--)
	{
		ants->next = (t_path *)malloc(sizeof(t_path));
		ants = ants->next;
		*ants = (t_path){ft_itoa(i), s, NULL, NULL};
		i++;
	}
	return (lst);
}

static t_path	*find_current(t_path *lst, char *s)
{
	t_path *backup;
	t_path *lst2;

	backup = lst;
	while (lst)
	{
		lst2 = lst;
		while (lst2)
		{
			if (ft_strequ(lst2->from, s))
				return (lst2);
			else
				lst2 = lst2->next;
		}
		lst = lst->ways;
	}
	return (backup);
}

static int		set_ant_move(t_path *lst, t_path *curnt, char *end, int i)
{
	t_path	*cur;

	cur = find_current(lst, curnt->name);
	if (cur->next && cur->next->from == NULL)
	{
		if (i != 0)
			ft_printf(" ");
		cur->from = NULL;
		if (!ft_strequ(cur->next->name, end))
			cur->next->from = curnt->name;
		curnt->from = cur->next->name;
		if (ft_strequ(curnt->from, end))
			ft_printf("{yellow}");
		else
			ft_printf("{cyan}");
		ft_printf("L%s-%s", curnt->name, curnt->from);
		ft_printf("{eoc}");
		return (1);
	}
	else if (lst->ways && cur->next && cur->next->from != NULL)
		if (set_ant_move(lst->ways, curnt, end, i))
			return (1);
	return (0);
}

void			ft_print_answer(t_status *status)
{
	t_path	*curnt;
	t_path	*lst;
	int		i;

	i = 0;
	status->ants = create_ants_list(status->ant_num, status->start);
	while (they_are_all_there(status->ants, status->end))
	{
		lst = status->toprint;
		curnt = status->ants;
		i = 0;
		while (curnt)
		{
			if (!ft_strequ(curnt->from, status->end))
				if (set_ant_move(lst, curnt, status->end, i))
					i++;
			curnt = curnt->next;
		}
		ft_printf("\n");
	}
}
