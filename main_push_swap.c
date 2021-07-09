/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_push_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laclide <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 11:04:21 by laclide           #+#    #+#             */
/*   Updated: 2021/07/06 12:42:48 by laclide          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	witch_side_rotate(t_push *lst, int i)
{
	if (i > lst->actual_size_a / 2)
	{
		while (i != 0)
		{
			revers_rotate(lst, lst->first_a);
			write(1, "rra\n", 4);
			i++;
			i = i % lst->actual_size_a;
		}
	}
	else
	{
		while (i != 0)
		{
			rotate(lst, lst->first_a);
			write(1, "ra\n", 3);
			i--;
		}
	}
}

void	insert_ele_in_lst(t_push *lst)
{
	t_sort *start;
	int	i;

	start = lst->first_a;
	i = found_good_place(lst);
	witch_side_rotate(lst, i);
	push(lst, lst->first_b);
	write(1, "pa\n", 3);
}

int		found_e_min(t_push *lst)
{
	int	i;
	t_sort	*start;

	i = 0;
	start = lst->first_a;
	while (lst->first_a->nbr != lst-> e_min_a)
	{
		i++;
		lst->first_a = lst->first_a->next;
	}
	lst->first_a = start;
	return (i);
}


int	main(int ac, char *av[])
{
	t_push new;
	int	i;

	if (ac < 2)
		return (0);
	if (check_arg(ac, av) == 1)
		return (error(0, &new));
	if (init_stc(&new, ac, av) == 1)
		return (0);
	sort_tab(&new);
	if (list_sort(&new) == 1)
		return (clean(&new, 2));
	new.nbr_per_part = ac;
	if (ac < 3)
	{
		write(1, "ra\n", 3);
	}
	if (ac < 20)
	{
		sort_em_all(&new);
		if (list_sort(&new) != 1)
			write(1,"ERROR\n", 6);
		return (clean(&new, 2));
	}
	solver_push_swap(&new);
	if (list_sort(&new) != 1)
		write(1,"ERROR\n", 6);
	t_sort *start;

	start = new.first_a;
/*	while (new.first_a)
	{
		printf("%d |",new.first_a->nbr);
new.first_a = new.first_a->next;
	}*/
	clean(&new, 2);
}
