/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max_min_lst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laclide <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 14:15:59 by laclide           #+#    #+#             */
/*   Updated: 2021/07/03 14:16:33 by laclide          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	update_max_min_lst_b(t_push *stc, t_sort *target)
{
	t_sort	*start;

	start = target;
	while (target)
	{
		if (target->nbr < stc->e_min_b)
			stc->e_min_b = target->nbr;	
		if (target->nbr > stc->e_max_b)
			stc->e_max_b = target->nbr;	
		target = target->next;
	}
	target = start;
}

void	update_max_min_lst(t_push *stc, t_sort *target)
{
	t_sort	*start;

	if (target == stc->first_a)
	{
	start = target;
	while (target)
	{
			if (target->nbr < stc->e_min_a)
				stc->e_min_a = target->nbr;	
			if (target->nbr > stc->e_max_a)
				stc->e_max_a = target->nbr;	
		target = target->next;
	}
	target = start;
	}
	else if (target == stc->first_b)
		update_max_min_lst_b(stc, target);
}

int	check_max_min_b(t_push *stc, t_sort *target)
{
		if (stc->first_a == NULL)
		{
			stc->e_min_a = target->nbr;
			stc->e_max_a = target->nbr;
		}
		if (target->nbr < stc->e_min_a)
			stc->e_min_a = target->nbr;
		if (target->nbr > stc->e_max_a)
			stc->e_max_a = target->nbr;
		if (target->nbr == stc->e_min_b || target->nbr == stc->e_min_b)
			return (1);
		return (0);
}

int	check_max_min(t_push *stc, t_sort *target)
{
	if (target == stc->first_a)
	{
		if (stc->first_b == NULL)
		{
			stc->e_min_b = target->nbr;
			stc->e_max_b = target->nbr;
		}
		if (target->nbr < stc->e_min_b)
			stc->e_min_b = target->nbr;
		if (target->nbr > stc->e_max_b)
			stc->e_max_b = target->nbr;
		if (target->nbr == stc->e_min_a || target->nbr == stc->e_max_a)
			return (1);

		return (0);
	}
	if (target == stc->first_b)
	{
		return (check_max_min_b(stc, target));
	}
	return (0);
}

