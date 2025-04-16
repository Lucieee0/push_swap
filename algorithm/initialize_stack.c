/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusimon <lusimon@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 16:35:28 by lusimon           #+#    #+#             */
/*   Updated: 2025/02/27 20:20:38 by lusimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_list	*find_min(t_list **stack)
{
	int		min;
	t_list	*min_node;
	t_list	*current;

	current = *stack;
	if (!(*stack))
		return (NULL);
	min = 2147483647;
	while (current)
	{
		if (*(current->value) < min)
		{
			min = *(current->value);
			min_node = current;
		}
		current = current->next;
	}
	return (min_node);
}

//this function will define the position of the node in the stack
//first we assign the rank to the node that has the highest value
//the rank is equal to the total number of nodes
//then we find for the node that has the second biggest value
//the rank will then be (number of nodes - 1)

int	assign_rank_to_max(t_list **stack)
{
	int		total_nodes;
	int		new_max;
	t_list	*current;

	total_nodes = 0;
	new_max = 0;
	current = find_max(stack);
	new_max = *(current->value);
	current->rank = total_nodes;
	return (new_max);
}

void	define_rank(t_list *stack)
{
	t_list	*beginning;
	int		total_nodes;
	int		new_max;
	int		max;

	total_nodes = count_nodes(&stack);
	beginning = stack;
	new_max = assign_rank_to_max(&stack);
	while (total_nodes > 0)
	{
		max = -2147483648;
		while (stack)
		{
			if ((*(stack->value) > max) && (*(stack->value) < new_max))
			{
				max = *(stack->value);
				stack->rank = total_nodes;
			}
			stack = stack->next;
		}
		new_max = max;
		stack = beginning;
		total_nodes--;
	}
}

t_list	*find_max(t_list **stack)
{
	int		max;
	t_list	*max_node;
	t_list	*current;

	max_node = NULL;
	current = *stack;
	if (!(*stack))
		return (NULL);
	max = -2147483648;
	while (current)
	{
		if (*(current->value) > max)
		{
			max = *(current->value);
			max_node = current;
		}
		current = current->next;
	}
	return (max_node);
}

void	define_median_index(t_list **stack)
{
	int		i;
	int		median;
	t_list	*current;

	current = *stack;
	i = 1;
	if (!(*stack))
		return ;
	median = (count_nodes(stack)) / 2;
	while (current)
	{
		current->index = i;
		if (i <= median)
			current->above_median = true;
		else
			current->above_median = false;
		current = current->next;
		i++;
	}
}
