/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_checker_push_swap.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laclide <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 19:20:57 by laclide           #+#    #+#             */
/*   Updated: 2021/07/11 19:52:11 by laclide          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_for_two_c(char *str)
{
	if (str[0] == 's' && str[1] == 'a')
		return (1);
	if (str[0] == 's' && str[1] == 'b')
		return (2);
	if (str[0] == 's' && str[1] == 's')
		return (3);
	if (str[0] == 'r' && str[1] == 'a')
		return (4);
	if (str[0] == 'r' && str[1] == 'b')
		return (5);
	if (str[0] == 'r' && str[1] == 'r')
		return (6);
	if (str[0] == 'p' && str[1] == 'a')
		return (7);
	if (str[0] == 'p' && str[1] == 'b')
		return (8);
	return (-1);
}

int	check_text(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	if (i != 2 && i != 3)
		return (-1);
	if (i == 2)
		return (check_for_two_c(str));
	if (i == 3)
	{
		if (str[0] == 'r' && str[1] == 'r' && str[2] == 'a')
			return (9);
		if (str[0] == 'r' && str[1] == 'r' && str[2] == 'b')
			return (10);
		if (str[0] == 'r' && str[1] == 'r' && str[2] == 'r')
			return (11);
	}
	return (-1);
}

void	do_some_swap(t_push *stc, int res)
{
	if (res == 6)
	{
		rotate(stc, stc->first_a);
		rotate(stc, stc->first_b);
	}
	else if (res == 7)
		push(stc, stc->first_b);
	else if (res == 8)
		push(stc, stc->first_a);
	else if (res == 9)
		revers_rotate(stc, stc->first_a);
	else if (res == 10)
		revers_rotate(stc, stc->first_b);
	else if (res == 11)
	{
		revers_rotate(stc, stc->first_a);
		revers_rotate(stc, stc->first_b);
	}
}

int	do_the_move(char *str, t_push *stc)
{
	int	res;

	res = check_text(str);
	if (res < 0)
		return (1);
	if (res == 1)
		swap(stc, 1);
	else if (res == 2)
		swap(stc, 2);
	else if (res == 3)
	{
		swap(stc, 1);
		swap(stc, 2);
	}
	else if (res == 4)
		rotate(stc, stc->first_a);
	else if (res == 5)
		rotate(stc, stc->first_b);
	else if (res >= 6 && res <= 11)
		do_some_swap(stc, res);
	return (0);
}

int	main(int ac, char *av[])
{
	t_push	new;
	char	*str;

	if (check_arg(ac, av) == 1)
		return (error(0, &new));
	if (init_stc(&new, ac, av) == 1)
		return (0);
	while (rec_gnl(0, &str) != 0)
	{
		if (do_the_move(str, &new) != 0)
		{
			free(str);
			return (error(3, &new));
		}
		free(str);
	}
	if (str)
		free(str);
	if (list_sort(&new) != 1 || new.actual_size_b != 0)
		return (clean(&new, 55));
	else
		return (clean(&new, 56));
}
