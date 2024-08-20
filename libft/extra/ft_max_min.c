/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_max_min.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontero <fmontero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 11:30:50 by fmontero          #+#    #+#             */
/*   Updated: 2024/08/20 20:56:24 by fmontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_maxint(int a, int b)
{
	if (a < b)
		return (b);
	return (a);
}

int	ft_minint(int a, int b)
{
	if (a > b)
		return (b);
	return (a);
}
