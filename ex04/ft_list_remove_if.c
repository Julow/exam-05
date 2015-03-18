/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/18 09:58:49 by exam              #+#    #+#             */
/*   Updated: 2015/03/18 10:13:21 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

void	remove_if_begin(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list			*tmp;

	while (*begin_list != NULL)
	{
		if (cmp((*begin_list)->data, data_ref) != 0)
			break ;
		tmp = (*begin_list)->next;
		free(*begin_list);
		*begin_list = tmp;
	}
}

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list			*tmp;
	t_list			*free_tmp;
	t_list			*prev;

	remove_if_begin(begin_list, data_ref, cmp);
	tmp = (*begin_list)->next;
	prev = tmp;
	while (tmp != NULL)
	{
		if (cmp(tmp->data, data_ref) == 0)
		{
			prev->next = tmp->next;
			free_tmp = tmp;
			tmp = tmp->next;
			free(free_tmp);
		}
		else
		{
			prev = tmp;
			tmp = tmp->next;
		}
	}
}
