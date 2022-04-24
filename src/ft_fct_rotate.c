/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fct_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasser <jrasser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 11:52:42 by jrasser           #+#    #+#             */
/*   Updated: 2022/03/31 20:56:31 by jrasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_ra(t_tabs tabs)
{
	int	temp;
	int	i;

	write (1, "ra\n", 3);
	if (tabs.a.size >= 2)
	{
		i = 0;
		temp = tabs.a.tab[0];
		while (i < tabs.a.size - 1)
		{
			tabs.a.tab[i] = tabs.a.tab[i + 1];
			i++;
		}
		tabs.a.tab[i] = temp;
	}
}

void	ft_rb(t_tabs tabs)
{
	int	temp;
	int	i;

	write (1, "rb\n", 3);
	if (tabs.b.size >= 2)
	{
		i = 0;
		temp = tabs.b.tab[0];
		while (i < tabs.b.size - 1)
		{
			tabs.b.tab[i] = tabs.b.tab[i + 1];
			i++;
		}
		tabs.b.tab[i] = temp;
	}
}

void	ft_rr(t_tabs tabs)
{
	int	temp;
	int	i;

	write (1, "rr\n", 3);
	if (tabs.a.size >= 2)
	{
		i = -1;
		temp = tabs.a.tab[0];
		while (++i < tabs.a.size - 1)
			tabs.a.tab[i] = tabs.a.tab[i + 1];
		tabs.a.tab[i] = temp;
	}
	if (tabs.b.size >= 2)
	{
		i = -1;
		temp = tabs.b.tab[0];
		while (++i < tabs.b.size - 1)
			tabs.b.tab[i] = tabs.b.tab[i + 1];
		tabs.b.tab[i] = temp;
	}
}
