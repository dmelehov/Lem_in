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

void    add_curent_visit(t_path *lst, char *str, char *str2)
{
    while (lst->next)
        lst = lst->next;
    lst->next = (t_path *)malloc(sizeof(t_path));
    lst = lst->next;
    *lst = (t_path){ft_strdup(str), ft_strdup(str2), NULL, NULL};
}

t_path      *copy_path(t_path *path)
{
    t_path *new;
    t_path *first;

    new = (t_path *)malloc(sizeof(t_path));
    *new = (t_path){ft_strdup(path->name), NULL, NULL, NULL};
    first = new;
    path = path->next;
//    new = new->next;
    while (path)
    {
        new->next = (t_path *)malloc(sizeof(t_path));
        new = new->next;
        *new = (t_path){ft_strdup(path->name), NULL, NULL, NULL};
        path = path->next;
    }
    return (first);
}

void    print_right_path(t_path *path)
{
    while (path)
    {
        printf("L%s", path->name);
        printf("{%s}", path->from);
        if (path->next)
            printf(" - ");
        path = path->next;
    }
    printf("\n");
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

void    print_answer(t_path *path, char *str)
{
    t_path *lst;

    lst = path;
//    print_right_path(lst);
//    printf("[%s]\n", str);
//    printf("SRAV\n");
    while (str && lst)
    {
//        printf("SRAV2\n");
        if (ft_strequ(str, lst->name))
        {
//            printf("SRAV3\n");
            print_answer(path, lst->from);
            printf("L%s - ", lst->name);
        }
        lst = lst->next;
    }
}

//char    *the_last_of(t_path *path)
//{
//    while (path->next)
//        path = path->next;
//    return (path->name);
//}


//int     ft_solution(t_node *node, t_node *links, t_status *status, t_path *path, int i)
//{
//    if (links == NULL)
//        return (0);
//    ft_solution(node, links->next, status, path, i);
////    if (was_visited(path, links->name))
////        return (0);
//    if (ft_strequ(links->name, status->end))
//    {
//        printf("The ANSWER is :  ");
//        print_answer(path, the_last_of(path));
//        printf("L%s\n", links->name);
////        print_right_path(path, i);
////        printf("Exit function with value {%d}\n", i);
//        return (i);
//    }
//    return (0);
//}

int     add_right_path(t_status *status, t_path *was_here)
{
    t_path *lst;

    lst = status->ans;
//    printf("SRAV\n");
//    print_right_path(was_here);
//    printf()
    if (status->ans == NULL)
    {
        status->ans = was_here;
        return (0);
    }
    while (lst->ways)
        lst = lst->ways;
    lst->ways = was_here;
//    print_right_path(ans);
    return (1);
}

t_path     *ft_solution(t_node *node, t_node *links, t_status *status, t_path *path)
{
    t_path *was_here;

    if (links == NULL)
        return (NULL);
    ft_solution(node, links->next, status, path);
//    printf("Checking room {%s}\n", links->name);
    if (was_visited(path, links->name))
        return (NULL);
    was_here = copy_path(path);
    add_curent_visit(was_here, links->name, links->name);
//    print_right_path(was_here);
    if (ft_strequ(links->name, status->end))
    {
//        printf("The ANSWER is :  ");
        add_right_path(status, was_here);
//        print_right_path(was_here);
//        printf("Exit function with value {%d}\n", i);
        return (NULL);
    }
    ft_solution(node, (check_name(node, links->name))->link, status, was_here);
    return (NULL);
}

//t_path      *queue_mngr(t_path *queue)
//{
//    t_path *lst;
//
//    lst = queue->next;
//    ft_strdel(&(queue->name));
//    ft_strdel(&(queue->from));
//    ft_memdel((void **)(&queue));
//    return (lst);
//}

//void        go_v_shir(t_node *node, t_status *status)
//{
//    t_node *links;
//    t_node *lst;
//    t_path  *queue;
//    t_path  *visited;
////    int i;
//
////    i = 0;
//    queue = (t_path *)malloc(sizeof(t_path));
//    visited = (t_path *)malloc(sizeof(t_path));
//    *visited = (t_path){ft_strdup(status->start), NULL, NULL};
//    *queue = (t_path){ft_strdup(status->start), NULL, NULL};
//    while (queue)
//    {
////        if (ft_strequ(queue->name, status->start))
////            queue = queue_mngr(queue);
//        printf("Checking room {%s}\n", queue->name);
////        printf("The QUEUE == ");
////        print_right_path(queue);
////        printf("The VISITED == ");
////        print_right_path(visited);
//        links = (check_name(node, queue->name)->link);
//        if (!ft_strequ(queue->name, status->end))
//            ft_solution(node, links, status, visited, 1);
//        lst = links;
//        while (lst)
//        {
//            if (!was_visited(visited, lst->name) && !was_visited(queue, lst->name)
//                && !ft_strequ(lst->name, status->end))
//                add_curent_visit(queue, lst->name, queue->name);
//            lst = lst->next;
//        }
//        queue = queue_mngr(queue);
//        if (queue && !was_visited(visited, queue->name))
//            add_curent_visit(visited, queue->name, queue->from);
//    }
//}

//int    ft_solution2(t_node *node, t_node *links, t_status *status, t_path *path)
//{
//    t_path *was_here;
//
//    if (links == NULL)
//        return (0);
//
//    ft_solution2(node, links->next, status, path);
//    if (was_visited(path, links->name))
//    {
////        printf("Room {%s} was visited\n", links->name);
////        ft_solution(node, links->next, status, path, i);
//        return (0);
//    }
//    was_here = copy_path(path);
//    add_curent_visit(was_here, links->name, links->name);
//    if (ft_strequ(links->name, status->end))
//    {
//        printf("The ANSWER is :  ");
//        print_right_path(was_here);
//        return (1);
//    }
//    ft_solution2(node, (check_name(node, links->name))->link, status, was_here);
//    return (0);
//}

int     get_links_num(t_node *node, char *str)
{
    int i;
    t_node *lst;

    i = 0;
    lst = (check_name(node, str))->link;
    while (lst)
    {
        lst = lst->next;
        i++;
    }
    return (i);
}

int     get_path_length(t_path *lst)
{
    int i;

    i = 0;
    while (lst)
    {
        lst = lst->next;
        i++;
    }
    return (i);
}

//t_path  *find_shortest(t_path * lst)
//{
//    int len;
//    int cur;
//    t_path *shortest;
//
//    cur = get_path_length(lst);
//    while(lst)
//    {
//        len = get_path_length(lst);
//        if (len < cur)
//        {
//            cur = len;
//            shortest = lst;
//        }
//        lst = lst->ways;
//    }
//    return (shortest);
//}

int     path_is_unique(t_path * lst, t_path *cmpr)
{
    if (cmpr == NULL)
        return (1);
    cmpr = cmpr->next;
    lst = lst->next;

    while (lst->next)
    {
        if (was_visited(cmpr, lst->name))
            return (0);
        lst = lst->next;
    }
    return (1);
}

t_path  *find_another_shortest(t_path * lst, t_path *cmpr)
{
    int len;
    int cur;
    t_path *shortest;

    cur = 666;
    shortest = NULL;
    while(lst)
    {
        if (cmpr == NULL || path_is_unique(lst, cmpr))
        {
            len = get_path_length(lst);
            if (len < cur)
            {
                cur = len;
                shortest = lst;
            }
        }
        lst = lst->ways;
    }
    return (copy_path(shortest));
}

void    get_unique_paths(t_status *status, int max_start, int max_end)
{
    int max_path;
    t_path *shortest;
    t_path *lst;

    max_path = (max_start >= max_end ? max_end : max_start);
    printf("{%d} | {%d} | {%d}\n", max_start, max_end, max_path);
    lst = status->ans;
    status->ans = NULL;
    shortest = NULL;
    while(max_path--)
    {
        add_right_path(status, find_another_shortest(lst, shortest));
        shortest = status->ans;
    }
}

t_path  *create_ants_list(int num, char *s)
{
    t_path *ants;
    t_path *lst;
    int i;

    i = 1;
    printf("The ants list is:   ");
    ants = (t_path *)malloc(sizeof(t_path));
    *ants = (t_path){ft_itoa(i++), ft_strdup(s), NULL, NULL};
    lst = ants;
    num -= 1;
    while (num--)
    {
//        printf("SRAV\n");
        ants->next = (t_path *)malloc(sizeof(t_path));
//        if (i == 1)
//            lst = ants;
        ants = ants->next;
        *ants = (t_path){ft_itoa(i), ft_strdup(s), NULL, NULL};
//        printf("{%s}\n", ants->name);
//        printf("adrs == %p | %p\n", ants, lst);

//        printf("adrs2 == %p | %p\n", ants, lst);

        i++;
    }
    return (lst);
}

t_path     *they_are_all_there(t_path *ants, char *s)
{
    while (ants)
    {
        if (ft_strequ(ants->from, s))
            ants = ants->next;
        else
            return (ants);
    }
    return (NULL);
}

t_path    *find_current(t_path *lst, char *s)
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

void    set_ant_move(t_path *lst, t_path *curnt, char *end)
{
    t_path *cur;

    cur = find_current(lst, curnt->name);
    if (cur->next && cur->next->from == NULL) {
        cur->from = NULL;
        if (!ft_strequ(cur->next->name, end))
            cur->next->from = curnt->name;
        curnt->from = cur->next->name;
        printf("L%s-%s ", curnt->name, curnt->from);
    }
    else if (lst->ways && cur->next && cur->next->from != NULL)
        set_ant_move(lst->ways, curnt, end);
}

void    print_final_output(t_status *status)
{
    t_path *ants;
    t_path *curnt;
    t_path *lst;
//    t_path *lst2;

    ants = create_ants_list(status->ant_num, status->start);
    print_right_path(ants);

//    lst = status->ans;
    while (they_are_all_there(ants, status->end))
    {
//        printf("SRAV\n");
        lst = status->ans;
        curnt = ants;
//        curnt = they_are_all_there(ants, status->end);
        while (curnt)
        {
            if (!ft_strequ(curnt->from, status->end))
                set_ant_move(lst, curnt, status->end);
            curnt = curnt->next;
        }
        printf("\n");
    }
}

int     main(void)
{
    t_status    *status;
    t_node      *node;
    t_path      *path;
    t_path      *lst;
    char        *line;

    line = NULL;
//    ans = NULL;
    status = (t_status *)malloc(sizeof(t_status));
    *status = (t_status){0, 0, 0, 0, 0, NULL, NULL, NULL};
    node = (t_node *)malloc(sizeof(t_node));
    *node = (t_node){NULL, 0, 0, NULL, NULL};
    if (ft_validator(status, node, line, 0)) {
        ft_print_lists(node, status);
        printf("START == %s\nEND == %s\n", status->start, status->end);
        printf("Good\n");
    }
//    go_v_shir(node, status);
    path = (t_path *)malloc(sizeof(t_path));
//    ans = (t_path *)malloc(sizeof(t_path));
    *path = (t_path){ft_strdup(status->start), NULL, NULL, NULL};
    ft_solution(node, (check_name(node, status->start))->link, status, path);
//    ft_solution2(node, (check_name(node, status->start))->link, status, path);
    lst = status->ans;
    while (lst)
    {
//        printf("SRAV\n");
        print_right_path(lst);
        lst = lst->ways;
    }
    status->node = node;
    get_unique_paths(status, get_links_num(node, status->start),  get_links_num(node, status->end));
    lst = status->ans;
    while (lst)
    {
        print_right_path(lst);
        lst = lst->ways;
    }
    print_final_output(status);
    return (0);
}
