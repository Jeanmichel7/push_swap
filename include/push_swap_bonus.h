/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasser <jrasser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 21:01:38 by jrasser           #+#    #+#             */
/*   Updated: 2022/04/19 00:25:38 by jrasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H

# define PUSH_SWAP_BONUS_H
# define BUFFER_SIZE 4
# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"
# include <sys/types.h>
# include <sys/uio.h>
# include <sys/stat.h>
# include <fcntl.h>

typedef struct s_tab
{
	int	*tab;
	int	size;
}	t_tab;

typedef struct s_tabs
{
	t_tab	a;
	t_tab	b;
}	t_tabs;

void	ft_check_arg_error(int argc, char **argv);
t_tabs	ft_fill_array(int argc, char **argv);
t_tab	ft_reverse_tab(t_tab tab);
t_tabs	ft_check_cmd(t_tabs tabs, char *cmd);
int		ft_tab_is_sort(t_tab tab);
void	ft_display_error(void);
t_tabs	ft_free_return(t_tabs tabs, char *cmd);

/* GET NEXT LINE */
char	*get_next_line(int fd);
char	*ft_strconcat(char *dst, char *src);
size_t	ft_strlen(const char *str);
char	*update_buffer(char *buffer);
int		ft_is_buffer_end_line(char *buffer);
int		ft_check_buffer_empty(char **buffer, int fd);
char	*ft_calloc_line(char *buffer, long size);
int		ft_read(int fd, char *buffer);

/*  FCT OPERATION  */
void	ft_sa(t_tabs tabs);
void	ft_sb(t_tabs tabs);
void	ft_ss(t_tabs tabs);

t_tabs	ft_pa(t_tabs tabs);
t_tabs	ft_pb(t_tabs tabs);

void	ft_ra(t_tabs tabs);
void	ft_rb(t_tabs tabs);
void	ft_rr(t_tabs tabs);

void	ft_rra(t_tabs tabs);
void	ft_rrb(t_tabs tabs);
void	ft_rrr(t_tabs tabs);

#endif
