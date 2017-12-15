#ifndef LEMIN_H
#define LEMIN_H

#include "libft/includes/libft.h"
#include "libft/includes/get_next_line.h"
#include <stdio.h>


typedef struct      s_node
{
    char            *name;
    int             status;
    int             x;
    int             y;
    int             *links;
    struct s_node   *next;
}                   t_node;

#endif //LEM_IN_LEMIN_H
