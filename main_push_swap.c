/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_push_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laclide <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 11:04:21 by laclide           #+#    #+#             */
/*   Updated: 2021/07/04 23:30:14 by laclide          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	found_good_place(t_push *lst)
{
	t_sort	*prec;
	t_sort	*start;
	int	i;

	i = 0;
	prec = NULL;
	start = lst->first_a;
	while (lst->first_a->next)
	{
		lst->first_a = lst->first_a->next;
	}
	prec = lst->first_a;
	lst->first_a = start;
	while (lst->first_a)
	{
		if ((prec->nbr < lst->first_b->nbr && lst->first_a->nbr > lst->first_b->nbr) || (prec->nbr == lst->e_max_a && (lst->first_b->nbr < lst->e_min_a || lst->first_b->nbr > lst->e_max_a)))
		{
			break;
		}
		i++;
		prec = lst->first_a;
		lst->first_a = lst->first_a->next;
	}
	lst->first_a = start;
	return (i);
}

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

void	sort_tri_list(t_push *lst)
{
	while (list_sort(lst) != 1)
	{
		if (lst->first_a->next->nbr == lst->e_min_a && lst->first_a->nbr == lst->e_max_a)
		{
			write(1, "ra\n", 3);
			rotate(lst, lst->first_a);
		}
		else if (lst->first_a->next->nbr == lst->e_max_a && lst->first_a->nbr != lst->e_min_a)
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
	printf("list a |");
	while (lst->first_a)
	{
		printf("%d |", lst->first_a->nbr);
		lst->first_a = lst->first_a->next;
	}
}

int	main(int ac, char *av[])
{
	t_push new;

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
	if (ac < 20)
	{
		sort_em_all(&new);
		return (1);
	}
	solver_push_swap(&new);
	clean(&new, 2);
	printf("main	list a |");
	while (new.first_a)
	{
		printf("%d |", new.first_a->nbr);
		new.first_a = new.first_a->next;
	}
	printf("\n");
}
