/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorrao- <ptorrao-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 16:46:03 by ptorrao-          #+#    #+#             */
/*   Updated: 2024/08/12 11:06:22 by ptorrao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_free_mtr(char **str)
{
	int	j;

	j = -1;
	while (str[++j])
		free(str[j]);
	free(str);
}

void	ft_free_stacks(t_stack **a, t_stack **b)
{
	t_stack	*temp;

	temp = *a;
	while (temp)
	{
		temp = (*a)->next;
		free(*a);
		*a = temp;
	}
	free(a);
	temp = *b;
	while (temp)
	{
		temp = (*b)->next;
		free(*b);
		*b = temp;
	}
	free(b);
}

void	ft_ultimate_free(char **str, t_stack **a, t_stack **b, int argc)
{
	if (argc == 2 && str)
		ft_free_mtr(str);
	ft_free_stacks(a, b);
}

int	size_of_list(t_stack **a)
{
	int		i;
	t_stack	*temp;

	i = 0;
	temp = *a;
	while (temp)
	{
		i++;
		temp = temp->next;
	}
	return (i);
}

int	sorted(t_stack **a)
{
	t_stack	*temp;

	temp = *a;
	while (temp->next)
	{
		if (temp->index > temp->next->index)
			return (0);
		temp = temp->next;
	}
	return (1);
}
