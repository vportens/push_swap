/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laclide <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 19:07:29 by laclide           #+#    #+#             */
/*   Updated: 2021/06/07 17:52:53 by viporten         ###   ########.fr       */
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

void	do_some_swap(t_lst *a, t_lst *b, int res)
{
	if (res == 6)
	{
		rotate(a, 0);
		rotate(b, 0);
	}
	else if (res == 7)
		push(b, a);
	else if (res == 8)
		push(a, b);
	else if (res == 9)
		revers_rotate(a, 0);
	else if (res == 10)
		revers_rotate(b, 0);
	else if (res == 11)
	{
		revers_rotate(a, 0);
		revers_rotate(b, 0);
	}
}

int	do_the_move(char *str, t_lst *a, t_lst *b)
{
	int	res;

	res = check_text(str);
	if (res < 0)
		return (1);
	if (res == 1)
		swap(a);
	else if (res == 2)
		swap(b);
	else if (res == 3)
	{
		swap(a);
		swap(b);
	}
	else if (res == 4)
		rotate(a, 0);
	else if (res == 5)
		rotate(b, 0);
	else if (res >= 6 && res <= 11)
		do_some_swap(a, b, res);
	return (0);
}

int	main(int ac, char *av[0])
{
	t_lst	a;
	t_lst	b;
	char	*str;

	if (ac < 2)
		return (error(0, &a, &b));
	if (check_arg(ac, av) == 1)
		return (error(0, &a, &b));
	if (init_lst(&a, &b, ac, av) == 1)
		return (error(0, &a, &b));
	while (rec_gnl(0, &str))
	{
		if (do_the_move(str, &a, &b) != 0)
		{
			free(str);
			return (error(3, &a, &b));
		}
		free(str);
	}
	if (str)
		free(str);
	if (is_lst_sort(&a) == 0 && b.actual_size == 0)
		return (error(4, &a, &b));
	else
		return (error(3, &a, &b));
}
