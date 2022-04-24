/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fct_reverse_rotate.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasser <jrasser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 20:57:35 by jrasser           #+#    #+#             */
/*   Updated: 2022/04/09 14:57:06 by jrasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap_bonus.h"

void	ft_sub_rotate(int *tab, int i, int *temp, int *temp2)
{
	*temp2 = tab[i];
	tab[i] = *temp;
	*temp = *temp2;
}

void	ft_rra(t_tabs tabs)
{
	int	temp;
	int	temp2;
	int	i;

	if (tabs.a.size >= 2)
	{
		temp = tabs.a.tab[0];
		tabs.a.tab[0] = tabs.a.tab[tabs.a.size - 1];
		i = 1;
		while (i < tabs.a.size)
		{
			temp2 = tabs.a.tab[i];
			tabs.a.tab[i] = temp;
			temp = temp2;
			i++;
		}
	}
}

void	ft_rrb(t_tabs tabs)
{
	int	temp;
	int	temp2;
	int	i;

	if (tabs.b.size >= 2)
	{
		temp = tabs.b.tab[0];
		tabs.b.tab[0] = tabs.b.tab[tabs.b.size - 1];
		i = 1;
		while (i < tabs.b.size)
		{
			temp2 = tabs.b.tab[i];
			tabs.b.tab[i] = temp;
			temp = temp2;
			i++;
		}
	}
}

void	ft_rrr(t_tabs tabs)
{
	int	temp;
	int	temp2;
	int	i;

	if (tabs.a.size >= 2)
	{
		temp = tabs.a.tab[0];
		tabs.a.tab[0] = tabs.a.tab[tabs.a.size - 1];
		i = 0;
		while (++i < tabs.a.size)
			ft_sub_rotate(tabs.a.tab, i, &temp, &temp2);
	}
	if (tabs.b.size >= 2)
	{
		temp = tabs.b.tab[0];
		tabs.b.tab[0] = tabs.b.tab[tabs.b.size - 1];
		i = 0;
		while (++i < tabs.b.size)
			ft_sub_rotate(tabs.b.tab, i, &temp, &temp2);
	}
}
