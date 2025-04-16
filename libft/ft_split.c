/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusimon <lusimon@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 15:58:14 by lusimon           #+#    #+#             */
/*   Updated: 2025/03/04 18:27:40 by lusimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

char	*substring(char *s, int start, int end)
{
	char	*sub;
	int		i;
	int		j;

	i = 0;
	j = 0;
	sub = (char *)malloc(sizeof(char) * (end - start + 1));
	if (!sub)
		return (NULL);
	while (s[i] != '\0')
	{
		if (s[i] == s[start])
		{
			while (start <= end)
			{
				sub[j] = s[start];
				j++;
				start++;
			}
		}
		i++;
	}
	sub[j] = '\0';
	return (sub);
}

void	*free_substring(char **ss, int position)
{
	int	i;

	i = 0;
	while (i <= position)
	{
		free(ss[i]);
		i++;
	}
	free(ss);
	return (NULL);
}

char	**ft_initialize(char *str)
{
	char	**result;
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (str[i] == ' ')
			count++;
		i++;
	}
	result = (char **)malloc(sizeof(char *) * (count + 2));
	if (!result)
		return (NULL);
	return (result);
}

char	**ft_split(char *str)
{
	int		i;
	int		j;
	int		start;
	char	**result;

	i = 0;
	j = 0;
	result = ft_initialize(str);
	while (str[i] != '\0')
	{
		while (str[i] == ' ')
			i++;
		if (str[i] == '\0')
			break ;
		start = i;
		while ((str[i] >= '0' && str[i] <= '9')
			|| (str[i] == '-' || str[i] == '+'))
			i++;
		result[j] = substring(str, start, i);
		if (!result)
			free_substring(result, j);
		j++;
	}
	result[j] = NULL;
	return (result);
}
