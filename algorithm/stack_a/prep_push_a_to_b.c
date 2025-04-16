/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prep_push_a_to_b.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusimon <lusimon@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 16:33:57 by lusimon           #+#    #+#             */
/*   Updated: 2025/03/03 10:19:55 by lusimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	one_away_from_one_a(t_list **stack_a)
{
	t_list	*current;

	if (!stack_a || !(*stack_a))
		return ;
	current = *stack_a;
	while (current && !(current->selected_candidate))
		current = current->next;
	if (!current)
		return ;
	if (current->above_median == true)
	{
		ra(stack_a);
	}
	else
	{
		rra(stack_a);
	}
	define_median_index(stack_a);
}

void	one_away_from_one_b(t_list **stack_a, t_list **stack_b)
{
	t_list	*current;

	current = *stack_a;
	while (!(current->selected_candidate))
		current = current->next;
	if (current->target_node->above_median == true)
		rb(stack_b);
	else
		rrb(stack_b);
	define_median_index(stack_b);
}

void	both_away_from_one(t_list **stack_a, t_list **stack_b)
{
	t_list	*current;

	current = *stack_a;
	while (!(current->selected_candidate))
		current = current->next;
	if (current->above_median == true
		&& current->target_node->above_median == true)
		rr(stack_a, stack_b);
	else if (!(current->above_median == true
			&& current->target_node->above_median == true))
		rrr(stack_a, stack_b);
	else if (current->above_median == true)
	{
		ra(stack_a);
		rrb(stack_b);
	}
	else
	{
		rb(stack_b);
		rra(stack_a);
	}
	define_median_index(stack_a);
	define_median_index(stack_b);
}

void	prep_move_ab(t_list **stack_a, t_list **stack_b)
{
	t_list	*current;

	current = *stack_a;
	while (!(current->selected_candidate))
		current = current->next;
	while (current->index > 1 || current->target_node->index > 1)
	{
		if (current->index == 1 && current->target_node->index == 1)
			break ;
		else if (current->index != 1 && current->target_node->index != 1)
			both_away_from_one(stack_a, stack_b);
		else if (current->index != 1)
			one_away_from_one_a(stack_a);
		else if (current->target_node->index != 1)
		{
			one_away_from_one_b(stack_a, stack_b);
		}
		current = *stack_a;
		while (!(current->selected_candidate))
			current = current->next;
	}
	pb(stack_a, stack_b);
}
