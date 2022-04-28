/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasser <jrasser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 17:56:23 by jeulliot          #+#    #+#             */
/*   Updated: 2022/04/28 23:05:56 by jrasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_is_int(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '-' || str[0] == '+')
		if (str[++i] == '\0')
			return (0);
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

void	ft_check_arg_error(int argc, char **argv)
{
	int	i;
	int	nbr;

	if (argc == 1)
		exit (1);
	i = 1;
	while (i < argc)
	{
		nbr = ft_atoi(argv[i]);
		if (nbr == 0)
		{
			if (argv[i][0] != '0' && ft_strncmp(argv[i], "-0", 2))
			{
				write (2, "Error\n", 6);
				exit (1);
			}
		}
		i++;
	}
}
