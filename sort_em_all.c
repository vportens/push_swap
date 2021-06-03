/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_em_all.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal--ce <edal--ce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 13:00:17 by laclide           #+#    #+#             */
/*   Updated: 2021/06/03 17:13:07 by edal--ce         ###   ########.fr       */
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

void	insert_ele_in_lst(t_lst *a, t_lst *b)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (a->lst[i] != a->e_min)
		i++;
	while (j < a->actual_size)
	{

		if (a->lst[i] < b->lst[0])
			i++;

		else
			break;
		if (i == a->actual_size)
			i = 0;
		j++;
	}
	if (i > a->actual_size / 2)
	{
		while (i != 0)
		{
			revers_rotate(a);
			write(1, "rra\n", 4);
			i++;
			i = i % a->actual_size;
		}
	}
	else
	{
		while (i != 0)
		{
			rotate(a);
			write(1, "ra\n", 3);
			i--;
		}
	}
	push(b, a);
	write(1, "pa\n", 3);
	return ;


}

void	sort_tri_list(t_lst *a)
{
	while (is_lst_sort(a) != 0)
	{
		if (a->lst[1] == a->e_min && a->lst[0] == a->e_max)
		{
			rotate(a);
			write(1, "ra\n", 3);
		}
		else if (a->lst[1] == a->e_max && a->lst[0] != a->e_min)
		{
			revers_rotate(a);
			write(1, "rra\n", 4);
		}
		else 
		{
			swap(a);
			write(1, "sa\n", 3);
		}
	}
}

int	sort_em_all(t_lst *a, t_lst *b, t_move *move)
{
	int i;

	i = 0;
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
	{
		insert_ele_in_lst(a, b);
	}
	while (a->lst[i] != a->e_min)
		i++;
	if (i > a->actual_size / 2)
	{
		while (a->lst[0] != a->e_min)
		{
			revers_rotate(a);
			write(1, "rra\n", 4);
			i--;
		}
	}
	else
	{
		while (a->lst[0] != a->e_min)
		{
			rotate(a);
			write(1, "ra\n", 4);
		}

	}
}
