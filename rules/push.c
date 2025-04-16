/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusimon <lusimon@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 13:47:45 by lusimon           #+#    #+#             */
/*   Updated: 2025/02/27 13:56:55 by lusimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push_a(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp;

	temp = *stack_b;
	if (*stack_b == NULL)
		return ;
	*stack_b = (*stack_b)->next;
	temp->next = *stack_a;
	*stack_a = temp;
}

void	pa(t_list **stack_a, t_list **stack_b)
{
	push_a(stack_a, stack_b);
	ft_printf("pa\n");
}

void	push_b(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp;
	t_list	*current;

	temp = *stack_a;
	current = *stack_a;
	if (*stack_a == NULL)
		return ;
	*stack_a = current->next;
	temp->next = *stack_b;
	*stack_b = temp;
}

void	pb(t_list **stack_a, t_list **stack_b)
{
	push_b(stack_a, stack_b);
	ft_printf("pb\n");
}
