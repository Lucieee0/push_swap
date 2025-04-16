/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusimon <lusimon@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 14:00:58 by lusimon           #+#    #+#             */
/*   Updated: 2025/02/27 14:05:02 by lusimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotate_a(t_list **stack_a)
{
	t_list	*temp;
	t_list	*current;

	temp = *stack_a;
	current = *stack_a;
	if (*stack_a == NULL)
		return ;
	*stack_a = (*stack_a)->next;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = current;
	current->next = NULL;
}

void	ra(t_list **stack_a)
{
	rotate_a(stack_a);
	ft_printf("ra\n");
}

void	rotate_b(t_list **stack_b)
{
	t_list	*temp;
	t_list	*current;

	temp = *stack_b;
	current = *stack_b;
	if (*stack_b == NULL)
		return ;
	*stack_b = (*stack_b)->next;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = current;
	current->next = NULL;
}

void	rb(t_list **stack_b)
{
	rotate_a(stack_b);
	ft_printf("rb\n");
}

void	rr(t_list **stack_a, t_list **stack_b)
{
	rotate_a(stack_a);
	rotate_b(stack_b);
	ft_printf("rr\n");
}
