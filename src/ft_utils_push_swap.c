/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_push_swap.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasser <jrasser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 09:37:34 by jrasser           #+#    #+#             */
/*   Updated: 2022/04/28 23:11:36 by jrasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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
				exit (1);
			}
			j++;
		}
		i++;
	}
	tabs.a.size = i;
	return (tabs);
}

void	ft_checker_doublon(t_tabs tabs, int i)
{
	int	j;

	j = 0;
	while (j < i)
	{
		if (tabs.a.tab[i] == tabs.a.tab[j])
		{
			write (2, "Error\n", 6);
			free (tabs.a.tab);
			exit (1);
		}
		j++;
	}
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
		ft_checker_doublon(tabs, i);
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
