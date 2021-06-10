/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_push_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal--ce <edal--ce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 14:37:09 by laclide           #+#    #+#             */
/*   Updated: 2021/06/10 17:40:50 by viporten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char *av[])
{
	t_lst	a;
	t_lst	b;

	if (ac < 2)
		return (0);
	if (check_arg(ac, av) == 1)
		return (error(0, &a, &b));
	if (init_lst(&a, &b, ac, av) == 1)
		return (error(0, &a, &b));
	if (is_lst_sort(&a) == 0)
		return (0);
//	if (ac < 100)
//		sort_em_all(&a, &b, 0);
//	else
	sort_em_by_part(&a, &b, 0);
	free(a.lst);
	free(b.lst);
}
