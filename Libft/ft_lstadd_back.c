/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 20:05:28 by gdelta            #+#    #+#             */
/*   Updated: 2020/12/03 23:12:06 by gdelta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list		*start;

	if (lst && new)
	{
		start = (*lst);
		if (start != NULL)
		{
			while (start->next)
				start = start->next;
			start->next = new;
		}
		else
			(*lst) = new;
	}
}