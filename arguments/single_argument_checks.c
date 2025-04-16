/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   single_argument_checks.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusimon <lusimon@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 14:56:05 by lusimon           #+#    #+#             */
/*   Updated: 2025/03/04 18:25:23 by lusimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//look for -, +, and digits, won't let pass other values
//case when the arguments are one long string

int	check_unwanted_characters_split(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!((str[i] >= '0' && str[i] <= '9')
				|| str[i] == '-' || str[i] == '+' || str[i] == ' '))
			return (0);
		i++;
	}
	return (1);
}

int	check_sign_digits_split(char **str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[j] != NULL)
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
			if (str[j][i] < '0' && str[j][i] > '9')
				return (0);
			i++;
		}
		j++;
	}
	return (1);
}
//eliminate too big or too small integers

int	count_digits_split(char **str)
{
	int	i;
	int	j;
	int	digit_count;

	i = 0;
	j = 0;
	digit_count = 0;
	j = 0;
	while (str[j] != NULL)
	{
		i = 0;
		digit_count = 0;
		if (str[j][i] == '-' || str[j][i] == '+')
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

int	within_integer_limits_split(char **str)
{
	long	num;
	int		i;

	i = 0;
	while (str[i] != NULL)
	{
		num = atol(str[i]);
		if (num > 2147483647 || num < -2147483648)
			return (0);
		i++;
	}
	return (1);
}

int	check_arguments_split(char **str)
{
	int	checker_1;
	int	checker_2;
	int	checker_3;

	checker_1 = 0;
	checker_2 = 0;
	checker_3 = 0;
	checker_1 = check_sign_digits_split(str);
	checker_2 = count_digits_split(str);
	checker_3 = within_integer_limits_split(str);
	if ((checker_1 + checker_2 + checker_3) < 3)
		return (0);
	return (1);
}
