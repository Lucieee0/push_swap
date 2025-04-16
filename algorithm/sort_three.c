/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusimon <lusimon@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 17:19:08 by lusimon           #+#    #+#             */
/*   Updated: 2025/02/27 20:27:09 by lusimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_three(t_list **stack_a)
{
	t_list	*biggest_node;
	t_list	*current;

	biggest_node = find_max(stack_a);
	current = *stack_a;
	if (biggest_node == current)
	{
		ra(stack_a);
	}
	else if (current->next == biggest_node)
	{
		rra(stack_a);
	}
	current = *stack_a;
	if ((*(current->value)) > (*(current->next->value)))
	{
		sa(stack_a);
	}
}
