/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorrao- <ptorrao-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 16:28:06 by ptorrao-          #+#    #+#             */
/*   Updated: 2024/08/12 11:04:57 by ptorrao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	pa(t_stack **a, t_stack **b)
{
	t_stack	*temp1;
	t_stack	*temp2;

	if (!(*b))
		return ;
	temp1 = *b;
	temp2 = (*b)->next;
	temp1->next = *a;
	*b = temp2;
	*a = temp1;
	ft_printf("pa\n");
}

void	pb(t_stack **a, t_stack **b)
{
	t_stack	*temp1;
	t_stack	*temp2;

	if (!(*a))
		return ;
	temp1 = *a;
	temp2 = (*a)->next;
	temp1->next = *b;
	*a = temp2;
	*b = temp1;
	ft_printf("pb\n");
}
