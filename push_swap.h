/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laclide <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 11:10:14 by laclide           #+#    #+#             */
/*   Updated: 2021/07/06 12:25:18 by laclide          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

struct	s_sort;

typedef struct s_push
{
	int			*tab_a;
	int			max_lst;
	int			actual_size_a;
	int			actual_size_b;
	int			e_min_a;
	int			e_max_a;
	int			e_min_b;
	int			e_max_b;
	int			nbr_per_part;
	int			min_move;
	int			nbr_to_move;
	struct s_sort		*first_a;
	struct s_sort		*first_b;

}				t_push;

typedef struct	s_sort
{
	int		nbr;
	int		pos_sort;
	int		ra;
	int		rra;
	int		rb;
	int		rrb;
	int		nbr_move;
	int		r;
	struct s_sort	*next;
}				t_sort;

int	ft_str_len(char *str);
char	*ft_itoa(int nbr);
int	check_arg(int ac, char **av);
int	error(int i, t_push *lst);
int	clean(t_push *lst, int i);
int	init_stc(t_push *lst, int ac, char **av);
int	check_doublon(t_push *lst);

int	is_lst_sort(int *tab, int max_lst);
int	ft_atoi(char *str, int *a, int index);
int	init_lst_b_chaine(t_push *lst);
int	*ft_cp_tab(int	*tab, int max_lst);

int	ft_lst_add_back(int	nbr, t_push *stc);
int	ft_lst_first(int nbr, t_push *stc);
t_sort	*ft_lst_last(t_push *stc);


void	sort_tab(t_push *stc);
void	swap(t_push	*stc, int list);
void	push(t_push *stc, t_sort *target);
t_sort	*rotate(t_push *stc, t_sort *target);

t_sort	*revers_rotate(t_push *stc, t_sort *target);
int	list_sort(t_push *stc);

void	solver_push_swap(t_push *stc);

void	check_max_min(t_push *stc, t_sort *target);
void	update_max_min_lst_b(t_push *stc, t_sort *target);
void	update_max_min_lst(t_push *stc, t_sort *target);
void	check_max_min_b(t_push *stc, t_sort *target);
	
void	push_rr(t_push *stc, t_sort *start, int a, int b);
void	push_r(t_push *stc, t_sort *start, int a, int b);
void	push_both(t_push *stc, t_sort *start);
void	push_both_second_path(t_push *stc, t_sort *start);
void	push_the_nbr(int nbr_to_move, t_push *stc);
void	put_big_one_to_the_top(t_push *stc);
void	put_second_part(t_push *stc);
void	send_lst(t_push *stc);
int		fucking_norme(int which_one, int a, int b, int c);

void	sort_em_all(t_push *lst);
void	sort_tri_list(t_push *lst);
int	found_good_place(t_push *lst);
void	witch_side_rotate(t_push *lst, int i);
void	insert_ele_in_lst(t_push *lst);
int		found_e_min(t_push *lst);
#endif
