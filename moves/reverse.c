/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorrao- <ptorrao-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 16:17:09 by ptorrao-          #+#    #+#             */
/*   Updated: 2024/08/12 11:04:32 by ptorrao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rra(t_stack	**a, int i)
{
	t_stack	*temp1;
	t_stack	*temp2;

	temp1 = *a;
	temp2 = *a;
	while (temp2->next->next)
		temp2 = temp2->next;
	while (temp1->next)
		temp1 = temp1->next;
	temp1->next = *a;
	temp2->next = NULL;
	*a = temp1;
	if (i == 0)
		ft_printf("rra\n");
}

void	rrb(t_stack	**b, int i)
{
	t_stack	*temp1;
	t_stack	*temp2;

	temp1 = *b;
	temp2 = *b;
	while (temp2->next->next)
		temp2 = temp2->next;
	while (temp1->next)
		temp1 = temp1->next;
	temp1->next = *b;
	temp2->next = NULL;
	*b = temp1;
	if (i == 0)
		ft_printf("rrb\n");
}

void	rrr(t_stack **a, t_stack **b)
{
	rra (a, 1);
	rrb (b, 1);
	ft_printf("rrr\n");
}
