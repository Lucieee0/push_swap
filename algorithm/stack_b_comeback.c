/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_b_comeback.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusimon <lusimon@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 16:35:47 by lusimon           #+#    #+#             */
/*   Updated: 2025/02/27 20:44:22 by lusimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	find_target_comeback(t_list *stack_a, t_list *stack_b)
{
	t_list	*a;
	t_list	*target_node;
	int		best_match;

	target_node = NULL;
	while (stack_b)
	{
		best_match = 2147483647;
		a = stack_a;
		while (a)
		{
			if (*(a->value) > *(stack_b->value) && *(a->value) < best_match)
			{
				best_match = *(a->value);
				target_node = a;
			}
			a = a->next;
		}
		if (best_match == 2147483647)
			stack_b->target_node = find_min(&stack_a);
		else
			stack_b->target_node = target_node;
		stack_b = stack_b->next;
	}
}

void	init_nodes_b(t_list **stack_a, t_list **stack_b)
{
	define_median_index(stack_a);
	define_median_index(stack_b);
	define_rank(*stack_a);
	define_rank(*stack_b);
	find_target_comeback(*stack_a, *stack_b);
}

void	sort_before_come_back(t_list **stack_a, t_list **stack_b)
{
	t_list	*current;

	current = *stack_b;
	if (current->target_node->above_median == true)
		ra(stack_a);
	else
		rra(stack_a);
	define_median_index(stack_a);
}

void	move_b_to_a(t_list **stack_a, t_list **stack_b)
{
	t_list	*current;

	current = *stack_b;
	while (current->target_node->index > 1)
	{
		sort_before_come_back(stack_a, stack_b);
	}
	pa(stack_a, stack_b);
}
