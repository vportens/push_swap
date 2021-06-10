/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_em_by_part.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viporten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 17:33:44 by viporten          #+#    #+#             */
/*   Updated: 2021/06/10 18:10:43 by viporten         ###   ########.fr       */
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

t_sort	*init_lst_pool(t_lst *a, int *pool, int *pos)
{
	int j;
	int i;
	t_sort	*new = NULL;
	t_sort	*first = NULL;
	t_sort	*tmp = NULL;

	i = 0;
	if (a->actual_size < 10)
		j = a->actual_size;
	else
		j = 10;
	while (i < j)
	{
		printf("%d index, %d index max\n",i,j);
		new = malloc(sizeof(t_sort));
		new->pool = pool[i];
		new->pos = pos[i];
		new->next = NULL;
		if (tmp)
		{
			tmp->next = new;
		}
		if (i == 0)
		{
			first = new;
		}
		tmp = new;
		i++;
	}
	return (first);
}

void	find_the_way(t_lst *a, t_lst *b, t_sort *lst, int index)
{
	int ra_ez = 1000;
	int	rra_ez = 1000;
	int ra;
	int	rra;
	int pos_ez;
	t_sort *first;
	t_sort	*prec;
	t_sort	*tmp;

	first = lst;
	prec = NULL;
	while (lst)
	{
		ra = i - lst->pos;
		rra = a->e_max - lst->pos + index + 1;
		if (ra < ra_ez)
		{
			pos_ez = lst->pos;
			ra_ez = ra;
		}
		if (rra < rra_ez)
		{
			pos_ez = lst->pos;
			rra_ez = rra;
		}
		lst = lst->next;
	}
	lst = first;
	while (lst->pos != pos_ez && lst)
	{
		prec = lst;
		lst = lst->next;
	}
	if (ra_ez < rra_ez)
		printf("%d\n operation a faire", ra_ez);
	else if (rra_ez < ra_ez)
		printf("%d\n operation a faire", rra_ez);
	if (prec == NULL && lst->next == NULL)
	{
		free(lst);
		lst = NULL;
	}
	else if (prec == NULL)
	{
		tmp = lst->next;
		free(lst);
		lst = tmp;
	}
	else if
	{
		prec->next = lst->next;
		free(lst);
	}
	lst = first;
}

void	sort_em_by_part(t_lst *a, t_lst *b, int ac)
{
	int	i;
	int	j;
	t_sort *lst = NULL;

	int	pool[10];
	int	pos[10];

	i = 0;
	j = 0;
	init_pool(a, pool, pos);
	lst = init_lst_pool(a, pool, pos);
	while (lst)
	{
		find_the_way(a, b, lst, i);
	}
	while (i < 10 && i < a->actual_size)
	{
		printf("%d position %d\n",pool[i], pos[i]);
		i++;
	}
	while (lst)
	{
		printf("%d positon pool %d\n", lst->pool, lst->pos);
		lst = lst->next;
	}
	
}
