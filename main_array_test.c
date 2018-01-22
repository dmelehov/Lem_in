/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_array_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelehov <dmelehov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 19:13:30 by dmelehov          #+#    #+#             */
/*   Updated: 2018/01/18 09:04:52 by dmelehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/includes/libft.h"

typedef struct	s_point
{
	int	x;
	int	y;
}				t_point;

bool	ft_print_point(void *data)
{
	t_point	*point;

	point = (t_point *)data;
	printf("x: %d, y: %d\n", point->x, point->y);
	return (true);
}

bool	ft_cmp(void *d1, void *d2)
{
	return (ft_memcmp(d1, d2, sizeof(t_point)));
}

/*
 * This file is a little example of the t_array structure
 */

int		main(int argc, char const** argv)
{
	t_array array;
	t_point	point;

	/*
	 * initialize array with realloc and delete pointer NULL
	 * and sizeof structure t_point
	 */
	D_ARRAY(init)(&array, NULL, NULL, sizeof(t_point));
	/*
	 * add point to array ! Check return value not as me :| !
	 */
	point.x = 1;
	point.y = 2;
	printf("Push back x: %d, y: %d\n", point.x, point.y);
	D_ARRAY(push_back)(&array, &point);
	/*
	 * Check if array is empty
	 */
	printf("Array is empty ? %d\n", D_ARRAY(empty)(&array));
	/*
	 * Get size and capacity
	 */
	printf("Capacity %zu, Size %zu\n", D_ARRAY(capacity)(&array), D_ARRAY(size)(&array));
	/*
	 * Change capacity
	*/
	D_ARRAY(resize)(&array, 10);
	printf("Capacity %zu, Size %zu\n", D_ARRAY(capacity)(&array), D_ARRAY(size)(&array));
	/*
	 * Print contents
	 */
	D_ARRAY(foreach)(&array, ft_print_point);
	/*
	 * Get first element
	 */
	ft_print_point(F_ARRAY_AT(&array, 0, t_point *));
	/*
	 * Delete this fucking point !!
	 */
	printf("Delete point\n");
	D_ARRAY(delete_if)(&array, ft_cmp, &point);
	printf("Capacity %zu, Size %zu\n", D_ARRAY(capacity)(&array), D_ARRAY(size)(&array));
	point.x = 3;
	point.y = 5;
	D_ARRAY(push_back)(&array, &point);
	point.x = 5;
	point.y = 7;
	D_ARRAY(push_back)(&array, &point);
	printf("Add two new\n");
	printf("Capacity %zu, Size %zu\n", D_ARRAY(capacity)(&array), D_ARRAY(size)(&array));
	D_ARRAY(foreach)(&array, ft_print_point);
	/*
	 * free memory used by array because we are nice !!
	 */
	D_ARRAY(destroy)(&array);
	(void)argc;
	(void)argv;
	return (0);
}
