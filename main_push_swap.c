/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_push_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laclide <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 11:04:21 by laclide           #+#    #+#             */
/*   Updated: 2021/07/03 16:33:09 by laclide          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	solver_push_swap(&new);
	printf("main	list a |");
	while (new.first_a)
	{
		printf("%d |", new.first_a->nbr);
		new.first_a = new.first_a->next;
	}
	printf("\n");
}
