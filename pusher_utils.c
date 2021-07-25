/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laclide <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 16:04:37 by laclide           #+#    #+#             */
/*   Updated: 2021/07/03 17:22:37 by laclide          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_break(t_push *stc, t_sort *prec)
{
	if ((prec->pos_sort > stc->first_a->pos_sort && (stc->first_b->pos_sort
				< stc->first_a->pos_sort)) || (stc->first_a->nbr > stc->e_max_b
			&& prec->nbr == stc->e_min_b) || (stc->first_a->nbr < stc->e_min_b
			&& prec->nbr == stc->e_min_b) || (stc->first_a->nbr > stc->e_max_b
			&& stc->first_b->nbr == stc->e_max_b))
		return (1);
	return (0);
}

int	init_target_two(t_push *stc, t_sort *target)
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
	return (0);
}

int	init_target(t_push *stc, t_sort *target)
{
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
		init_target_two(stc, target);
	return (0);
}
