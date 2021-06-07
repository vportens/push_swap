/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laclide <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 19:39:28 by laclide           #+#    #+#             */
/*   Updated: 2021/06/07 17:11:45 by viporten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	error(int i, t_lst *a, t_lst *b)
{
	if (i < 3)
		write(2, "Error\n", 6);
	if (i == 2)
	{
		free(a->lst);
		free(b->lst);
	}
	if (i == 3)
	{
		write(1, "KO\n", 3);
		free(a->lst);
		free(b->lst);
	}
	if (i == 4)
	{
		write(1, "OK\n", 3);
		free(a->lst);
		free(b->lst);
	}
	return (1);
}

int	check_doublon(t_lst *a, t_lst *b)
{
	int	i;
	int	j;

	i = 0;
	a->e_min = a->lst[0];
	a->e_max = a->lst[0];
	while (i < a->actual_size - 1)
	{
		j = i + 1;
		while (j < a->actual_size)
		{
			if (a->lst[j] < a->e_min)
				a->e_min = a->lst[j];
			if (a->lst[j] > a->e_max)
				a->e_max = a->lst[j];
			if (a->lst[i] == a->lst[j])
				return (error(2, a, b));
			j++;
		}
		i++;
	}
	return (0);
}

int	init_lst(t_lst *a, t_lst *b, int ac, char **av)
{
	int	i;

	i = 0;
	a->max_lst = ac - 1;
	b->max_lst = ac - 1;
	a->lst = malloc(sizeof (int) * (ac - 1));
	if (a->lst == NULL)
		return (1);
	b->lst = malloc(sizeof (int) * (ac - 1));
	if (b->lst == NULL)
	{
		free(a->lst);
		return (1);
	}
	while (i < ac - 1)
	{
		if (ft_atoi(av[i + 1], a, i) == 1)
			return (error(2, a, b));
		b->lst[i] = 0;
		i++;
	}
	a->actual_size = ac - 1;
	b->actual_size = 0;
	return (check_doublon(a, b));
}

int	check_arg(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	while (i < ac)
	{
		j = 0;
		while (av[i][j] != '\0')
		{
			if ((av[i][j] <= '9' && av[i][j] >= '0')
				|| (j == 0 && av[i][0] == '-'))
				j++;
			else
				return (1);
		}
		i++;
	}
	return (0);
}