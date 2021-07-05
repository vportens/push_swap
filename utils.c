/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laclide <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 11:08:13 by laclide           #+#    #+#             */
/*   Updated: 2021/07/04 18:11:07 by laclide          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int clean(t_push *lst, int i)
{
	t_sort	*tmp;

	if (i >= 1)
		free(lst->tab_a);
	if (i >= 2)
	{
		while (lst->first_a != NULL)
		{
			tmp = lst->first_a;
			lst->first_a = lst->first_a->next;
			free(tmp);
		}
	}
	return (1);
}

int	error(int i, t_push *lst)
{
	int	j;

	j = 0;
	if (i >= 0)
		write(1, "Error\n", 6);
	if (i > 0)
		clean(lst, i);
	return (1);
}

int	ft_atoi(char *str, int *a, int index)
{
	double	nbr;
	int		i;
	int		j;

	i = 0;
	nbr = 0;
	j = 1;
	if (str[0] == '-')
	{
		i++;
		j = -1;
	}
	while (str[i])
	{
		nbr = nbr * 10 + str[i] - 48;
		i++;
	}
	nbr = nbr * j;
	if (nbr > 2147483647 || nbr < -2147483648)
		return (1);
	a[index] = nbr;
	return (0);
}

int	check_doublon(t_push *lst)
{
	int	i;
	int	j;

	i = 0;
	lst->e_min_a = lst->tab_a[0];
	lst->e_max_a = lst->tab_a[0];
	while (i < lst->actual_size_a - 1)
	{
		j = i + 1;
		while (j < lst->actual_size_a)
		{
			if (lst->tab_a[j] < lst->e_min_a)
				lst->e_min_a = lst->tab_a[j];
			if (lst->tab_a[j] > lst->e_max_a)
				lst->e_max_a = lst->tab_a[j];
			if (lst->tab_a[i] == lst->tab_a[j])
				return (error(1, lst));
			j++;
		}
		i++;
	}
	return (0);
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

int	*ft_cp_tab(int	*tab, int max_lst)
{
	int	i;
	int	*new;

	i = 0;
	new = malloc(sizeof(int) * (max_lst));
	if (new == NULL)
		return (NULL);
	i = 0;
	while (i < max_lst)
	{
		new[i] = tab[i];
		i++;
	}
	return (new);
}