/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laclide <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 21:52:01 by laclide           #+#    #+#             */
/*   Updated: 2021/07/03 17:23:54 by laclide          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_sorting_pos(t_push *stc)
{
	int		i;
	t_sort	*first;

	i = 0;
	while (i < stc->max_lst)
	{
		first = stc->first_a;
		while (stc->first_a->nbr != stc->tab_a[i])
			stc->first_a = stc->first_a->next;
		stc->first_a->pos_sort = i;
		stc->first_a = first;
		i++;
	}
	stc->first_a = first;
}

void	sort_tab(t_push *stc)
{
	int	i;
	int	tmp;

	i = 0;
	while (i < stc->max_lst - 1)
	{
		if (stc->tab_a[i] > stc->tab_a[i + 1])
		{
			tmp = stc->tab_a[i];
			stc->tab_a[i] = stc->tab_a[i + 1];
			stc->tab_a[i + 1] = tmp;
			i = 0;
		}
		else
			i++;
	}
	init_sorting_pos(stc);
	return ;
}
