/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusimon <lusimon@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 13:45:15 by lusimon           #+#    #+#             */
/*   Updated: 2025/02/27 14:00:23 by lusimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap_a(t_list **stack_a)
{
	t_list	*first;
	t_list	*second;
	int		temp;

	first = *stack_a;
	second = *stack_a;
	temp = 0;
	if (!stack_a || !(*stack_a) || (first->next == NULL))
		return ;
	second = second->next;
	temp = (*(first->value));
	*(first->value) = *(second->value);
	*(second->value) = temp;
}

void	sa(t_list **stack_a)
{
	swap_a(stack_a);
	ft_printf("sa\n");
}

void	swap_b(t_list **stack_b)
{
	t_list	*first;
	t_list	*second;
	int		temp;

	first = *stack_b;
	second = *stack_b;
	temp = 0;
	if (!stack_b || !(*stack_b) || (first->next == NULL))
		return ;
	second = second->next;
	temp = (*(first->value));
	*(first->value) = *(second->value);
	*(second->value) = temp;
}

void	sb(t_list **stack_b)
{
	swap_b(stack_b);
	ft_printf("sb\n");
}

void	ss(t_list **stack_a, t_list **stack_b)
{
	swap_a(stack_a);
	swap_b(stack_b);
	ft_printf("ss\n");
}
//deleted swap_ab don't need it