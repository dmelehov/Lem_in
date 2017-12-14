#include "lemin.h"

void    error_mngr(int er_num)
{
    write(1, "ERROR\n", 6);
    if (er_num == 1)
        write(1, "The number of ants should be a positive number without whitespaces\n", 67);
    if (er_num == 2)
        write(1, "Incorrect input, line break\n", 28);
    exit(0);
}

int     check_ant_num(char *line)
{
    int i;
    int res;

    i = 0;
    res = 0;
    while (line[i])
    {
        if (ft_isdigit(line[i]))
            i++;
        else
            error_mngr(1);
    }
    res = ft_atoi(line);
    if (res <= 0)
        error_mngr(1);
    return (res);
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
//    ant_num = check_ant_num(line);
//    node = (t_node *)malloc(ant_num * sizeof(t_node));
    while (get_next_line(0, &line) > 0 && line[0] != '\0')
    {

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
