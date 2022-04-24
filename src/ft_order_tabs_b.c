/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_order_tabs_b.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasser <jrasser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 21:39:06 by jrasser           #+#    #+#             */
/*   Updated: 2022/04/18 00:41:26 by jrasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_tabs	ft_pb_ordered(t_tabs *tabs, t_sort *sort)
{
	int	nb_rotate;
	int	sens;

	sens = 1;
	if (ft_pb_ordered_index(tabs, sort) >= (tabs->b.size + 1) / 2)
	{
		nb_rotate = tabs->b.size - ft_pb_ordered_index(tabs, sort);
		sens = 0;
	}
	else
		nb_rotate = ft_pb_ordered_index(tabs, sort);
	while (nb_rotate > 0)
	{
		if (sens)
			sort->offset += 1;
		if (sens)
			ft_rb(*tabs);
		else
		{
			sort->offset -= 1;
			ft_rrb(*tabs);
		}
		nb_rotate--;
	}
	return (ft_pb(*tabs));
}

int	ft_sub_pb_ordered_index(t_tabs *tabs, t_sort *sort)
{
	int	i;
	int	nb;

	nb = tabs->a.tab[0];
	i = tabs->b.size;
	while (--i && i > tabs->b.size - 1 - sort->offset)
	{
		if (nb >= ft_search_max_block(tabs->b, sort))
			return (ft_index_of(ft_search_max_block(tabs->b, sort), tabs->b));
		if (nb < ft_search_min_block(tabs->b, sort))
			return (ft_index_of(ft_search_min_block(tabs->b, sort), \
			tabs->b) + 1);
		if (tabs->b.size == 1 && tabs->b.tab[0] > nb)
			return (1);
		if ((tabs->b.size == 1 && tabs->b.tab[0] < nb)
			|| (i == tabs->b.size - 1 && tabs->b.tab[i] > nb
				&& tabs->b.tab[0] < nb))
			return (0);
		if (i != tabs->b.size - 1 && tabs->b.size > 1
			&& tabs->b.tab[i] > nb && tabs->b.tab[i + 1] < nb)
			return (i + 1);
	}
	return (-1);
}

int	ft_pb_ordered_index(t_tabs *tabs, t_sort *sort)
{
	int	i;
	int	nb;

	nb = tabs->a.tab[0];
	i = -1;
	while (++i < tabs->b.size - 1 && i < tabs->b.size % S_BLOCK - sort->offset)
	{
		if (nb >= ft_search_max_block(tabs->b, sort))
			return (ft_index_of(ft_search_max_block(tabs->b, sort), tabs->b));
		if (nb < ft_search_min_block(tabs->b, sort))
			return (ft_index_of(ft_search_min_block(tabs->b, sort), \
			tabs->b) + 1);
		if (tabs->b.size == 1 && tabs->b.tab[0] > nb)
			return (1);
		if ((tabs->b.size == 1 && tabs->b.tab[0] < nb)
			|| (i == tabs->b.size - 1 && tabs->b.tab[i] > nb
				&& tabs->b.tab[0] < nb))
			return (0);
		if (i != tabs->b.size - 1 && tabs->b.size > 1
			&& tabs->b.tab[i] > nb && tabs->b.tab[i + 1] < nb)
			return (i + 1);
	}
	return (ft_sub_pb_ordered_index(tabs, sort));
}

t_tabs	ft_order_tabs_b(t_tabs tabs)
{
	int	max;
	int	index_max;

	if (tabs.b.size == 0)
		return (tabs);
	max = ft_search_max(tabs.b);
	index_max = ft_index_of(max, tabs.b);
	if (max == tabs.b.tab[0])
		return (tabs);
	if (index_max >= tabs.b.size / 2)
		while (tabs.b.tab[0] != max)
			ft_rrb(tabs);
	else
		while (tabs.b.tab[0] != max)
			ft_rb(tabs);
	return (tabs);
}

int	ft_index_of(int nb, t_tab tab)
{
	int	i;

	i = 0;
	while (i < tab.size)
	{
		if (tab.tab[i] == nb)
			return (i);
		i++;
	}
	return (0);
}
