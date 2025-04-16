/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusimon <lusimon@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 14:05:51 by lusimon           #+#    #+#             */
/*   Updated: 2025/02/27 14:08:55 by lusimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	reverse_a(t_list **stack_a)
{
	t_list	*temp;
	t_list	*current;
	t_list	*save;

	temp = *stack_a;
	current = *stack_a;
	save = *stack_a;
	while (current->next->next != NULL)
		current = current->next;
	save = current->next;
	current->next = NULL;
	*stack_a = save;
	save->next = temp;
}

void	rra(t_list **stack_a)
{
	reverse_a(stack_a);
	ft_printf("rra\n");
}

void	reverse_b(t_list **stack_b)
{
	t_list	*temp;
	t_list	*current;
	t_list	*save;

	temp = *stack_b;
	current = *stack_b;
	save = *stack_b;
	while (current->next->next != NULL)
		current = current->next;
	save = current->next;
	current->next = NULL;
	*stack_b = save;
	save->next = temp;
}

void	rrb(t_list **stack_b)
{
	reverse_b(stack_b);
	ft_printf("rrb\n");
}

void	rrr(t_list **stack_a, t_list **stack_b)
{
	reverse_a(stack_a);
	reverse_b(stack_b);
	ft_printf("rrr\n");
}
