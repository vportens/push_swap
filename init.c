/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laclide <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 17:56:55 by laclide           #+#    #+#             */
/*   Updated: 2021/07/03 15:33:05 by laclide          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int	init_lst(t_push *stc, int nbr_element)
{
	int	i;
	t_sort	*first;

	i = 0;
	stc->first_a = NULL;
	stc->first_b = NULL;
	stc->actual_size_b = 0;
	stc->actual_size_a = nbr_element;
	while (i < nbr_element)
	{
		if (stc->first_a == NULL)
		{
			if (ft_lst_first(stc->tab_a[i], stc) == 1)
				return (error(2, stc));
			first = stc->first_a;
		}
		else if (ft_lst_add_back(stc->tab_a[i], stc) == 1)
			return (error(2, stc));
		i++;
	}
	stc->first_a = first;
/*	while (stc->first_a != NULL)
	{
		printf("init.c	in the list %d\n", stc->first_a->nbr);
		stc->first_a = stc->first_a->next;
	}*/
	return (0);
}

int	init_stc(t_push *stc, int ac, char **av)
{
	int	i;

	i = 0;
	stc->tab_a = malloc(sizeof(int) * (ac - 1));
	if (stc->tab_a == NULL)
		return (error(0, stc));
	while (i < ac - 1)
	{
		if (ft_atoi(av[i + 1], stc->tab_a, i) == 1)
			return (error(1, stc));
		i++;
	}
	stc->actual_size_a = ac - 1;
	stc->max_lst = ac - 1;
	if (check_doublon(stc) == 1)
		return (1);
	if (init_lst(stc, ac - 1) == 1)
		return (1);
	return (0);
}
