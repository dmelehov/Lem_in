#ifndef LEMIN_H
# define LEMIN_H

#include "libft/includes/libft.h"
#include <stdio.h>

typedef struct      s_path
{
	char            *name;
	char            *from;
	struct s_path   *next;
	struct s_path   *ways;
}                   t_path;

typedef struct      s_node
{
	char            *name;
	int             x;
	int             y;
	struct s_node   *link;
}                   t_node;

typedef struct      s_status
{
	int     ant_num;
	int     start_exist;
	int     end_exist;
	int     cur_cmnd;
	int     cur_input_type;
	char    *start;
	char    *end;
	struct s_path   *ans;
	struct s_mylist *node;
}					t_status;

// t_node  *get_next_node(t_node *node);

/*
**  validator01.c
*/

int		ft_get_input(char *line, t_status *status);
void	ft_check_status(t_status *status, int inp_type);
int		ft_check_comand(t_status *status, char *line);
int		ft_validator(t_status *status);

int     check_delimeters(char const *s, char c);
int      ft_get_ants_num(char *line, t_status *status);
int     check_num_str(char *line);


#endif


// typedef struct		s_mylist
// {
// 	t_mylist_cell	*v_begin;
// 	t_mylist_cell	*v_end;
// 	size_t			v_size;
// 	void			(*ft_destroy)(void *data);
// }					t_mylist;

// typedef struct				s_mylist_cell
// {
// 	struct s_mylist_cell	*v_next;
// 	struct s_mylist_cell	*v_prev;
// 	void					*v_data;
// }							t_mylist_cell;

// typedef struct			s_mylist_interval
// {
// 	t_mylist_cell		*v_begin;
// 	t_mylist_cell		*v_end;
// }						t_mylist_interval;
