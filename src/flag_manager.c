/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelehov <dmelehov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 16:38:29 by dmelehov          #+#    #+#             */
/*   Updated: 2018/01/31 21:44:55 by dmelehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

#define RESRVED "-dpmq"

static void		display_readme(void)
{
	int		fd;
	char	*line;

	fd = open("README.md", O_RDONLY);
	line = NULL;
	if (fd < 3)
		D_ERROR(-1, "Ooops!README file is gone somewhere");
	while ((get_next_line(fd, &line) > 0))
	{
		ft_putendl_fd(line, 2);
		ft_strdel(&line);
	}
	exit(-1);
}

static void		display_usage(void)
{
	ft_putendl_fd("usage: ./lem-in [-dpmq] < [map ...]", 2);
	ft_putendl_fd("       	[-d] - debug option", 2);
	ft_putendl_fd("       	[-p] - print founded paths", 2);
	ft_putendl_fd("       	[-m] - use multiple paths", 2);
	ft_putendl_fd("       	[-q] - quiet mode", 2);
	ft_putendl_fd("       	[--help] for more info", 2);
	exit(-1);
}

static void		check_flag_corecktness(char *s)
{
	int		i;
	char	*c;
	int		minus;

	i = 0;
	minus = 0;
	if (s[i] != '-')
		display_usage();
	if (ft_strequ(s, "--help"))
		display_readme();
	while (s[i])
	{
		if ((c = ft_strchr(RESRVED, s[i])))
		{
			if (*c == '-')
				minus++;
			i++;
		}
		else
			display_usage();
	}
	if (minus != 1)
		display_usage();
}

void			flag_seter(t_status *status, int ac, char *s)
{
	size_t	i;

	i = 0;
	if (ac > 2)
		display_usage();
	else if (ac == 2)
	{
		check_flag_corecktness(s);
		while (s[i])
		{
			if (s[i] == 'd')
				status->debug += 1;
			else if (s[i] == 'p')
				status->pr_paths += 1;
			else if (s[i] == 'm')
				status->pr_mult += 1;
			else if (s[i] == 'q')
				status->quiet += 1;
			i++;
		}
		if (status->debug > 1 || status->pr_mult > 1 || status->pr_paths > 1)
			display_usage();
	}
	ft_strdel(&s);
}

#undef RESRVED
