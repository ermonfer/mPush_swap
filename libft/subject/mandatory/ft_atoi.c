/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontero <fmontero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 13:09:34 by fmontero          #+#    #+#             */
/*   Updated: 2024/09/10 20:14:31 by fmontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long overflow(int sign);

int	ft_atoi(const char *str)
{
	int	sign;
	int	result;
	int	digit;
	int	cutoff;
	int	cutlim;

	while (ft_isspace(*str))
		str++;
	sign = 1;
	if (*str == '-' || *str == '+')
	{
		if (*str++ == '-')
			sign = -1;
	}
	cutoff = (sign == 1) * (INT_MAX / 10) - (sign == -1) * (INT_MIN / 10);
	cutlim = (sign == 1) * (INT_MAX % 10) - (sign == -1) * (INT_MIN % 10);
	result = 0;
	while (ft_isdigit(*str))
	{
		digit = *str++ - '0';
		if (result > cutoff || (result == cutoff && digit == cutlim))
		return(overflow(sign));
	}
		result = result * 10 + (*str++ - '0');
	return (result * sign);
}

static long	overflow(int sign)
{
	errno = ERANGE;
    if (sign == -1)
		return (INT_MAX);
	else
		return (INT_MIN);
}