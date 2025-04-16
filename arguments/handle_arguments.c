/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_arguments.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusimon <lusimon@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 17:53:01 by lusimon           #+#    #+#             */
/*   Updated: 2025/03/04 18:19:14 by lusimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	free_array_of_string(char **s)
{
	int	i;

	i = 0;
	while (s[i] != NULL)
	{
		free(s[i]);
		i++;
	}
}

t_list	*handle_split(char **string)
{
	int		i;
	t_list	*lst;
	t_list	*new_node;
	int		*number;
	char	**resultat;

	i = 0;
	lst = NULL;
	new_node = NULL;
	if (!(check_unwanted_characters_split(*string)))
		return (NULL);
	resultat = ft_split(string[0]);
	if (!resultat || !*resultat || !check_arguments_split(resultat))
		return (NULL);
	while (resultat[i] != NULL)
	{
		number = malloc(sizeof(int));
		if (!number)
			return (NULL);
		*number = atoi(resultat[i]);
		new_node = ft_lstnew(number);
		ft_lstadd_back(&lst, new_node);
		i++;
	}
	return (lst);
}

t_list	*handle_argv(char **string, int nbr_arguments)
{
	int		i;
	t_list	*lst;
	t_list	*new_node;
	int		*number;

	i = 1;
	lst = NULL;
	new_node = NULL;
	if (!(check_arguments_argv(string, nbr_arguments)))
		return (NULL);
	while (i <= nbr_arguments)
	{
		number = malloc(sizeof(int));
		if (!number)
			return (NULL);
		*number = atoi(string[i]);
		new_node = ft_lstnew(number);
		ft_lstadd_back(&lst, new_node);
		i++;
	}
	return (lst);
}

// t_list	*handle_argv(char **string, int nbr_arguments)
// {
// 	int		i;
// 	t_list	*lst;
// 	t_list	*new_node;
// 	int		*number;

// 	i = 1;
// 	lst = NULL;
// 	new_node = NULL;
// 	if (!(check_arguments_argv(string, nbr_arguments)))
// 		return (NULL);
// 	while (i <= nbr_arguments)
// 	{
// 		number = malloc(sizeof(int));
// 		if (!number)
// 			return (NULL);
// 		*number = atoi(string[i]);
// 		new_node = ft_lstnew(number);
// 		ft_lstadd_back(&lst, new_node);
// 		i++;
// 	}
// 	return (lst);
// }

//we look for duplicates in our linked_list
//Do we have two nodes with the same value?

int	check_duplicate(t_list **stack)
{
	t_list	*current;
	t_list	*compare;

	current = *stack;
	compare = *stack;
	if (!stack && !(*stack))
		return (0);
	while (current != NULL)
	{
		compare = current->next;
		while (compare != NULL)
		{
			if (*(compare->value) == *(current->value))
			{
				return (0);
			}
			compare = compare->next;
		}
		current = current->next;
	}
	return (1);
}

//nbr_arguments is equal to argc - 1

t_list	*ft_handle(char **string, int nbr_arguments)
{
	t_list	*head;

	head = NULL;
	if (nbr_arguments == 1)
	{
		head = handle_split(string);
	}
	else
	{
		head = handle_argv(string, nbr_arguments);
	}
	if (!(check_duplicate(&head)))
		return (NULL);
	return (head);
}
