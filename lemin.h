#ifndef LEMIN_H
#define LEMIN_H

#include "libft/includes/libft.h"
#include "libft/includes/get_next_line.h"
#include <stdio.h>


typedef struct s_node
{
    char *name;
    int x;
    int y;
    int status;
    char *next;
}               t_node;

typedef struct  s_map
{
    int     num_of_ants;
}               t_map;



#endif //LEM_IN_LEMIN_H
