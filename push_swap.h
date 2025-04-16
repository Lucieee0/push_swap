/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusimon <lusimon@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 14:47:48 by lusimon           #+#    #+#             */
/*   Updated: 2025/03/04 17:51:34 by lusimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <limits.h>
# include <stdio.h>
# include <stdbool.h>
# include <unistd.h>
# include <stdarg.h>

typedef struct s_list
{
	int				*value;
	int				rank;
	int				index;
	int				push_cost;
	bool			above_median;
	bool			selected_candidate;
	struct s_list	*target_node;
	struct s_list	*next;
}	t_list;

//Algorithm
//stack_a
//define_target.c
void	find_target(t_list *stack_a, t_list *stack_b);
void	push_cost(t_list **stack_a, t_list **stack_b);
void	selected_candidate(t_list **stack_a);
t_list	*find_selected_candidate(t_list **stack_a);
void	init_nodes_a(t_list **stack_a, t_list **stack_b);
//prep_push_a_to_b.c
void	one_away_from_one_a(t_list **stack_a);
void	one_away_from_one_b(t_list **stack_a, t_list **stack_b);
void	both_away_from_one(t_list **stack_a, t_list **stack_b);
void	prep_move_ab(t_list **stack_a, t_list **stack_b);
//initialize_stack.c
t_list	*find_min(t_list **stack);
int		assign_rank_to_max(t_list **stack);
void	define_rank(t_list *stack);
t_list	*find_max(t_list **stack);
void	define_median_index(t_list **stack);
//sort_stack.c
bool	smaller_index_top(t_list **stack_a);
void	min_on_top(t_list **stack_a);
void	sort_stack(t_list **stack_a, t_list **stack_b);
//sort_three.c
void	sort_three(t_list **stack_a);
//stack_b_comeback.c
void	find_target_comeback(t_list *stack_a, t_list *stack_b);
void	init_nodes_b(t_list **stack_a, t_list **stack_b);
void	sort_before_come_back(t_list **stack_a, t_list **stack_b);
void	move_b_to_a(t_list **stack_a, t_list **stack_b);
//stack_utils.c
int		sorted(t_list **stack_a);
int		count_nodes(t_list **stack);

//arguments
//multiple_arguments_checks
int		check_unwanted_characters_argv(char **str, int nbr_arguments);
int		check_sign_digits_argv(char **str, int nbr_arguments);
int		count_digits_argv(char **str, int nbr_arguments);
int		within_integer_limits_argv(char **str, int nbr_arguments);
int		check_arguments_argv(char **str, int nbr_arguments);
//single_argument_checks
int		check_unwanted_characters_split(char *str);
int		check_sign_digits_split(char **str);
int		count_digits_split(char **str);
int		within_integer_limits_split(char **str);
int		check_arguments_split(char **str);
//handle_arguments
void	free_array_of_string(char **s);
t_list	*handle_split(char **string);
t_list	*handle_argv(char **string, int nbr_arguments);
int		check_duplicate(t_list **stack);
t_list	*ft_handle(char **string, int nbr_arguments);

//libft
//bonus_libft
t_list	*ft_lstnew(int *value);
void	ft_lstadd_back(t_list **lst, t_list *new);
//ft_split
char	*substring(char *s, int start, int end);
void	*free_substring(char **ss, int position);
char	**ft_initialize(char *str);
char	**ft_split(char *str);
//libft
int		ft_atoi(const char *str);
int		print_char(int c);
int		ft_printf(const char *format, ...);
void	*ft_calloc(size_t count, size_t size);

//rules.c
//swap.c
void	swap_a(t_list **stack_a);
void	sa(t_list **stack_a);
void	swap_b(t_list **stack_b);
void	sb(t_list **stack_b);
void	ss(t_list **stack_a, t_list **stack_b);
//push.c
void	push_a(t_list **stack_a, t_list **stack_b);
void	pa(t_list **stack_a, t_list **stack_b);
void	push_b(t_list **stack_a, t_list **stack_b);
void	pb(t_list **stack_a, t_list **stack_b);
//rotate.c
void	rotate_a(t_list **stack_a);
void	ra(t_list **stack_a);
void	rotate_b(t_list **stack_b);
void	rb(t_list **stack_b);
void	rr(t_list **stack_a, t_list **stack_b);
//reverse_rotate.c
void	reverse_a(t_list **stack_a);
void	rra(t_list **stack_a);
void	reverse_b(t_list **stack_b);
void	rrb(t_list **stack_b);
void	rrr(t_list **stack_a, t_list **stack_b);

#endif