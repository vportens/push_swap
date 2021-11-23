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

int	found_the_best_move(t_push *stc, int part)
{
	int		min_move;
	int		nbr_to_move;
	t_sort	*first_a;

	first_a = stc->first_a;
	if (stc->first_b)
		min_move = -1;
	while (stc->first_a)
	{
		if (stc->first_a->pos_sort < stc->nbr_per_part * (part + 1))
		{
			if (stc->first_a->nbr_move < min_move || min_move == -1)
			{
				min_move = stc->first_a->nbr_move;
				nbr_to_move = stc->first_a->pos_sort;
			}
		}
		if (stc->first_a)
			stc->first_a = stc->first_a->next;
	}
	stc->first_a = first_a;
	return (nbr_to_move);
}

int	best_nbr_move(t_push *stc)
{
	int	res_r;
	int	res_rr;
	int	res_both;

	if (stc->first_a->ra > stc->first_a->rb)
		res_r = stc->first_a->ra;
	else
		res_r = stc->first_a->rb;
	if (stc->first_a->rra > stc->first_a->rrb)
		res_rr = stc->first_a->rra;
	else
		res_rr = stc->first_a->rrb;
	if (stc->first_a->ra + stc->first_a->rrb > stc->first_a->rra
		+ stc->first_a->rb)
		res_both = stc->first_a->rra + stc->first_a->rb;
	else
		res_both = stc->first_a->ra + stc->first_a->rrb;
	if (res_r >= res_rr && res_rr <= res_both)
		stc->first_a->r = 0;
	if (res_rr >= res_r && res_r <= res_both)
		stc->first_a->r = 1;
	if (res_both <= res_r && res_both <= res_rr)
		stc->first_a->r = -1;
	return (fucking_norme(stc->first_a->r, res_r, res_rr, res_both));
}

void	fill_inf_move(t_push *stc, int index)
{
	int		j;
	t_sort	*first_b;
	t_sort	*prec;

	prec = NULL;
	first_b = stc->first_b;
	stc->first_a->ra = index;
	stc->first_a->rra = stc->actual_size_a - index;
	j = 0;
	if (prec == NULL)
		prec = ft_lst_last(stc);
	while (stc->first_b)
	{
		if (is_break(stc, prec) == 1)
			break ;
		prec = stc->first_b;
		stc->first_b = stc->first_b->next;
		j++;
	}
	stc->first_a->rb = j;
	stc->first_a->rrb = stc->actual_size_b - j;
	stc->first_a->nbr_move = best_nbr_move(stc);
	stc->first_b = first_b;
}

void	sort_part(t_push *stc, int part)
{
	int		j;
	t_sort	*first_a;
	int		nbr;

	j = 0;
	first_a = stc->first_a;
	while (stc->first_a)
	{
		if (stc->first_a->pos_sort < stc->nbr_per_part * (part + 1))
			fill_inf_move(stc, j);
		if (stc->first_a)
			stc->first_a = stc->first_a->next;
		j++;
	}
	stc->first_a = first_a;
	if (stc->first_b == NULL)
	{
		push(stc, stc->first_a);
		write(1, "pb\n", 3);
		return ;
	}
	nbr = found_the_best_move(stc, part);
	push_the_nbr(nbr, stc);
}

void	solver_push_swap(t_push *stc)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (i < stc->max_lst / stc->nbr_per_part)
	{
		while (j < stc->nbr_per_part)
		{
			sort_part(stc, i);
			j++;
		}
		i++;
		j = 0;
	}
	while (j < stc->max_lst % stc->nbr_per_part)
	{
		sort_part(stc, i);
		j++;
	}
	put_big_one_to_the_top(stc);
	send_lst(stc);
	if (list_sort(stc) == 0)
		write(1, "ERROR\n", 6);
}
