/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusimon <lusimon@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 14:46:30 by lusimon           #+#    #+#             */
/*   Updated: 2025/03/06 12:57:59 by lusimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_list **stack)
{
	t_list	*next;
	t_list	*current;

	if (!stack)
		return ;
	current = *stack;
	while (current)
	{
		next = current->next;
		free(current->value);
		free(current);
		current = next;
	}
	*stack = NULL;
}
// t_list	*current;

// current = stack_a;
// while (current)
// {
// 	printf("%i\n", *(current->value));
// 	current = current->next;
// }

int	main(int argc, char *argv[])
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc >= 2 && (*argv[1] != '\0'))
	{
		if (argc == 2)
			stack_a = ft_handle(&argv[1], (argc - 1));
		else
			stack_a = ft_handle(argv, (argc - 1));
		if (!(stack_a))
		{
			ft_printf("Error\n");
			return (0);
		}
		if (count_nodes(&stack_a) > 1 && (!(sorted(&stack_a))))
			sort_stack(&stack_a, &stack_b);
	}
	free_stack(&stack_a);
	return (0);
}
