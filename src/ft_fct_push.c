/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fct_push.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasser <jrasser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 13:20:07 by jeulliot          #+#    #+#             */
/*   Updated: 2022/04/09 16:56:47 by jrasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_check_tabs_free(t_tabs tabs)
{
	free (tabs.a.tab);
	if (tabs.b.size)
		free (tabs.b.tab);
}

t_tabs	ft_pb(t_tabs tabs)
{
	int		i;
	t_tabs	new_tabs;

	write (1, "pb\n", 3);
	if (tabs.a.size >= 1)
	{
		new_tabs.a.tab = ft_calloc(sizeof(int), tabs.a.size - 1);
		i = -1;
		while (++i < tabs.a.size - 1)
			new_tabs.a.tab[i] = tabs.a.tab[i + 1];
		new_tabs.a.size = tabs.a.size - 1;
		new_tabs.b.tab = ft_calloc(sizeof(int), tabs.b.size + 1);
		i = -1;
		new_tabs.b.tab[0] = tabs.a.tab[0];
		while (++i < tabs.b.size)
			new_tabs.b.tab[i + 1] = tabs.b.tab[i];
		new_tabs.b.size = tabs.b.size + 1;
		ft_check_tabs_free(tabs);
		return (new_tabs);
	}
	return (tabs);
}

t_tabs	ft_pa(t_tabs tabs)
{
	int		i;
	t_tabs	new_tabs;

	write (1, "pa\n", 3);
	if (tabs.b.size >= 1)
	{
		new_tabs.b.tab = ft_calloc(sizeof(int), tabs.b.size - 1);
		i = -1;
		while (++i < tabs.b.size - 1)
			new_tabs.b.tab[i] = tabs.b.tab[i + 1];
		new_tabs.b.size = tabs.b.size - 1;
		new_tabs.a.tab = ft_calloc(sizeof(int), tabs.a.size + 1);
		i = -1;
		new_tabs.a.tab[0] = tabs.b.tab[0];
		while (++i < tabs.a.size)
			new_tabs.a.tab[i + 1] = tabs.a.tab[i];
		new_tabs.a.size = tabs.a.size + 1;
		ft_check_tabs_free(tabs);
		return (new_tabs);
	}
	return (tabs);
}
