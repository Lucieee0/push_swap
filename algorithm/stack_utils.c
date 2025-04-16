/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusimon <lusimon@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 16:35:53 by lusimon           #+#    #+#             */
/*   Updated: 2025/02/27 20:46:09 by lusimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	sorted(t_list **stack_a)
{
	t_list	*current;

	current = *stack_a;
	if (!(*stack_a))
		return (1);
	while (current->next != NULL)
	{
		if (*(current->value) > *(current->next->value))
			return (0);
		current = current->next;
	}
	return (1);
}

int	count_nodes(t_list **stack)
{
	t_list	*current;
	int		count;

	current = *stack;
	count = 1;
	while (current->next != NULL)
	{
		count++;
		current = current->next;
	}
	return (count);
}
