/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelehov <dmelehov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 15:47:10 by dmelehov          #+#    #+#             */
/*   Updated: 2018/01/31 18:34:31 by dmelehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# include "../libft/includes/libft.h"

# define STATUS {0,0,0,0,0,0,0,0,0,0,NULL,NULL,NULL,NULL,NULL,NULL,NULL}
# define ERC status->debug

typedef struct		s_path
{
	char			*name;
	char			*from;
	struct s_path	*next;
	struct s_path	*ways;
}					t_path;

typedef struct		s_node
{
	char			*name;
	int				x;
	int				y;
	struct s_array	*link;
}					t_node;

typedef struct		s_status
{
	int				ant_num;
	int				start_exist;
	int				end_exist;
	int				cur_cmnd;
	int				cur_input_type;
	int				max_path_num;
	int				debug;
	int				pr_paths;
	int				pr_mult;
	int				quiet;
	char			*start;
	char			*end;
	struct s_mylist	*node;
	struct s_array	*output;
	struct s_mylist	*ans;
	struct s_path	*ants;
	struct s_path	*toprint;
}					t_status;

/*
** flag_manager.c
*/

void				flag_seter(t_status *status, int ac, char *s);

/*
**  memory_liberator.c
*/

void				ft_memory_liberator(t_status *status);

/*
** input_data_validation.c
*/

int					ft_validator(t_status *status, int ret);
int					ft_check_comand(t_status *status, char *line);
int					ft_get_input(char *line, t_status *status);
void				ft_check_status(t_status *status, int inp_type);

/*
**  input_getters_validation.c
*/

int					ft_get_ants_num(char *line, t_status *status);
int					ft_get_room_data(char **arr, t_status *status);
void				ft_add_a_link(t_status *status, char *from, char *to);
int					ft_get_links_data(char **s, t_status *status);

/*
** other_checkers.c
*/

bool				check_name(void *data, void *s);
bool				check_dup_name(void *data, void *s);
bool				check_name2(void *data, void *s);
int					ft_not_in_ans(t_mylist *lst, char *name);
int					ft_not_in_queue(t_path *queue, char *s);

/*
** input_formating_checkers.c
*/

char				*get_next_path_elem(t_path *queue, char *s);
int					check_delimeters(char const *s, char c);
int					check_num_str(char *line, int erc);
bool				check_cordinates(void *data, void *dot);
void				set_queue_free(t_path *queue);

/*
**  ft_solution.c
*/

void				ft_bfs_solution(t_status *status);

/*
**  print_output.c
*/

void				ft_print_answer(t_status *status);

/*
**  ft_printer.c
*/

void				ft_print_status_struct(t_status *data);
void				ft_print_found_paths(t_path *path);
bool				ft_print_paths(void *data);
bool				ft_print_output(void *data);
bool				print_solution(void *ans);

/*
**  ft_printer2.c
*/

void				ft_napominalka(void);
bool				ft_print_node(void *data);
void				ft_print_queue(t_path *queue);
bool				ft_print_links(void *data);
bool				ft_print_visited(void *data);

/*
**  because_iam_nice.c
*/

void				ft_memory_liberator(t_status *status);

/*
**	and_other_checkers.c
*/

void				check_struct_fullness(t_status *status);
void				check_path_presence(t_status *status);
void				optimize_paths(t_status *status);

#endif
