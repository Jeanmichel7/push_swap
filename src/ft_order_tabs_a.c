/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_order_tabs_a.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasser <jrasser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 11:44:35 by jrasser           #+#    #+#             */
/*   Updated: 2022/04/17 02:08:33 by jrasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_tabs	ft_pa_ordered(t_tabs tabs)
{
	int	index;
	int	nb_rotate;
	int	sens;

	sens = 1;
	index = ft_pa_ordered_index(tabs);
	if (index >= (tabs.a.size + 1) / 2)
	{
		nb_rotate = tabs.a.size - index;
		sens = 0;
	}
	else
		nb_rotate = index;
	while (nb_rotate)
	{
		if (sens)
			ft_ra(tabs);
		else
			ft_rra(tabs);
		nb_rotate--;
	}
	tabs = ft_pa(tabs);
	return (tabs);
}

int	ft_pa_ordered_index(t_tabs tabs)
{
	int	i;
	int	nb;
	int	min;
	int	max;

	min = ft_search_min(tabs.a);
	max = ft_search_max(tabs.a);
	nb = tabs.b.tab[0];
	i = 0;
	while (i < tabs.a.size)
	{
		if (nb < min && tabs.a.tab[i] == min)
			return (i);
		if (nb > max && tabs.a.tab[i] == max && i != tabs.a.size - 1)
			return (i + 1);
		if (i != tabs.a.size - 1
			&& tabs.a.tab[i] < nb && tabs.a.tab[i + 1] > nb)
			return (i + 1);
		i++;
	}
	return (i);
}

t_tabs	ft_order_tabs_a(t_tabs tabs)
{
	int	index_min;
	int	min;

	index_min = ft_search_index_min(tabs.a);
	min = tabs.a.tab[index_min];
	if (min == tabs.a.tab[0])
		return (tabs);
	if (index_min >= tabs.a.size / 2)
		while (tabs.a.tab[0] != min)
			ft_rra(tabs);
	else
		while (tabs.a.tab[0] != min)
			ft_ra(tabs);
	return (tabs);
}

int	ft_search_min_first_third(t_tabs tabs)
{
	int	i;
	int	min;
	int	index_min;

	i = 0;
	min = 2147483647;
	index_min = 0;
	while (i < tabs.a.size / 3)
	{
		if (tabs.a.tab[i] < min)
		{
			min = tabs.a.tab[i];
			index_min = i;
		}
		i++;
	}
	return (index_min);
}

t_tabs	ft_pa_ordered_first_third(t_tabs tabs)
{
	int	index;
	int	nb_rotate;
	int	sens;

	sens = 1;
	index = ft_search_min_first_third(tabs);
	if (index >= (tabs.a.size + 1) / 2)
	{
		nb_rotate = tabs.a.size - index;
		sens = 0;
	}
	else
		nb_rotate = index;
	while (nb_rotate)
	{
		if (sens)
			ft_ra(tabs);
		else
			ft_rra(tabs);
		nb_rotate--;
	}
	return (tabs);
}
