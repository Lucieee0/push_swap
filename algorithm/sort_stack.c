/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusimon <lusimon@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 16:35:41 by lusimon           #+#    #+#             */
/*   Updated: 2025/03/03 11:00:06 by lusimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

bool	smaller_index_top(t_list **stack_a)
{
	t_list	*current;

	current = *stack_a;
	while (current->next)
	{
		if (*(current->value) > *(current->next->value))
			return (0);
		current = current->next;
	}
	return (1);
}

void	min_on_top(t_list **stack_a)
{
	t_list	*current;

	current = find_min(stack_a);
	if (current->index > 1)
	{
		if (current->above_median == true)
			ra(stack_a);
		else
			rra(stack_a);
		define_median_index(stack_a);
	}
}

void	sort_stack(t_list **stack_a, t_list **stack_b)
{
	int	len_a;

	len_a = count_nodes(stack_a);
	if (len_a-- > 3 && !sorted(stack_a))
		pb(stack_a, stack_b);
	if (len_a-- > 3 && !sorted(stack_a))
		pb(stack_a, stack_b);
	while (len_a-- > 3 && !sorted(stack_a))
	{
		init_nodes_a(stack_a, stack_b);
		prep_move_ab(stack_a, stack_b);
	}
	sort_three(stack_a);
	while (*stack_b)
	{
		init_nodes_b(stack_a, stack_b);
		move_b_to_a(stack_a, stack_b);
	}
	while (!smaller_index_top(stack_a))
	{
		define_median_index(stack_a);
		min_on_top(stack_a);
	}
}
