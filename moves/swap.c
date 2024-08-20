/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorrao- <ptorrao-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 13:55:32 by ptorrao-          #+#    #+#             */
/*   Updated: 2024/08/05 16:27:46 by ptorrao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sa(t_stack	**a, int i)
{
	int	temp;
	int	temp_index;

	temp = (*a)->data;
	temp_index = (*a)->index;
	(*a)->data = (*a)->next->data;
	(*a)->index = (*a)->next->index;
	(*a)->next->data = temp;
	(*a)->next->index = temp_index;
	if (i == 0)
		ft_printf("sa\n");
}

void	sb(t_stack	**b, int i)
{
	int	temp;
	int	temp_index;

	temp = (*b)->data;
	temp_index = (*b)->index;
	(*b)->data = (*b)->next->data;
	(*b)->index = (*b)->next->index;
	(*b)->next->data = temp;
	(*b)->next->index = temp_index;
	if (i == 0)
		ft_printf("sb\n");
}

void	ss(t_stack **a, t_stack **b)
{
	sa (a, 1);
	sb (b, 1);
	ft_printf("ss\n");
}
