/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_target.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusimon <lusimon@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 16:33:51 by lusimon           #+#    #+#             */
/*   Updated: 2025/02/27 20:15:35 by lusimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	find_target(t_list *stack_a, t_list *stack_b)
{
	t_list	*b;
	t_list	*target_node;
	int		best_match;

	target_node = NULL;
	while (stack_a)
	{
		best_match = -2147483648;
		b = stack_b;
		while (b)
		{
			if (*(b->value) < *(stack_a->value) && *(b->value) > best_match)
			{
				best_match = *(b->value);
				target_node = b;
			}
			b = b->next;
		}
		if (best_match == -2147483648)
			stack_a->target_node = find_max(&stack_b);
		else
			stack_a->target_node = target_node;
		stack_a = stack_a->next;
	}
}

void	push_cost(t_list **stack_a, t_list **stack_b)
{
	int		len_a;
	int		len_b;
	t_list	*current;

	current = *stack_a;
	len_a = count_nodes(stack_a);
	len_b = count_nodes(stack_b);
	while (current)
	{
		current->push_cost = current->index;
		if (!(current->above_median))
			current->push_cost = (len_a - (current->index) + 1);
		if (current->target_node->above_median)
			current->push_cost += current->target_node->index;
		else
			current->push_cost += (len_b - (current->target_node->index) + 1);
		current = current->next;
	}
}

void	selected_candidate(t_list **stack_a)
{
	int		cheapest_cost;
	t_list	*current;
	t_list	*selected_candidate;

	current = *stack_a;
	if (!(*stack_a))
		return ;
	cheapest_cost = 2147483647;
	while (current)
	{
		if (current->push_cost < cheapest_cost)
		{
			cheapest_cost = current->push_cost;
			selected_candidate = current;
		}
		current = current->next;
	}
	selected_candidate->selected_candidate = true;
}

t_list	*find_selected_candidate(t_list **stack_a)
{
	t_list	*current;

	selected_candidate(stack_a);
	current = *stack_a;
	while (current)
	{
		if (current->selected_candidate == true)
			return (current);
		else
			current = current->next;
	}
	return (NULL);
}

void	init_nodes_a(t_list **stack_a, t_list **stack_b)
{
	define_median_index(stack_a);
	define_median_index(stack_b);
	define_rank(*stack_a);
	define_rank(*stack_b);
	find_target(*stack_a, *stack_b);
	push_cost(stack_a, stack_b);
	find_selected_candidate(stack_a);
}
