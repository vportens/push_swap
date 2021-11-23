/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laclide <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 18:22:05 by laclide           #+#    #+#             */
/*   Updated: 2021/07/02 16:01:40 by laclide          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lst_deep(t_sort *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}

int	ft_lst_first(int nbr, t_push *stc)
{
	t_sort	*new;

	new = malloc(sizeof(t_sort));
	if (new == NULL)
		return (1);
	new->nbr = nbr;
	new->next = NULL;
	stc->first_a = new;
	return (0);
}

int	ft_lst_add_back(int	nbr, t_push *stc)
{
	t_sort	*new;

	new = malloc(sizeof(t_sort));
	if (new == NULL)
		return (1);
	new->nbr = nbr;
	new->next = NULL;
	if (stc->first_a == NULL)
	{
		stc->first_a = new;
		return (0);
	}
	while (stc->first_a->next != NULL)
		stc->first_a = stc->first_a->next;
	stc->first_a->next = new;
	stc->first_a = stc->first_a->next;
	return (0);
}

t_sort	*ft_lst_last(t_push *stc)
{
	t_sort	*start;
	t_sort	*ret;

	ret = NULL;
	start = stc->first_b;
	if (stc->first_b)
	{
		while (stc->first_b->next)
			stc->first_b = stc->first_b->next;
		ret = stc->first_b;
	}
	stc->first_b = start;
	return (ret);
}
