/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasser <jrasser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 19:34:04 by jrasser           #+#    #+#             */
/*   Updated: 2022/04/18 00:42:36 by jrasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_search_min(t_tab tab)
{
	int	i;
	int	min;

	i = 0;
	min = 2147483647;
	while (i < tab.size)
	{
		if (tab.tab[i] < min)
			min = tab.tab[i];
		i++;
	}
	return (min);
}

int	ft_search_max(t_tab tab)
{
	int	i;
	int	max;

	i = 0;
	max = -2147483648;
	while (i < tab.size)
	{
		if (tab.tab[i] > max)
			max = tab.tab[i];
		i++;
	}
	return (max);
}

int	ft_search_min_block(t_tab tab, t_sort *sort)
{
	int	i;
	int	min;
	int	size;

	size = tab.size % S_BLOCK;
	min = 2147483647;
	i = 0;
	while (i < tab.size - 1 && i < size - sort->offset)
	{
		if (tab.tab[i] < min)
			min = tab.tab[i];
		i++;
	}
	i = tab.size - 1;
	while (i && i > tab.size - 1 - sort->offset)
	{
		if (tab.tab[i] < min)
			min = tab.tab[i];
		i--;
	}
	return (min);
}

int	ft_search_max_block(t_tab tab, t_sort *sort)
{
	int	i;
	int	max;
	int	size;

	size = tab.size % S_BLOCK;
	i = 0;
	max = -2147483648;
	while (i < tab.size - 1 && i < size - sort->offset)
	{
		if (tab.tab[i] > max)
			max = tab.tab[i];
		i++;
	}
	i = tab.size - 1;
	while (i && i > tab.size - 1 - sort->offset)
	{
		if (tab.tab[i] > max)
			max = tab.tab[i];
		i--;
	}
	return (max);
}

int	ft_search_index_min(t_tab tab)
{
	int	i;
	int	min;
	int	index_min;

	i = 0;
	min = 2147483647;
	while (i < tab.size)
	{
		if (tab.tab[i] < min)
		{
			min = tab.tab[i];
			index_min = i;
		}
		i++;
	}
	return (index_min);
}
