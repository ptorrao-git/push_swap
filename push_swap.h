/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorrao- <ptorrao-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 15:14:27 by ptorrao-          #+#    #+#             */
/*   Updated: 2024/08/12 11:01:15 by ptorrao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/ft_printf/ft_printf.h"
# include "libft/libft.h"
# include "libft/get_next_line/get_next_line_bonus.h"
# include "limits.h"

typedef struct s_stack
{
	long			data;
	int				index;
	struct s_stack	*next;
}	t_stack;

void	ft_free_mtr(char **str);
void	ft_free_stacks(t_stack **a, t_stack **b);
void	ft_ultimate_free(char **str, t_stack **a, t_stack **b, int argc);

void	validate_matrix(char **mtr, int argc, t_stack **a, t_stack **b);
void	validate_min_max(char **mtr, int argc, t_stack **a, t_stack **b);
void	validate_duplicates(char **mtr, int argc, t_stack **a, t_stack **b);
void	validate_list(char **mtr, int argc, t_stack **a, t_stack **b);
void	insert_index(t_stack **a, int i);
void	radix_sort(t_stack **a, t_stack **b);
void	sort_3(t_stack **a);
void	sort_4(t_stack **a, t_stack **b, int i);
void	sort_5(t_stack **a, t_stack **b, int i);
void	choose_sort(t_stack **a, t_stack **b);

void	pb(t_stack **a, t_stack **b);
void	pa(t_stack **a, t_stack **b);
void	rra(t_stack	**a, int i);
void	rrb(t_stack	**b, int i);
void	rrr(t_stack **a, t_stack **b);
void	ra(t_stack	**a, int i);
void	rb(t_stack	**b, int i);
void	rr(t_stack **a, t_stack **b);
void	sa(t_stack	**a, int i);
void	sb(t_stack	**b, int i);
void	ss(t_stack **a, t_stack **b);

int		size_of_list(t_stack **a);
int		sorted(t_stack **a);

#endif