/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pusher.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laclide <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 17:14:30 by laclide           #+#    #+#             */
/*   Updated: 2021/07/04 18:03:50 by laclide          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_both_second_path(t_push *stc, t_sort *start)
{
	int	i;
	int	j;
	t_sort *target_i;
	t_sort *target_j;

	i = stc->first_a->ra;
	j = stc->first_a->rrb;
	stc->first_a = start;
	target_i = stc->first_a;
	target_j = stc->first_b;
	while (i > 0)
	{
		target_i =  rotate(stc, target_i);
		write(1, "ra\n", 3);
		i--;
	}
	while (j > 0)
	{
		target_j = revers_rotate(stc, target_j);
		write(1, "rrb\n", 4);
		j--;
	}
	push(stc, stc->first_a);
	write(1, "pa\n", 3);
}

void	push_both(t_push *stc, t_sort *start)
{
	int	i;
	int	j;
	t_sort *target_i;
	t_sort *target_j;

	i = stc->first_a->rb;
	j = stc->first_a->rra;
	stc->first_a = start;
	target_i = stc->first_b;
	target_j = stc->first_a;
	while (i > 0)
	{
		target_i =  rotate(stc, target_i);
			write(1, "rb\n", 3);
			i--;
	}
	while (j > 0)
	{
		target_j = revers_rotate(stc, target_j);
				write(1, "rra\n", 4);
			j--;
	}
	push(stc, stc->first_a);
	write(1, "pa\n", 3);
}

void	push_r(t_push *stc, t_sort *start, int a, int b)
{
	stc->first_a = start;
	while (a > 0 && b > 0)
	{
		rotate(stc, stc->first_a);
		rotate(stc, stc->first_b);
		write(1, "rr\n", 3);
		a--;
		b--;
	}
	while (a > 0)
	{
		rotate(stc, stc->first_a);
		write(1, "ra\n", 3);
		a--;
	}
	while (b > 0)
	{
		rotate(stc, stc->first_b);
		write(1, "rb\n", 3);
		b--;
	}
	push(stc, stc->first_a);
	write(1, "pa\n", 3);
}

void	push_rr(t_push *stc, t_sort *start, int a, int b)
{
	stc->first_a = start;
	while (a > 0 && b > 0)
	{
		revers_rotate(stc, stc->first_a);
		revers_rotate(stc, stc->first_b);
		write(1, "rrr\n", 4);
		a--;
		b--;
	}
	while (a > 0)
	{
		revers_rotate(stc, stc->first_a);
		write(1, "rra\n", 4);
		a--;
	}
	while (b > 0)
	{
		revers_rotate(stc, stc->first_b);
		write(1, "rrb\n", 4);
		b--;
	}
	push(stc, stc->first_a);
	write(1, "pa\n", 3);
}

void	push_the_nbr(int nbr_to_move, t_push *stc)
{
	t_sort *start;

	start = stc->first_a;
	while (stc->first_a->pos_sort != nbr_to_move)
		stc->first_a = stc->first_a->next;
	if (stc->first_a->r == -1)
	{
		if (stc->first_a->ra + stc->first_a->rrb > stc->first_a->rb + stc->first_a->rra)
			push_both(stc, start);
		else
			push_both_second_path(stc, start);
	}
	else if (stc->first_a->r == 0)
		push_rr(stc, start, stc->first_a->rra, stc->first_a->rrb);
	else if (stc->first_a->r == 1)
		push_r(stc, start, stc->first_a->ra, stc->first_a->rb);
}

