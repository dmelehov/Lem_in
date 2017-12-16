#include "lemin.h"

void    error_mngr(int er_num)
{
    write(1, "ERROR\n", 6);
    if (er_num == 1)
        write(1, "The param should be a positive number without whitespaces\n", 58);
    else if (er_num == 2)
        write(1, "Incorrect input, line break\n", 28);
    else if (er_num == 3)
        write(1, "Room name does not suppose to start with 'L' or '#'\n", 52);
    else if (er_num == 4)
        write(1, "There must be a room data after a command\n", 42);
    else if (er_num == 5)
        write(1, "Wrong argument set as a input parametr\n", 39);
    else if (er_num == 6)
        write(1, "There can be only one start and end\n", 36);
    else if (er_num == 7)
        write(1, "There must be a room after command\n", 35);
    else if (er_num == 8)
        write(1, "Wrong input sequence\n", 35);
    else if (er_num == 9)
        write(1, "Room with a current name allready exist\n", 35);
    else if (er_num == 10)
        write(1, "Wrong link input\n", 17);
    else if (er_num == 11)
        write(1, "Duplicated links\n", 17);
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

t_node     *check_name(t_node *node, char *s)
{
    while (node)
    {
        if (!ft_strcmp(s, node->name))
            return (node);
        node = node->next;
    }
    return (NULL);
}

void    get_links(t_node *node, char *str)
{
    t_node *lst;

    lst = node->link;
    if (!check_name(lst, str))
    {
        lst = get_next_node(lst->link);
        lst->name = ft_strdup(str);
    }
    else
        error_mngr(11);

}

void    check_links(t_node *node, char *s)
{

    char **arr;
    int  i;

    arr = ft_strsplit(s, '-');
    i = 0;
    while (arr[i])
        i++;
    if (i != 2)
        error_mngr(10);
    if (!check_name(node, arr[0]) || !check_name(node, arr[1]))
        error_mngr(10);
    get_links(check_name(node, arr[0]), arr[1]);
    get_links(check_name(node, arr[1]), arr[0]);
}

t_node  *get_next_node(t_node *node)
{
    if (node == NULL)
    {
        node = (t_node *)malloc(sizeof(t_node));
        *node = (t_node){NULL, 0, 0, NULL, NULL};
        return (node);
    }
    while (node->next != NULL)
        node = node->next;
    node->next = (t_node *)malloc(sizeof(t_node));
    node = node->next;
    *node = (t_node){NULL, 0, 0, NULL, NULL};
    return (node);
}

int     ft_get_input(char *line, t_node *node)
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
        if (check_name(node, s[0]))
            error_mngr(9);
        node = get_next_node(node);
        node->name = ft_strdup(s[0]);
        node->x = check_num_str(s[1]);
        node->y = check_num_str(s[2]);
    }
    else if (i == 1)
    {
        check_links(node, s[0]);
        i = 5;
    }
    return (i);
}

int  ft_check_comand(char *line, t_status *status)
{
    if (!ft_strcmp(line + 2, "start"))
    {
        if (status->start_exist == 0)
        {
            status->start_exist = 1;
            return (1);
        }
        else
            error_mngr(6);
    }
    else if (!ft_strcmp(line + 2, "end"))
    {
        if (status->end_exist == 0)
        {
            status->end_exist = 1;
            return (2);
        }
        else
            error_mngr(6);
        // return (status->end_exist == 0 ? 2 : error_mngr(6));
    }
    return (0);
}

void     ft_check_status(t_status *status, int inp_type)
{
    if (status->cur_cmnd != 0 && inp_type != 3)
        error_mngr(7);
    if (status->cur_input_type > inp_type)
        error_mngr(8);
    status->cur_input_type = inp_type;
    status->cur_cmnd = 0;
}

int     ft_validator(t_status *status, t_node *node, char *line)
{
    get_next_line(0, &line);
    status->ant_num = check_num_str(line);
    if (status->ant_num <= 0)
        error_mngr(1);
    while (get_next_line(0, &line) > 0 && line[0] != '\0')
    {
        if (line[0] == 'L')
            error_mngr(3);
        else if (line[0] == '#' && line[1] == '#')
            status->cur_cmnd = ft_check_comand(line, status);
        else if (line[0] == '#')
            continue ;
        else
            ft_check_status(status, ft_get_input(line, node));
    }
    if (!(line) || line[0] == '\0')
        error_mngr(2);
//    printf("%d\n", ant_num);
    return (1);
}

int     main(void)
{
    t_status    *status;
    t_node      *node;
    char        *line;

    line = NULL;
//    node = NULL;
    status = (t_status *)malloc(sizeof(t_status));
    *status = (t_status){0, 0, 0, 0, 0};
    node = (t_node *)malloc(sizeof(t_node));
    *node = (t_node){NULL, 0, 0, NULL, NULL};
    if (ft_validator(status, node, line))
        printf("Good\n");
//    int     ant_num;
//    char *line;
//    t_map   *

//    while (get_next_line(0, &line))
//        printf("%s\n", line);
    return (0);
}
