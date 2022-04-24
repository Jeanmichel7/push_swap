/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_first_sort_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasser <jrasser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 19:35:59 by jrasser           #+#    #+#             */
/*   Updated: 2022/04/18 00:41:21 by jrasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_sort	ft_sort_swap(t_sort sort, t_tabs *tabs)
{
	sort.ll_max = (*tabs).a.tab[sort.i_check];
	ft_sa(*tabs);
	ft_ra(*tabs);
	return (sort);
}

t_sort	ft_sort_push(t_sort *sort, t_tabs *tabs)
{
	if (sort->i_check == 1)
		ft_ra(*tabs);
	*tabs = ft_pb_ordered(tabs, sort);
	sort->i_check = 0;
	return (*sort);
}

t_sort	ft_sort_ra(t_sort sort, t_tabs *tabs)
{
	sort.ll_max = sort.last_max;
	sort.last_max = (*tabs).a.tab[sort.i_check];
	ft_ra(*tabs);
	return (sort);
}
