/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlely <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 13:07:53 by hlely             #+#    #+#             */
/*   Updated: 2017/11/25 21:14:21 by hlely            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_list_size(t_list *begin_list)
{
	int i;

	if (begin_list == NULL)
		return (0);
	i = 0;
	while (begin_list)
	{
		begin_list = begin_list->next;
		i++;
	}
	return (i);
}

void	ft_swap_data(t_list *curr, t_list *next)
{
	t_list *temp;

	temp = curr->content;
	curr->content = next->content;
	next->content = temp;
}

void	ft_list_sort(t_list **begin_list, int (*cmp)())
{
	t_list	*curr;
	t_list	*next;
	int		length;
	int		i;

	i = 0;
	length = ft_list_size(*begin_list);
	while (i < length)
	{
		curr = *begin_list;
		next = curr->next;
		while (next != NULL)
		{
			if (cmp(curr->content, next->content) > 0)
				ft_swap_data(curr, next);
			curr = next;
			next = curr->next;
		}
		i++;
	}
}
