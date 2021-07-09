/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonction.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laclide <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 00:37:02 by laclide           #+#    #+#             */
/*   Updated: 2021/07/06 12:25:51 by laclide          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_push	*stc, int list)
{
	t_sort	*tmp;
	t_sort	*first;
	t_sort	*to_go;

	if (list == 1)
		to_go = stc->first_a;
	else
		to_go = stc->first_b;
	if (to_go == NULL || to_go->next == NULL)
		return ;
	first = to_go->next;
	tmp = first->next;
	to_go->next = tmp;
	first->next = to_go;
	if (list == 1)
		stc->first_a = first;
	if (list == 2)
		stc->first_b = first;
	return ;
}

int	actual_size(t_push *stc, t_sort *target)
{
	int		i;
	t_sort	*start;

	start = target;
	i = 0;
	while (target)
	{
		i++;
		target = target->next;
	}
	target = start;
	return (i);
}

void	push(t_push *stc, t_sort *target)
{
	int		i;
	t_sort	*a;
	t_sort	*b;

	a = stc->first_a;
	b = stc->first_b;
	i = 0;
	if (target == NULL)
		return ;
	check_max_min(stc, target);
	stc->actual_size_a = actual_size(stc, stc->first_a);
	stc->actual_size_b = actual_size(stc, stc->first_b);
	str = ft_itoa(stc->actual_size_a);
	if (target == stc->first_a)
	{
		stc->first_a = stc->first_a->next;
		target->next = stc->first_b;
		stc->first_b = target;
		stc->actual_size_a--;
		stc->actual_size_b++;
		if (stc->actual_size_a == 0)
			stc->first_a = NULL;
		if (stc->actual_size_a == 1)
			stc->first_a->next = NULL;
		if (stc->actual_size_b == 1)
			stc->first_b->next = NULL;
	}
	else
	{	
		stc->first_b = target->next;
		target->next = stc->first_a;
		stc->first_a = target;
		stc->actual_size_b--;
		stc->actual_size_a++;
		if (stc->actual_size_b == 0)
			stc->first_b = NULL;
		if (stc->actual_size_b == 1)
			stc->first_b->next = NULL;
		if (stc->actual_size_a == 1)
			stc->first_a->next = NULL;
	}
}

t_sort	*rotate(t_push *stc, t_sort *target)
{
	t_sort	*obj;
	t_sort	*first;
	int		i;

	i = 0;
	if (target->next == NULL)
		return (NULL);
	if (target == stc->first_a)
		i = 1;
	obj = target;
	first = target->next;
	while (target->next)
		target = target->next;
	target->next = obj;
	obj->next = NULL;
	if (i == 1)
		return (stc->first_a = first);
	else
		return (stc->first_b = first);
}

t_sort	*revers_rotate(t_push *stc, t_sort *target)
{
	t_sort	*first;
	t_sort	*obj;
	t_sort	*prec;
	int		i;

	i = 0;
	if (target->next == NULL)
		return (NULL);
	if (target == stc->first_a)
		i = 1;
	first = target;
	while (target->next)
	{
		prec = target;
		target = target->next;
	}
	obj = target;
	obj->next = first;
	prec->next = NULL;
	if (i == 1)
		stc->first_a = obj;
	else
		stc->first_b = obj;
	return (obj);
}
