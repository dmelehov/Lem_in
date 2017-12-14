/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelehov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/17 21:03:00 by dmelehov          #+#    #+#             */
/*   Updated: 2016/12/18 20:32:48 by dmelehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void	const *content, size_t content_size)
{
	t_list	*new;
	char	*s;
	char	*d;
	size_t	i;

	i = content_size;
	s = (char *)content;
	if (!(new = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if (content == NULL)
	{
		new->content = (void *)NULL;
		new->content_size = 0;
	}
	else
	{
		if (!(new->content = (t_list *)malloc(content_size)))
			return (NULL);
		d = new->content;
		while (i-- > 0)
			*d++ = *s++;
		new->content_size = content_size;
	}
	new->next = NULL;
	return (new);
}
