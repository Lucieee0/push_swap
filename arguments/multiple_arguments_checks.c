/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiple_arguments_checks.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusimon <lusimon@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 15:03:21 by lusimon           #+#    #+#             */
/*   Updated: 2025/02/28 13:39:16 by lusimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//case when the arguments are multiple strings
//j = 1, because argv[1] is the first argument we care about
//argv[1] < (argc - 1) -> first iteration

int	check_unwanted_characters_argv(char **str, int nbr_arguments)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (j < (nbr_arguments + 1))
	{
		i = 0;
		while (str[j][i] != '\0')
		{
			if (!((str[j][i] >= '0' && str[j][i] <= '9')
				|| str[j][i] == '-' || str[j][i] == '+' || str[j][i] == ' '))
				return (0);
			i++;
		}
		j++;
	}
	return (1);
}

int	check_sign_digits_argv(char **str, int nbr_arguments)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (j < (nbr_arguments + 1))
	{
		i = 0;
		if ((str[j][i] >= '0' && str[j][i] <= '9')
			|| ((str[j][i] == '-' || str[j][i] == '+')
				&& (str[j][i + 1] >= '0' && str[j][i + 1] <= '9')))
			i++;
		else
			return (0);
		while (str[j][i] != '\0')
		{
			if (!(str[j][i] >= '0' && str[j][i] <= '9'))
				return (0);
			i++;
		}
		j++;
	}
	return (1);
}

int	count_digits_argv(char **str, int nbr_arguments)
{
	int	i;
	int	j;
	int	digit_count;

	i = 0;
	j = 1;
	digit_count = 0;
	while (j < (nbr_arguments + 1))
	{
		i = 0;
		digit_count = 0;
		if (str[j][i] >= '0' && str[j][i] <= '9')
			i++;
		while (str[j][i] != '\0')
		{
			i++;
			digit_count++;
		}
		if (digit_count > 11)
			return (0);
		j++;
	}
	return (1);
}

//i = 1, because we start at argv[1]
//argv[1] < (argc - 1) -> first iteration

int	within_integer_limits_argv(char **str, int nbr_arguments)
{
	long	num;
	int		i;

	i = 1;
	while (i < (nbr_arguments + 1))
	{
		num = 0;
		num = atol(str[i]);
		if (num > 2147483647 || num < -2147483648)
			return (0);
		i++;
	}
	return (1);
}

int	check_arguments_argv(char **str, int nbr_arguments)
{
	int	checker_1;
	int	checker_2;
	int	checker_3;
	int	checker_4;

	checker_1 = 0;
	checker_2 = 0;
	checker_3 = 0;
	checker_4 = 0;
	checker_1 = check_sign_digits_argv(str, nbr_arguments);
	checker_2 = count_digits_argv(str, nbr_arguments);
	checker_3 = within_integer_limits_argv(str, nbr_arguments);
	checker_4 = check_unwanted_characters_argv(str, nbr_arguments);
	if ((checker_1 + checker_2 + checker_3 + checker_4) < 4)
		return (0);
	return (1);
}
