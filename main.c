/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laclide <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 14:37:09 by laclide           #+#    #+#             */
/*   Updated: 2021/06/03 15:04:39 by laclide          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

nbr_move = 0;

int	error(int i)
{
	if (i == 1)
		write(1, "bad arg\n", 8);
	write(1, "Error\n", 6);
	return (0);
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
			{
				free(a->lst);
				free(b->lst);
				return (1);
			}
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
		{
			free(a->lst);
			free(b->lst);
			return (1);
		}
		b->lst[i] = 0;
		i++;
	}
	a->actual_size = ac - 1;
	b->actual_size = 0;
	return (check_doublon(a, b));
}

int	check_arg(int ac, char **av)
{
	int i;
	int j;

	i = 1;
	while (i < ac)
	{
		j = 0;
		while (av[i][j] != '\0')
		{
			if ((av[i][j] <= '9' && av[i][j] >= '0') || (j == 0 && av[i][0] == '-'))
				j++;
			else
				return (1);
		}
		i++;
	}
	return (0);
}

int	main(int ac, char *av[])
{
	t_lst 	a;
	t_lst 	b;
	t_move	move;
	
	if (ac < 2)
		return (error(0));
	if (ac == 2)
		return (0);
	if (check_arg(ac, av) == 1)
		return (0);
	if (init_lst(&a, &b, ac, av) == 1)
		return (error(0));
	//push(&a, &b);
	//push(&b, &a);
	sort_em_all(&a, &b, &move);
	int	i;

	i = is_lst_sort(&a);
//	if (i == 0)
//		printf("la liste est trier\n");

//	swap(&a);
//	revers_rotate(&a);
	//rotate(&a);
//	rotate(&a);
//	rotate(&a);
//	push(&a, &b);
//	push(&b, &a);
//	push(&a, &b);
//	push(&a, &b);
//	push(&a, &b);
//	push(&a, &b);
//	push(&a, &b);
//	swap(&a);

	i = 0;
	printf("\n nbr move fait %d\n", nbr_move);
	printf("list a\n");
	while (i < a.max_lst)
	{
		printf("%d\n", a.lst[i]);
		i++;
	}
	printf("\nlist b\n");
	i = 0;
	while (i < b.max_lst)
	{
		printf("%d\n", b.lst[i]);
		i++;
	}
	/*
	printf("nbr max dans list a %d\n", a.max_lst);
	printf("nbr in list a %d\n", a.actual_size);
	printf("nbr min de list a %d\n", a.e_min);
	printf("nbr max de list a %d\n", a.e_max);
	printf("nbr max dans list b %d\n", b.max_lst);
	printf("nbr in list b %d\n", b.actual_size);
	printf("nbr min de list b %d\n", b.e_min);
	printf("nbr max de list b %d\n", b.e_max);*/
}
