/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasser <jrasser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 20:56:51 by jrasser           #+#    #+#             */
/*   Updated: 2022/04/18 23:27:54 by jrasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap_bonus.h"

int	main(int argc, char **argv)
{
	t_tabs	tabs;
	char	*cmd;

	ft_check_arg_error(argc, argv);
	tabs = ft_fill_array(argc, argv);
	cmd = get_next_line(0);
	while (cmd)
	{
		tabs = ft_check_cmd(tabs, cmd);
		cmd = get_next_line(0);
	}
	if (ft_tab_is_sort(tabs.a) && tabs.b.size == 0)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	free (tabs.a.tab);
	return (0);
}

t_tabs	ft_check_cmd(t_tabs tabs, char *cmd)
{
	if (ft_strncmp(cmd, "sa", ft_strlen(cmd) - 1) == 0)
		ft_sa(tabs);
	else if (ft_strncmp(cmd, "sb", ft_strlen(cmd) - 1) == 0)
		ft_sb(tabs);
	else if (ft_strncmp(cmd, "ss", ft_strlen(cmd) - 1) == 0)
		ft_ss(tabs);
	else if (ft_strncmp(cmd, "pa", ft_strlen(cmd) - 1) == 0)
		tabs = ft_pa(tabs);
	else if (ft_strncmp(cmd, "pb", ft_strlen(cmd) - 1) == 0)
		tabs = ft_pb(tabs);
	else if (ft_strncmp(cmd, "ra", ft_strlen(cmd) - 1) == 0)
		ft_ra(tabs);
	else if (ft_strncmp(cmd, "rb", ft_strlen(cmd) - 1) == 0)
		ft_rb(tabs);
	else if (ft_strncmp(cmd, "rr", ft_strlen(cmd) - 1) == 0)
		ft_rr(tabs);
	else if (ft_strncmp(cmd, "rra", ft_strlen(cmd) - 1) == 0)
		ft_rra(tabs);
	else if (ft_strncmp(cmd, "rrb", ft_strlen(cmd) - 1) == 0)
		ft_rrb(tabs);
	else if (ft_strncmp(cmd, "rrr", ft_strlen(cmd) - 1) == 0)
		ft_rrr(tabs);
	else
		ft_display_error();
	return (ft_free_return(tabs, cmd));
}

t_tabs	ft_free_return(t_tabs tabs, char *cmd)
{
	free(cmd);
	return (tabs);
}

void	ft_display_error(void)
{
	write (2, "Error\n", 6);
	exit (1);
}
