/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 14:41:27 by beredzhe          #+#    #+#             */
/*   Updated: 2024/03/01 14:44:33 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	check(va_list args, const char *format, int *i)
{
	int	result;

	result = 0;
	*i = *i + 1;
	if (format[*i] == 'c')
		result += ft_print_c(args);
	else if (format[*i] == 's')
		result += ft_print_s(args);
	else if (format[*i] == 'i' || format[*i] == 'd')
		result += ft_print_i(args);
	else if (format[*i] == 'u')
		result += ft_print_u(args);
	else if (format[*i] == 'x' || format[*i] == 'X')
		result += ft_print_x(args, format[*i]);
	else if (format[*i] == 'p')
		result += ft_print_p(args);
	else if (format[*i] == '%')
	{
		if (write(1, "%", 1) == -1)
			return (-1);
		result++;
	}
	return (result);
}

int	checkformat(va_list args, const char *format, int *i, int *result)
{
	int	tmp;

	tmp = check(args, format, i);
	if (tmp == -1)
		return (-1);
	else
		*result += tmp;
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		result;

	result = 0;
	i = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			if (checkformat(args, format, &i, &result) == -1)
				return (-1);
		}
		else
		{
			if (write(1, &format[i], 1) == -1)
				return (-1);
			result++;
		}
		i++;
	}
	va_end(args);
	return (result);
}
