/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laclide <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 17:04:12 by laclide           #+#    #+#             */
/*   Updated: 2021/06/01 17:25:03 by laclide          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
