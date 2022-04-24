/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasser <jrasser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 01:03:58 by jrasser           #+#    #+#             */
/*   Updated: 2022/04/19 00:08:44 by jrasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap_bonus.h"

t_tabs	ft_parse_args(int argc, char **argv)
{
	t_tabs	tabs;
	int		i;
	int		j;

	tabs.a.tab = ft_calloc(sizeof(int), argc - 1);
	i = 0;
	while (i < argc - 1)
	{
		tabs.a.tab[i] = ft_atoi(argv[i + 1]);
		j = 0;
		while (j < i)
		{
			if (tabs.a.tab[i] == tabs.a.tab[j])
			{
				write (2, "Error\n", 6);
				free (tabs.a.tab);
				exit (-1);
			}
			j++;
		}
		i++;
	}
	tabs.a.size = i;
	return (tabs);
}

t_tabs	ft_parse_arg(char **argv)
{
	t_tabs	tabs;
	char	**tabs_temp;
	int		i;
	int		len;

	tabs_temp = ft_split(argv[1], ' ');
	i = -1;
	len = 0;
	while (tabs_temp[++i])
		len++;
	tabs.a.tab = ft_calloc(sizeof(int), len);
	i = 0;
	while (tabs_temp[i])
	{
		tabs.a.tab[i] = ft_atoi(tabs_temp[i]);
		free(tabs_temp[i]);
		i++;
	}
	free(tabs_temp);
	tabs.a.size = i;
	return (tabs);
}

t_tabs	ft_fill_array(int argc, char **argv)
{
	t_tabs	tabs;

	if (argc == 2)
		tabs = ft_parse_arg(argv);
	else
		tabs = ft_parse_args(argc, argv);
	tabs.a = ft_reverse_tab(tabs.a);
	tabs.b.size = 0;
	return (tabs);
}

t_tab	ft_reverse_tab(t_tab tab)
{
	int	i;
	int	temp;

	i = 0;
	while (i < tab.size)
	{
		temp = tab.tab[i];
		tab.tab[i] = tab.tab[tab.size - 1 - i];
		tab.tab[tab.size - 1 - i] = temp;
		i++;
	}
	return (tab);
}

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
