/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal--ce <edal--ce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 14:39:17 by laclide           #+#    #+#             */
/*   Updated: 2021/06/04 13:15:44 by edal--ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	update_part_one(t_lst *from, t_lst *to)
{
	if (to->actual_size == 0)
	{
		to->e_max = from->lst[0];
		to->e_min = from->lst[0];
	}
	if (from->actual_size == 1)
	{
		from->e_max = 0;
		from->e_min = 0;
	}
	if (to->actual_size != 0)
	{
		if (to->e_min > from->lst[0])
			to->e_min = from->lst[0];
		if (to->e_max < from->lst[0])
			to->e_max = from->lst[0];
	}
}

void	update_limit(t_lst *from, t_lst *to)
{
	int	i;

	i = 1;
	update_part_one(from, to);
	if (from->actual_size != 1 && from->lst[0] == from->e_min)
	{
		from->e_min = from->lst[i];
		while (i < from->actual_size)
		{
			if (from->lst[i] < from->e_min)
				from->e_min = from->lst[i];
			i++;
		}
	}
	i = 1;
	if (from->actual_size != 1 && from->lst[0] == from->e_max)
	{
		from->e_max = from->lst[i];
		while (i < from->actual_size)
		{
			if (from->lst[i] > from->e_max)
				from->e_max = from->lst[i];
			i++;
		}
	}
}

void	push(t_lst *from, t_lst *to)
{
	int	tmp;
	int	i;

	i = to->actual_size;
	if (from->actual_size == 0)
		return ;
	tmp = from->lst[0];
	if (to->actual_size == 0 || tmp == from->e_min || tmp == from->e_max
		|| tmp < to->e_min || tmp > to->e_max)
		update_limit(from, to);
	while (i > 0)
	{
		to->lst[i] = to->lst[i - 1];
		i--;
	}
	to->lst[0] = tmp;
	to->actual_size++;
	from->actual_size--;
	i = 1;
	while (i <= from->actual_size)
	{
		from->lst[i - 1] = from->lst[i];
		i++;
	}
	from->lst[i - 1] = 0;
}

void	rotate(t_lst *to_rotate)
{
	int	tmp;
	int	i;

	i = 0;
	tmp = to_rotate->lst[0];
	if (to_rotate->actual_size < 2)
		return ;
	while (i < to_rotate->actual_size - 1)
	{
		to_rotate->lst[i] = to_rotate->lst[i + 1];
		i++;
	}
	to_rotate->lst[i] = tmp;
	write(1, "ra\n", 3);
	return ;
}

void	revers_rotate(t_lst *to_rotate)
{
	int	tmp;
	int	i;

	i = to_rotate->actual_size - 1;
	tmp = to_rotate->lst[i];
	if (i < 1)
		return ;
	while (i > 0)
	{
		to_rotate->lst[i] = to_rotate->lst[i - 1];
		i--;
	}
	to_rotate->lst[i] = tmp;
	write(1, "rra\n", 4);
	return ;
}
