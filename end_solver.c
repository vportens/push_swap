/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_solver.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laclide <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 17:18:43 by laclide           #+#    #+#             */
/*   Updated: 2021/07/03 17:22:31 by laclide          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	put_second_part(t_push *stc)
{
		while (stc->first_b->nbr != stc->e_max_b)
		{
			revers_rotate(stc, stc->first_b);
			write(1, "rrb\n", 4);
		}
}

void	put_big_one_to_the_top(t_push *stc)
{
	t_sort *start;
	int	i;

	start = stc->first_b;
	i = 0;
	while (stc->first_b && stc->first_b->nbr != stc->e_max_b)
	{
		i++;
		stc->first_b = stc->first_b->next;
	}
	stc->first_b = start;
	if (i < stc->max_lst / 2)
	{
		while (stc->first_b->nbr != stc->e_max_b)
		{
			rotate(stc, stc->first_b);
			write(1, "rb\n", 3);
		}
	}
	else 
		put_second_part(stc);
}

void	send_lst(t_push *stc)
{
	while (stc->first_b)
	{
		push(stc, stc->first_b);
		write(1, "pb\n", 3);
	}
}

int		fucking_norme(int which_one, int a, int b, int c)
{
	if (which_one == 1)
		return (a);
	if (which_one == 0)
		return (b);
	if (which_one == -1)
		return (c);
}

