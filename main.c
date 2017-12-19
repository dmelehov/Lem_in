#include "lemin.h"

void    ft_print_lists(t_node *node, t_status *status)
{
    t_node *lst;

    printf("There is [%d] ants\n", status->ant_num);
    while (node != NULL) {
        lst = NULL;
        printf("Room name == %s with coordinates X = %d and Y = %d\n", node->name, node->x, node->y);
        if (node->link != NULL) {
            lst = node->link;
            printf("A room is linked with this rooms:\n");
        }
//        else
//            printf("Links are empty\n");
        while (lst != NULL)
        {
            printf("%30s\n", lst->name);
            lst = lst->next;
        }
        node = node->next;
    }
}

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
        write(1, "There must be one start and one end\n", 36);
    else if (er_num == 7)
        write(1, "There must be a room after command\n", 35);
    else if (er_num == 8)
        write(1, "Wrong input sequence\n", 21);
    else if (er_num == 9)
        write(1, "Room with a current name allready exist\n", 40);
    else if (er_num == 10)
        write(1, "Wrong link input\n", 17);
    else if (er_num == 11)
        write(1, "Duplicated links\n", 17);
    else if (er_num == 12)
        write(1, "There are not linked rooms\n", 27);
    exit(0);
}

int     check_not_linked_rooms(t_node *node) {
    while (node)
    {
        if (node->link == NULL)
            return (1);
        node = node->next;
    }
    return (0);
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
        if (ft_strequ(s, node->name))
            return (node);
        node = node->next;
    }
    return (NULL);
}

int     check_delimeters(char const *s, char c)
{
    int i;
    int res;

    i = 0;
    res = 0;
    while (s[i] != '\0')
    {
        if (s[i] == c)
            res++;
        i++;
    }
    return (res);
}

void    get_links(t_node *node, char *str)
{
    t_node *lst;

    if (node->link == NULL)
    {
        node->link = (t_node *)malloc(sizeof(t_node));
        *(node->link) = (t_node){NULL, 0, 0, NULL, NULL};
        node->link->name = ft_strdup(str);
    }
    else if (!check_name(node->link, str))
    {
        lst = get_next_node(node->link);
        lst->name = ft_strdup(str);
    }
    else
        error_mngr(11);
}

t_node  *get_next_node(t_node *node)
{
    while (node->next != NULL)
        node = node->next;
    node->next = (t_node *)malloc(sizeof(t_node));
    node = node->next;
    *node = (t_node){NULL, 0, 0, NULL, NULL};
    return (node);
}

int      ft_get_ants_num(char *line, t_status *status)
{
    status->ant_num = check_num_str(line);
    if (status->ant_num <= 0)
        error_mngr(1);
    return (1);
}

int     ft_get_room_data(char **arr, t_node *node, t_status *status)
{
    if (check_name(node, arr[0]))
        error_mngr(9);
    if (node->name != NULL)
        node = get_next_node(node);
    node->name = ft_strdup(arr[0]);
    node->x = check_num_str(arr[1]);
    node->y = check_num_str(arr[2]);
    if (status->cur_cmnd == 1)
        status->start = ft_strdup(arr[0]);
    else if (status->cur_cmnd == 2)
        status->end = ft_strdup(arr[0]);
    return (3);
}

int     ft_get_links_data(char *s, t_node *node)
{
    char **arr;
    int  i;

    i = 0;
    if (check_delimeters(s, '-') != 1)
        error_mngr(10);
    arr = ft_strsplit(s, '-');
    while (arr[i])
        i++;
    if (i != 2)
        error_mngr(10);
    if (!check_name(node, arr[0]) || !check_name(node, arr[1]))
        error_mngr(10);
    get_links(check_name(node, arr[0]), arr[1]);
    get_links(check_name(node, arr[1]), arr[0]);
    return (5);
}

int     ft_get_input(char *line, t_node *node, t_status *status)
{
    char **s;
    int i;

    if (status->cur_input_type == 0)
        return (ft_get_ants_num(line, status));
    i = 0;
    s = ft_strsplit(line, 32);
    while (s[i])
        i++;
    if (i == 3 && check_delimeters(line, ' ') != 2)
        error_mngr(5);
    if (i == 3 && status->cur_input_type <= 3)
        return (ft_get_room_data(s, node, status));
    else if (i == 1 && status->cur_input_type >= 3)
        return (ft_get_links_data(s[0], node));
    else if (i != 1 && i != 3)
        error_mngr(5);
    return (0);
}

void     ft_check_status(t_status *status, int inp_type)
{
    if (status->cur_cmnd != 0 && inp_type != 3)
        error_mngr(7);
    if (status->cur_input_type > inp_type)
        error_mngr(8);
    if (inp_type == 5 && !(status->start_exist == 1 && status->end_exist == 1))
        error_mngr(6);
    status->cur_input_type = inp_type;
    status->cur_cmnd = 0;
}

int  ft_check_comand(char *line, t_status *status)
{
    if (line[1] != '#')
        return (0);
    if (ft_strequ(line + 2, "start"))
    {
        if (status->cur_cmnd != 0)
            error_mngr(8);
        if (status->start_exist++ == 0)
            return (1);
        else
            error_mngr(6);
    }
    else if (ft_strequ(line + 2, "end"))
    {
        if (status->cur_cmnd != 0)
            error_mngr(8);
        if (status->end_exist++ == 0)
            return (2);
        else
            error_mngr(6);
    }
    return (0);
}

int     ft_validator(t_status *status, t_node *node, char *line, int r)
{
    while ((r = get_next_line(0, &line)) > 0)
    {
        if (line[0] == 'L')
            error_mngr(3);
        else if (line[0] == '#')
            status->cur_cmnd = ft_check_comand(line, status);
        else
            ft_check_status(status, ft_get_input(line, node, status));
        printf("%s\n", line);
    }
    if ((status->cur_input_type != 5 && *line == '\0') || r != 0)
        error_mngr(2);
    if (check_not_linked_rooms(node))
        error_mngr(12);
    return (1);
}

/*
 * THE VALIDATOR PART ENDED HERE
 * LET THE GAME BEGIN!!!
 */

void    add_curent_visit(t_path *lst, char *str)
{
    while (lst->next)
    {
//        printf("SRAV\n");
        lst = lst->next;
    }
    lst->next = (t_path *)malloc(sizeof(t_path));
    lst = lst->next;
    *lst = (t_path){ft_strdup(str), NULL};
}

t_path      *copy_path(t_path *path)
{
    t_path *new;
    t_path *first;

    new = (t_path *)malloc(sizeof(t_path));
    *new = (t_path){ft_strdup(path->name), NULL};
    first = new;
    path = path->next;
//    new = new->next;
    while (path)
    {
        new->next = (t_path *)malloc(sizeof(t_path));
        new = new->next;
        *new = (t_path){ft_strdup(path->name), NULL};
        path = path->next;
    }
    return (first);
}

void    print_right_path(t_path *path, int i)
{
    while (path)
    {
        printf("L%s", path->name);
        if (path->next)
            printf(" - ");
        path = path->next;
    }
    printf("\nDepth == {%d}\n", i);
}

int     was_visited(t_path *path, char *s)
{
    while (path)
    {
        if (ft_strequ(path->name, s))
            return (1);
        path = path->next;
    }
    return (0);
}

int     ft_solution(t_node *node, t_node *links, t_status *status, t_path *path, int i)
{
    t_path *was_here;


    if (links == NULL)
    {
//        printf("Room is NULL\n");
        return (0);
    }

//    printf("Checking room {%s} in depth {%d}\n", links->name, i);
    if (was_visited(path, links->name))
    {
//        printf("Room was visited\n");
        ft_solution(node, links->next, status, path, i);
        return (0);
    }
    was_here = copy_path(path);
    add_curent_visit(was_here, links->name);
//    print_right_path(was_here, i);
    if (ft_strequ(links->name, status->end))
    {
        printf("The answer is :\n");
        print_right_path(was_here, i);
//        printf("Exit function with value {%d}\n", i);
//        return (i);
    }
   if (ft_solution(node, links->next, status, path, i))
        ft_solution(node, (check_name(node, links->name))->link, status, was_here, i + 1);
    return (i);
}

int     main(void)
{
    t_status    *status;
    t_node      *node;
    t_path      *path;
    char        *line;
//    char        **arr;
//    int i = 0;

    line = NULL;
//    path = NULL;
    status = (t_status *)malloc(sizeof(t_status));
    *status = (t_status){0, 0, 0, 0, 0, NULL, NULL};
    node = (t_node *)malloc(sizeof(t_node));
    *node = (t_node){NULL, 0, 0, NULL, NULL};
    path = (t_path *)malloc(sizeof(t_path));
    if (ft_validator(status, node, line, 0)) {
        ft_print_lists(node, status);
        printf("START == %s\nEND == %s\n", status->start, status->end);
        printf("Good\n");
    }
//    *path = (t_path){NULL, NULL, NULL};
    *path = (t_path){ft_strdup(status->start), NULL};
    ft_solution(node, (check_name(node, status->start))->link, status, path, 1);
    return (0);
}
