/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laclide <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 14:43:06 by laclide           #+#    #+#             */
/*   Updated: 2021/07/06 12:15:36 by laclide          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	found_good_place(t_push *lst)
{
	t_sort	*prec;
	t_sort	*start;
	int		i;

	i = 0;
	prec = NULL;
	start = lst->first_a;
	while (lst->first_a->next)
		lst->first_a = lst->first_a->next;
	prec = lst->first_a;
	lst->first_a = start;
	while (lst->first_a)
	{
		if ((prec->nbr < lst->first_b->nbr && lst->first_a->nbr
				> lst->first_b->nbr) || (prec->nbr == lst->e_max_a
				&& (lst->first_b->nbr < lst->e_min_a || lst->first_b->nbr
					> lst->e_max_a)))
			break ;
		i++;
		prec = lst->first_a;
		lst->first_a = lst->first_a->next;
	}
	lst->first_a = start;
	return (i);
}

void	sort_tri_list(t_push *lst)
{
	while (list_sort(lst) != 1)
	{
		if (lst->first_a->next->nbr == lst->e_min_a
			&& lst->first_a->nbr == lst->e_max_a)
		{
			write(1, "ra\n", 3);
			rotate(lst, lst->first_a);
		}
		else if (lst->first_a->next->nbr == lst->e_max_a
			&& lst->first_a->nbr != lst->e_min_a)
		{
			revers_rotate(lst, lst->first_a);
			write(1, "rra\n", 4);
		}
		else
		{
			swap(lst, 1);
			write(1, "sa\n", 3);
		}
	}
}

void	sort_em_all(t_push *lst)
{
	int	i;

	if (lst->actual_size_a > 3)
	{
		while (lst->actual_size_a > 3)
		{
			push(lst, lst->first_a);
			write(1, "pb\n", 3);
		}
	}
	sort_tri_list(lst);
	while (lst->first_b != NULL)
		insert_ele_in_lst(lst);
	i = found_e_min(lst);
	witch_side_rotate(lst, i);
}
