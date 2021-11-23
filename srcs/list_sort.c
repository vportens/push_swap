/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laclide <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 17:17:30 by laclide           #+#    #+#             */
/*   Updated: 2021/07/04 21:59:34 by laclide          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	list_sort(t_push *stc)
{
	t_sort	*first;
	int		nbr;

	first = stc->first_a;
	if (stc->first_a)
		nbr = first->nbr;
	while (stc->first_a)
	{
		if (stc->first_a->nbr < nbr)
		{
			stc->first_a = first;
			return (0);
		}
		nbr = stc->first_a->nbr;
		stc->first_a = stc->first_a->next;
	}
	stc->first_a = first;
	return (1);
}
