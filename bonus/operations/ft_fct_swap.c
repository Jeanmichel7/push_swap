/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fct_swap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasser <jrasser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 13:20:07 by jeulliot          #+#    #+#             */
/*   Updated: 2022/04/09 14:56:45 by jrasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap_bonus.h"

void	ft_sa(t_tabs tabs)
{
	int	temp;

	if (tabs.a.size >= 2)
	{
		temp = tabs.a.tab[0];
		tabs.a.tab[0] = tabs.a.tab[1];
		tabs.a.tab[1] = temp;
	}
}

void	ft_sb(t_tabs tabs)
{
	int	temp;

	if (tabs.b.size >= 2)
	{
		temp = tabs.b.tab[0];
		tabs.b.tab[0] = tabs.b.tab[1];
		tabs.b.tab[1] = temp;
	}
}

void	ft_ss(t_tabs tabs)
{
	int	temp;

	if (tabs.a.size >= 2)
	{
		temp = tabs.a.tab[0];
		tabs.a.tab[0] = tabs.a.tab[1];
		tabs.a.tab[1] = temp;
	}
	if (tabs.b.size >= 2)
	{
		temp = tabs.b.tab[0];
		tabs.b.tab[0] = tabs.b.tab[1];
		tabs.b.tab[1] = temp;
	}
}
