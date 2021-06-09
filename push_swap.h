/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal--ce <edal--ce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 15:24:21 by laclide           #+#    #+#             */
/*   Updated: 2021/06/09 17:25:33 by viporten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# define BUFFER_SIZE 100

typedef struct s_lst
{
	int			max_lst;
	int			*lst;
	int			actual_size;
	int			e_min;
	int			e_max;
}				t_lst;

int				ft_atoi(char *str, t_lst *a, int index);
void			push(t_lst *from, t_lst *to);
void			swap(t_lst *to_swap);
void			rotate(t_lst *to_rotate, int show);
void			revers_rotate(t_lst *to_rotate, int show);
int				is_lst_sort(t_lst *a);
void			sort_em_all(t_lst *a, t_lst *b, int i);
void			sort_tri_list(t_lst *a);
int				get_next_line(int fd, char **line);
int				check_arg(int ac, char **av);
int				init_lst(t_lst *a, t_lst *b, int ac, char **av);
int				check_doublon(t_lst *a);
int				error(int i, t_lst *a, t_lst *b);
int				rec_gnl(int fd, char **line);

#endif
