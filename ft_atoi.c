/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal--ce <edal--ce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 17:04:12 by laclide           #+#    #+#             */
/*   Updated: 2021/06/04 13:15:00 by edal--ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_lst *to_swap)
{
	int	tmp;

	if (to_swap->actual_size < 2)
		return ;
	tmp = to_swap->lst[0];
	to_swap->lst[0] = to_swap->lst[1];
	to_swap->lst[1] = tmp;
	return ;
}

int	ft_atoi(char *str, t_lst *a, int index)
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
	a->lst[index] = nbr;
	return (0);
}
