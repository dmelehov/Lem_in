#include "lemin.h"

void    error_mngr(int er_num)
{
    write(1, "ERROR\n", 6);
    if (er_num == 1)
        write(1, "The param should be a positive number without whitespaces\n", 67);
    else if (er_num == 2)
        write(1, "Incorrect input, line break\n", 28);
    else if (er_num == 3)
        write(1, "Room name does not suppose to start with 'L' or '#'\n", 52);
    else if (er_num == 4)
        write(1, "There must be a room data after a command\n", 42);
    else if (er_num == 5)
        write(1, "Wrong argument set as a input parametr\n", 39);
    exit(0);
}

int     check_num_str(char *line)
{
    int i;
    int res;

    i = 0;
    while (line[i])
    {
        if (ft_isdigit(line[i]))
            i++;
        else
            error_mngr(1);
    }
    res = ft_atoi(line);
    return (res);
}

t_node  *ft_get_input(char *line, t_node *node, int status)
{
    char **s;
    int i;

    i = 0;
    s = ft_strsplit(line, 32);
    while (s[i])
        i++;
    if (i != 1 && i != 3)
        error_mngr(5);
    if (i == 3)
    {
        node->name = ft_strdup(s[0]);
        node->x = check_num_str(s[1]);
        node->y = check_num_str(s[2]);
    }
    else if (i == 1)
    {

    }
}

t_node  *ft_check_comand( char *line, t_node *node)
{
    int i;

    i = 0;
    if (!ft_strcmp(line + 2, "start"))
        i = 1;
    else if (!ft_strcmp(line + 2, "end"))
        i = 2;
    else
        return (NULL);
    node = ft_get_input(line, node);
    if (!node)
        error_mngr(4);
    else
        node->status = i;
    return (node);
}

int     ft_validator(void)
{
    char    *line;
    int     ant_num;
    t_node  *node;
    int     i;

    i = 0;
    line = NULL;
    get_next_line(0, &line);
    ant_num = check_num_str(line);
    if (ant_num <= 0)
        error_mngr(1);
    node = (t_node *)malloc(sizeof(t_node));
    while (get_next_line(0, &line) > 0 && line[0] != '\0')
    {
        if (line[0] == 'L')
            error_mngr(3);
        else if (line[0] == '#' && line[1] == '#')
            node = ft_check_comand(line, node);
        else if (line[0] == '#')
            continue ;
        else
            node = ft_get_input(line, node);
    }
    if (!(line) || line[0] == '\0')
        error_mngr(2);
    printf("%d\n", ant_num);
    return (1);
}

int     main(void)
{
    if (ft_validator())
        printf("Good\n");
//    int     ant_num;
//    char *line;
//    t_map   *

//    while (get_next_line(0, &line))
//        printf("%s\n", line);
    return (0);
}
