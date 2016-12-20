/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slitim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 22:23:14 by slitim            #+#    #+#             */
/*   Updated: 2016/11/20 18:26:42 by slitim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list		*list;

	if (!(list = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	list->next = NULL;
	if (content == NULL)
	{
		list->content = NULL;
		content_size = 0;
		return (list);
	}
	if (!(list->content = ft_memalloc(content_size)))
		return (NULL);
	list->content_size = content_size;
	list->content = ft_memcpy(list->content, content, content_size);
	return (list);
}
