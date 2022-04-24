/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasser <jrasser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 17:55:22 by jrasser           #+#    #+#             */
/*   Updated: 2022/04/18 23:28:50 by jrasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

int	main(int argc, char **argv)
{
	t_tabs	tabs;

	ft_check_arg_error(argc, argv);
	tabs = ft_fill_array(argc, argv);
	tabs = ft_sort(tabs);
	free (tabs.a.tab);
	return (0);
}