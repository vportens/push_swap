/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laclide <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 15:24:21 by laclide           #+#    #+#             */
/*   Updated: 2021/06/03 14:24:54 by laclide          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_lst
{
	int			max_lst;
	int			*lst;
	int			actual_size;
	int			e_min;
	int			e_max;
}				t_lst;

typedef struct	s_move
{
	char		*move;
	struct s_move		*next;
}				t_move;


int nbr_move;

int				ft_atoi(char *str, t_lst *a, int index);

void			push(t_lst *from, t_lst *to);
void			swap(t_lst *to_swap);
void			rotate(t_lst *to_rotate);
void			revers_rotate(t_lst *to_rotate);

int				is_lst_sort(t_lst *a);
int				sort_em_all(t_lst *a, t_lst *b, t_move *move);
void			sort_tri_list(t_lst *a);

#endif
