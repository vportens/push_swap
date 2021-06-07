/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_em_all.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal--ce <edal--ce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 13:00:17 by laclide           #+#    #+#             */
/*   Updated: 2021/06/04 20:30:00 by laclide          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_lst_sort(t_lst *a)
{
	int	i;

	i = 0;
	while (i < a->actual_size - 1)
	{
		if (a->lst[i] > a->lst[i + 1])
			return (1);
		i++;
	}
	return (0);
}

int 	found_good_place(int *j, int i, t_lst *a, t_lst *b)
{	
	if (a->lst[i] < b->lst[0])
		i++;
	else
	{
		(*j) = a->actual_size;
		return (i);
	}
	if (i == a->actual_size)
		i = 0;
	(*j)++;
	return (i);
}

void	insert_ele_in_lst(t_lst *a, t_lst *b, int i, int j)
{
	while (a->lst[i] != a->e_min)
		i++;
	while (j < a->actual_size)
		i = found_good_place(&j, i, a, b);
	if (i > a->actual_size / 2)
	{
		while (i != 0)
		{
			revers_rotate(a, 1);
			i++;
			i = i % a->actual_size;
		}
	}
	else
	{
		while (i != 0)
		{
			rotate(a, 1);
			i--;
		}
	}
	push(b, a);
	write(1, "pa\n", 3);
}

void	sort_tri_list(t_lst *a)
{
	while (is_lst_sort(a) != 0)
	{
		if (a->lst[1] == a->e_min && a->lst[0] == a->e_max)
		{
			rotate(a, 1);
		}
		else if (a->lst[1] == a->e_max && a->lst[0] != a->e_min)
		{
			revers_rotate(a, 1);
		}
		else
		{
			swap(a);
			write(1, "sa\n", 3);
		}
	}
}

void	sort_em_all(t_lst *a, t_lst *b, int i)
{
	if (a->actual_size > 3)
	{
		while (a->actual_size > 3)
		{
			push(a, b);
			write(1, "pb\n", 3);
		}
	}
	sort_tri_list(a);
	while (b->actual_size > 0)
		insert_ele_in_lst(a, b, 0, 0);
	while (a->lst[i] != a->e_min)
		i++;
	if (i > a->actual_size / 2)
	{
		while (a->lst[0] != a->e_min)
			revers_rotate(a, 1);
	}
	else
	{
		while (a->lst[0] != a->e_min)
			rotate(a, 1);
	}
}
