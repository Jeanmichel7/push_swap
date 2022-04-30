/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasser <jrasser@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 17:55:22 by jrasser           #+#    #+#             */
/*   Updated: 2022/04/30 20:48:31 by jrasser          ###   ########.fr       */
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

/*
make re && ./push_swap 824 -119 215 -308 217
bash push_swap_tester/tester.sh ../push_swap 100 100
*/
