/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorrao- <ptorrao-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 13:26:24 by ptorrao-          #+#    #+#             */
/*   Updated: 2024/08/12 11:08:39 by ptorrao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	validate_matrix(char **mtr, int argc, t_stack **a, t_stack **b)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (mtr[i])
	{
		j = 0;
		while (mtr[i][j])
		{
			if ((mtr[i][0] == '-' || mtr[i][0] == '+') && j == 0)
				j++;
			if (mtr[i][j] == 0 || !ft_isdigit(mtr[i][j]) || j > 11)
			{
				ft_ultimate_free(mtr, a, b, argc);
				ft_printf("Error\n");
				exit(1);
			}
			j++;
		}
		i++;
	}
}

void	validate_min_max(char **mtr, int argc, t_stack **a, t_stack **b)
{
	t_stack	*temp;

	temp = *a;
	while (temp)
	{
		if (temp->data > INT_MAX || temp->data < INT_MIN)
		{
			ft_ultimate_free(mtr, a, b, argc);
			ft_printf("Error\n");
			exit(1);
		}
		temp = temp->next;
	}
}

void	validate_duplicates(char **mtr, int argc, t_stack **a, t_stack **b)
{
	t_stack	*temp1;
	t_stack	*temp2;

	temp1 = *a;
	while (temp1->next)
	{
		temp2 = temp1->next;
		while (temp2)
		{
			if (temp1->data == temp2->data)
			{
				ft_ultimate_free(mtr, a, b, argc);
				ft_printf("Error\n");
				exit(1);
			}
			temp2 = temp2->next;
		}
		temp1 = temp1->next;
	}
}

void	validate_list(char **mtr, int argc, t_stack **a, t_stack **b)
{
	validate_min_max(mtr, argc, a, b);
	validate_duplicates(mtr, argc, a, b);
}

void	insert_index(t_stack **a, int i)
{
	t_stack	*temp1;
	t_stack	*temp2;
	long	min;

	temp1 = *a;
	while (temp1)
	{
		min = INT_MAX;
		temp2 = *a;
		while (temp2)
		{
			if (temp2->data < min && temp2->index == -1)
				min = temp2->data;
			temp2 = temp2->next;
		}
		temp2 = *a;
		while (temp2)
		{
			if (temp2->data == min)
				temp2->index = i++;
			temp2 = temp2->next;
		}
		temp1 = temp1->next;
	}
}
