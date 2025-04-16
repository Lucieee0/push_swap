/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusimon <lusimon@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 14:30:10 by lusimon           #+#    #+#             */
/*   Updated: 2025/03/03 10:22:53 by lusimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_atoi(const char *str)
{
	int	integer;
	int	sign;

	integer = 0;
	sign = 1;
	while (*str == 32 || (*str >= 9 && *str <= 13))
	{
		str++;
	}
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
		{
			sign = -sign;
		}
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		integer = integer * 10 + (*str - 48);
		str++;
	}
	return (integer * sign);
}

int	print_char(int c)
{
	if (write(1, &c, 1) == -1)
		return (-1);
	return (1);
}

int	ft_printf(const char *format, ...)
{
	va_list		ap;
	int			count;
	int			i;

	count = 0;
	i = 0;
	va_start(ap, format);
	while (format[i] != '\0')
	{
		count += print_char((int)format[i]);
		if (count < 0)
			return (-1);
		i++;
	}
	va_end(ap);
	return (count);
}

void	*ft_calloc(size_t count, size_t size)
{
	void			*table;
	size_t			i;
	size_t			total_size;
	unsigned char	*p;

	i = 0;
	total_size = count * size;
	table = malloc(total_size);
	if (table == NULL)
	{
		return (NULL);
	}
	p = table;
	while (i < total_size)
	{
		p[i] = 0;
		i++;
	}
	return (table);
}
