/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasser <jrasser@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 13:20:16 by jeulliot          #+#    #+#             */
/*   Updated: 2022/04/30 23:35:22 by jrasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_tabs	ft_sort(t_tabs tabs)
{
	if (!ft_tab_is_sort(tabs.a))
	{
		if (tabs.a.tab[0] > tabs.a.tab[1]
			&& ft_tab_is_sort_with_rotate(tabs.a) != 1)
			ft_sa(tabs);
		if (ft_tab_is_sort_with_rotate(tabs.a) == 1)
			tabs = ft_order_tab_with_rotate(tabs);
		if (!ft_tab_is_sort(tabs.a))
		{
			tabs = ft_first_sort(tabs);
			tabs = ft_second_sort(tabs);
		}
	}
	return (tabs);
}

void	ft_sub_first_sort(t_tabs *tabs, t_sort *sort)
{
	if ((sort->i_check == 1 && tabs->a.tab[1] > tabs->a.tab[tabs->a.size - 1]
		&& tabs->a.tab[1] < tabs->a.tab[0])
		|| (sort->i_check == 0 && tabs->a.tab[1] < tabs->a.tab[0]
			&& tabs->a.tab[0] > sort->last_max)
		|| (sort->i_check == 0 && tabs->a.tab[1] == ft_search_min(tabs->a)))
	{
		*sort = ft_sort_swap(*sort, tabs);
		sort->i--;
	}
	else
	{
		*sort = ft_sort_push(sort, tabs);
		sort->i--;
	}
}

t_tabs	ft_first_sort(t_tabs tabs)
{
	t_sort	sort;

	sort.i = 0;
	sort.i_check = 1;
	sort.last_max = tabs.a.tab[0];
	sort.ll_max = sort.last_max;
	sort.offset = 0;
	while (sort.i < tabs.a.size + tabs.b.size
		&& ft_tab_is_sort_with_rotate(tabs.a) != 1 && !ft_tab_is_sort(tabs.a))
	{
		if (tabs.b.size % S_BLOCK == 0 && tabs.b.size > 0)
		{
			tabs = ft_order_tabs_b(tabs);
			sort.offset = 0;
		}
		if (tabs.a.tab[sort.i_check] == ft_search_max(tabs.a)
			&& sort.i_check != 0 && tabs.a.size > 3)
			sort = ft_sort_push(&sort, &tabs);
		else if (tabs.a.tab[sort.i_check] < sort.last_max)
			ft_sub_first_sort(&tabs, &sort);
		else
			sort = ft_sort_ra(sort, &tabs);
		sort.i++;
	}
	return (tabs);
}

t_tabs	ft_second_sort(t_tabs tabs)
{
	int	state;

	state = 0;
	while (tabs.b.size)
	{
		tabs = ft_pa_ordered(tabs);
		state = 1;
	}
	if (state)
		free(tabs.b.tab);
	tabs = ft_order_tabs_a(tabs);
	return (tabs);
}
