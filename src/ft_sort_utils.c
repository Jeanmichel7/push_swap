/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasser <jrasser@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 21:45:53 by jrasser           #+#    #+#             */
/*   Updated: 2022/05/02 15:01:44 by jrasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_tab_is_sort(t_tab tab)
{
	int	i;

	i = 0;
	while (i < tab.size)
	{
		if (i != tab.size - 1 && tab.tab[i] > tab.tab[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	ft_tab_is_reverse_sort(t_tab tab)
{
	int	i;

	i = 0;
	while (i < tab.size)
	{
		if (i != tab.size - 1 && tab.tab[i] < tab.tab[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	ft_tab_is_sort_with_rotate(t_tab tab)
{
	int	i;
	int	min_gr1;
	int	max_gr1;
	int	min_gr2;
	int	max_gr2;

	i = 0;
	min_gr1 = tab.tab[i];
	while (i < tab.size - 1 && tab.tab[i] < tab.tab[i + 1])
		i++;
	if (i == tab.size - 1)
		return (0);
	max_gr1 = tab.tab[i++];
	min_gr2 = tab.tab[i];
	max_gr2 = tab.tab[i];
	while (i < tab.size - 1 && tab.tab[i] < tab.tab[i + 1])
		max_gr2 = tab.tab[i++ + 1];
	if (i == tab.size - 1 && tab.tab[i] > tab.tab[i - 1])
		max_gr2 = tab.tab[i];
	if (i == tab.size - 1 && (max_gr2 < min_gr1
			|| max_gr1 < min_gr2))
		return (1);
	return (0);
}

t_tabs	ft_order_tab_with_rotate(t_tabs tabs)
{
	int	i;
	int	min;

	i = 0;
	min = ft_search_min(tabs.a);
	while (i < tabs.a.size - 1 && tabs.a.tab[i] < tabs.a.tab[i + 1])
		i++;
	if (i == tabs.a.size - 1 && tabs.a.tab[i] > tabs.a.tab[i - 1])
		i++;
	if (i == tabs.a.size - 1)
		return (tabs);
	if (i >= tabs.a.size / 2)
		while (tabs.a.tab[0] != min)
			ft_rra(tabs);
	else
		while (tabs.a.tab[0] != min)
			ft_ra(tabs);
	return (tabs);
}

void	ft_print_tabs(t_tabs tabs)
{
	int	i;

	i = 0;
	ft_printf("\n     A     |     B\n");
	ft_printf("-----------|-----------\n");
	while (i < tabs.a.size || i < tabs.b.size)
	{
		if (i < tabs.a.size)
			ft_printf("% 10d |", tabs.a.tab[i]);
		else
			ft_printf("           |");
		if (tabs.b.size != 0 && tabs.b.size > i)
			ft_printf("% 10d\n", tabs.b.tab[i]);
		else
			ft_printf("\n");
		i++;
	}
	ft_printf("\n\n");
}
