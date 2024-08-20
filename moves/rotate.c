/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorrao- <ptorrao-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 13:55:38 by ptorrao-          #+#    #+#             */
/*   Updated: 2024/08/12 11:02:29 by ptorrao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ra(t_stack	**a, int i)
{
	t_stack	*temp1;
	t_stack	*temp2;

	temp1 = *a;
	temp2 = (*a)->next;
	while (temp1->next)
		temp1 = temp1->next;
	temp1->next = *a;
	(*a)->next = NULL;
	*a = temp2;
	if (i == 0)
		ft_printf("ra\n");
}

void	rb(t_stack	**b, int i)
{
	t_stack	*temp1;
	t_stack	*temp2;

	temp1 = *b;
	temp2 = (*b)->next;
	while (temp1->next)
		temp1 = temp1->next;
	temp1->next = *b;
	(*b)->next = NULL;
	(*b) = temp2;
	if (i == 0)
		ft_printf("rb\n");
}

void	rr(t_stack **a, t_stack **b)
{
	ra (a, 1);
	rb (b, 1);
	ft_printf("rr\n");
}
