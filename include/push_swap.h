/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasser <jrasser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 17:56:35 by jeulliot          #+#    #+#             */
/*   Updated: 2022/04/19 00:25:23 by jrasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H
# define S_BLOCK 40
# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"

typedef struct s_sort
{
	int	i;
	int	last_max;
	int	ll_max;
	int	i_check;
	int	offset;
}	t_sort;

typedef struct s_tab
{
	int	*tab;
	int	size;
}	t_tab;

typedef struct s_tabs
{
	t_tab	a;
	t_tab	b;
}	t_tabs;

void	ft_check_arg_error(int argc, char **argv);
t_tabs	ft_fill_array(int argc, char **argv);
t_tab	ft_reverse_tab(t_tab tab);
void	ft_print_tabs(t_tabs tabs);

/*  FCT LANGUAGE  */
void	ft_sa(t_tabs tabs);
void	ft_sb(t_tabs tabs);
void	ft_ss(t_tabs tabs);

t_tabs	ft_pa(t_tabs tabs);
t_tabs	ft_pb(t_tabs tabs);

void	ft_ra(t_tabs tabs);
void	ft_rb(t_tabs tabs);
void	ft_rr(t_tabs tabs);

void	ft_rra(t_tabs tabs);
void	ft_rrb(t_tabs tabs);
void	ft_rrr(t_tabs tabs);

/*  SORT  */
t_tabs	ft_sort(t_tabs tabs);
int		ft_tab_is_sort(t_tab tab);
int		ft_tab_is_reverse_sort(t_tab tab);
int		ft_tab_is_sort_with_rotate(t_tab tab);
t_tabs	ft_first_sort(t_tabs tabs);
t_tabs	ft_second_sort(t_tabs tabs);

t_tabs	ft_pa_ordered(t_tabs tabs);
int		ft_pa_ordered_index(t_tabs tabs);
t_tabs	ft_pb_ordered(t_tabs *tabs, t_sort *sort);
int		ft_pb_ordered_index(t_tabs *tabs, t_sort *sort);
t_tabs	ft_order_tabs_a(t_tabs tabs);
t_tabs	ft_order_tabs_b(t_tabs tabs);

t_tabs	ft_order_tab_with_rotate(t_tabs tabs);
int		ft_search_min(t_tab tab);
int		ft_search_max(t_tab tab);
int		ft_search_min_block(t_tab tab, t_sort *sort);
int		ft_search_max_block(t_tab tab, t_sort *sort);
int		ft_search_index_min(t_tab tab);

/*  UTILS FIRST SORT  */
t_sort	ft_sort_swap(t_sort sort, t_tabs *tabs);
t_sort	ft_sort_push(t_sort *sort, t_tabs *tabs);
t_sort	ft_sort_ra(t_sort sort, t_tabs *tabs);

int		ft_index_of(int nb, t_tab tab);
int		ft_search_min_first_third(t_tabs tabs);
t_tabs	ft_pa_ordered_first_third(t_tabs tabs);

#endif
