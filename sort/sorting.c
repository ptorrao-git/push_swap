/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorrao- <ptorrao-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 21:55:27 by ptorrao-          #+#    #+#             */
/*   Updated: 2024/08/12 11:11:06 by ptorrao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	radix_sort(t_stack **a, t_stack **b)
{
	int		len;
	int		bit;

	bit = 0;
	while (!sorted(a))
	{
		len = size_of_list(a);
		while (len--)
		{
			if ((*a)->index & 1 << bit)
				ra(a, 0);
			else
				pb(a, b);
		}
		while (*b)
			pa(a, b);
		bit++;
	}
}

void	sort_3(t_stack **a)
{
	int	top;
	int	mid;
	int	bot;

	bot = (*a)->next->next->data;
	mid = (*a)->next->data;
	top = (*a)->data;
	if (top > mid && mid > bot)
	{
		sa(a, 0);
		rra(a, 0);
	}
	else if (top > bot && bot > mid)
		ra(a, 0);
	else if (mid > top && top > bot)
		rra(a, 0);
	else if (mid > bot && bot > top)
	{
		sa(a, 0);
		ra(a, 0);
	}
	else if (bot > top && top > mid)
		sa(a, 0);
}

void	sort_4(t_stack **a, t_stack **b, int i)
{
	if ((*a)->next->next->next->index == i)
	{
		while ((*a)->index != i)
			rra(a, 0);
	}
	else
		while ((*a)->index != i)
			ra(a, 0);
	if (!sorted(a))
	{
		pb(a, b);
		sort_3(a);
		pa(a, b);
	}
}

void	sort_5(t_stack **a, t_stack **b, int i)
{
	if ((*a)->next->next->next->index == i
		|| (*a)->next->next->next->next->index == i)
	{
		while ((*a)->index != i)
			rra(a, 0);
	}
	else
		while ((*a)->index != i)
			ra(a, 0);
	if (!sorted(a))
	{
		pb(a, b);
		sort_4(a, b, 1);
		pa(a, b);
	}
}

void	choose_sort(t_stack **a, t_stack **b)
{
	if (size_of_list(a) == 2 && !sorted(a))
		sa(a, 0);
	if (size_of_list(a) == 3 && !sorted(a))
		sort_3(a);
	if (size_of_list(a) == 4 && !sorted(a))
		sort_4(a, b, 0);
	if (size_of_list(a) == 5 && !sorted(a))
		sort_5(a, b, 0);
	if (size_of_list(a) > 5 && !sorted(a))
		radix_sort(a, b);
}
