#ifndef LEMIN_H
#define LEMIN_H

#include "libft/includes/libft.h"
#include "libft/includes/get_next_line.h"
#include <stdio.h>

typedef struct      s_link
{
    char            *name;
    struct s_link   *next;
}                   t_links;

typedef struct      s_node
{
    char            *name;
    int             x;
    int             y;
    struct s_node   *link;
    struct s_node   *next;
}                   t_node;

typedef struct      s_status
{
    int     ant_num;
    int     start_exist;
    int     end_exist;
    int     cur_cmnd;
    int     cur_input_type;
}                   t_status;

t_node  *get_next_node(t_node *node);

#endif //LEM_IN_LEMIN_H
