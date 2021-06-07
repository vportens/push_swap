/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_push_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal--ce <edal--ce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 14:37:09 by laclide           #+#    #+#             */
/*   Updated: 2021/06/07 17:10:15 by viporten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char *av[])
{
	t_lst	a;
	t_lst	b;

	if (ac < 2)
		return (error(0, &a, &b));
	if (check_arg(ac, av) == 1)
		return (error(0, &a, &b));
	if (init_lst(&a, &b, ac, av) == 1)
		return (error(0, &a, &b));
	sort_em_all(&a, &b, 0);
	free(a.lst);
	free(b.lst);
}
