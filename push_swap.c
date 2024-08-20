/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorrao- <ptorrao-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 12:25:39 by ptorrao-          #+#    #+#             */
/*   Updated: 2024/08/12 12:29:56 by ptorrao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**split_args(int argc, char **argv, t_stack **a, t_stack **b)
{
	char	**mtr;

	if (argc < 2)
	{
		free(a);
		free(b);
		exit(1);
	}
	if (argc == 2 && argv[1])
	{
		mtr = ft_split(argv[1], ' ');
		if (!mtr)
		{
			ft_printf("Error\n");
			exit(1);
		}
	}
	if (argc > 2)
		mtr = ++argv;
	return (mtr);
}

void	create_list(char **mtr, t_stack **a, t_stack **b)
{
	int		i;
	t_stack	*temp;

	i = 0;
	if (!mtr[0])
	{
		free(a);
		free(b);
		ft_free_mtr(mtr);
		exit(1);
	}
	*a = (t_stack *)malloc(sizeof(t_stack));
	(*a)->data = ft_atol(mtr[i]);
	(*a)->index = -1;
	temp = *a;
	while (mtr[++i])
	{
		temp->next = (t_stack *)malloc(sizeof(t_stack));
		temp = temp->next;
		temp->data = ft_atol(mtr[i]);
		temp->index = -1;
		temp->next = NULL;
	}
}

int	main(int argc, char	**argv)
{
	t_stack	**a;
	t_stack	**b;
	char	**mtr;

	a = (t_stack **)malloc(sizeof(t_stack));
	b = (t_stack **)malloc(sizeof(t_stack));
	*b = NULL;
	mtr = split_args(argc, argv, a, b);
	validate_matrix(mtr, argc, a, b);
	create_list(mtr, a, b);
	validate_list(mtr, argc, a, b);
	insert_index(a, 0);
	choose_sort(a, b);
	ft_ultimate_free(mtr, a, b, argc);
	return (0);
}
