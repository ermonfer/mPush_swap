/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_signal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontero <fmontero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 21:14:14 by fmontero          #+#    #+#             */
/*   Updated: 2024/09/19 21:14:33 by fmontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int overflow(int *out_of_range, int sign);

int	ft_atoi_signal(const char *str, int *out_of_range)
{
	int	sign;
	int	result;
	int	digit;
	int	cutoff;
	int	cutlim;

	*out_of_range = 0;
	while (ft_isspace(*str))
		str++;
	sign = 1;
	if (*str == '-' || *str == '+')
		sign -= 2 * (*str++ ==  '-'); 
	cutoff = (sign == 1) * (INT_MAX / 10) - (sign == -1) * (INT_MIN / 10);
	cutlim = (sign == 1) * (INT_MAX % 10) - (sign == -1) * (INT_MIN % 10);
	result = 0;
	while (ft_isdigit(*str))
	{
		digit = *str++ - '0';
		if (result > cutoff || (result == cutoff && digit == cutlim))
			return(overflow(out_of_range, sign));
	}
		result = result * 10 + (*str++ - '0');
	return (result * sign);
}

static int	overflow(int *out_of_range, int sign)
{
	*out_of_range = 1; 
    if (sign == -1)
		return (INT_MIN);
	return (INT_MAX);
}