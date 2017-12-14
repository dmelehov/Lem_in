/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_colors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelehov <dmelehov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 16:07:26 by dmelehov          #+#    #+#             */
/*   Updated: 2017/05/18 20:14:25 by dmelehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** создание массива наименований цветов
*/

char	**ft_match_color(void)
{
	char **colors;

	colors = (char **)malloc(sizeof(char *) * 17);
	colors[0] = ft_strdup("{red}");
	colors[1] = ft_strdup("{green}");
	colors[2] = ft_strdup("{yellow}");
	colors[3] = ft_strdup("{blue}");
	colors[4] = ft_strdup("{magenta}");
	colors[5] = ft_strdup("{cyan}");
	colors[6] = ft_strdup("{white}");
	colors[7] = ft_strdup("{black}");
	colors[8] = ft_strdup("{red|b}");
	colors[9] = ft_strdup("{green|b}");
	colors[10] = ft_strdup("{yellow|b}");
	colors[11] = ft_strdup("{blue|b}");
	colors[12] = ft_strdup("{magenta|b}");
	colors[13] = ft_strdup("{cyan|b}");
	colors[14] = ft_strdup("{white|b}");
	colors[15] = ft_strdup("{black|b}");
	colors[16] = ft_strdup("{eoc}");
	colors[17] = NULL;
	return (colors);
}

/*
** создание массива кода цветов
*/

char	**ft_get_color(void)
{
	char **colval;

	colval = (char **)malloc(sizeof(char *) * 17);
	colval[0] = ft_strdup("\x1b[31m");
	colval[1] = ft_strdup("\x1b[32m");
	colval[2] = ft_strdup("\x1b[33m");
	colval[3] = ft_strdup("\x1b[34m");
	colval[4] = ft_strdup("\x1b[35m");
	colval[5] = ft_strdup("\x1b[36m");
	colval[6] = ft_strdup("\x1b[37m");
	colval[7] = ft_strdup("\x1b[30m");
	colval[8] = ft_strdup("\x1b[41m");
	colval[9] = ft_strdup("\x1b[42m");
	colval[10] = ft_strdup("\x1b[43m");
	colval[11] = ft_strdup("\x1b[44m");
	colval[12] = ft_strdup("\x1b[45m");
	colval[13] = ft_strdup("\x1b[46m");
	colval[14] = ft_strdup("\x1b[47m");
	colval[15] = ft_strdup("\x1b[40m");
	colval[16] = ft_strdup("\x1b[0m");
	colval[17] = NULL;
	return (colval);
}

/*
** проверка наличия цвета и его применение
*/

int		ft_check_color(char *format, char **s, int *ans)
{
	char	**colors;
	char	**colval;
	int		i;
	int		j;

	i = 0;
	j = 0;
	colors = ft_match_color();
	while (colors[i])
	{
		if (ft_str_isin(format, colors[i]))
		{
			colval = ft_get_color();
			while (colval[i][j])
				(*s)[(*ans)++] = colval[i][j++];
			ft_free_2d_arr(colval);
			free(colval);
			return (ft_strlen(colors[i]));
		}
		i++;
	}
	ft_free_2d_arr(colors);
	free(colors);
	return (0);
}

void	ft_free_struct(t_argdata *data)
{
	ft_strdel(&(data->form_input));
	ft_memdel((void **)&data);
}
