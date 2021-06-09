/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_em_by_part.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viporten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 17:33:44 by viporten          #+#    #+#             */
/*   Updated: 2021/06/09 19:07:06 by viporten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		find_min_next(int min, t_lst *a, int *pos, int index)
{
	int	i;
	int	ret;

	i = 0;
	ret = a->e_max;
	while (i < a->actual_size)
	{
		if (a->lst[i] < ret && a->lst[i] > min)
		{
			ret = a->lst[i];
			pos[index] = i;
		}
		i++;
	}
	i = 0;
	if (ret == a->e_max)
	{
		while (a->lst[i] != a->e_max)
			i++;
		pos[index] = i;
	}
	return (ret);
}

void	init_pool(t_lst *a, int *pool, int *pos)
{
	int i;
	int	tmp;

	i = 0;
	tmp = a->e_min;
	while (a->lst[i] != a->e_min)
		i++;
	pos[0] = i;
	i = 1;
	pool[0] = a->e_min;
	while (i < 10 && i < a->actual_size)
	{
		pool[i] = find_min_next(a->e_min, a, pos, i);
		a->e_min = pool[i];
		i++;
	}
	a->e_min = tmp;
	return ;
}

void	sort_em_by_part(t_lst *a, t_lst *b, int ac)
{
	int	i;
	int	j;
	int	pool[10];
	int	pos[10];

	i = 0;
	init_pool(a, pool, pos);
	while (i < 10 && i < a->actual_size)
	{
		printf("%d position %d\n",pool[i], pos[i]);
		i++;
	}
}
