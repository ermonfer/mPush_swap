/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_max_min.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontero <fmontero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 11:30:50 by fmontero          #+#    #+#             */
/*   Updated: 2024/08/14 11:57:19 by fmontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int maxint(int a, int b)
{
    if (a<b)
        return (b);
    return (a);
}

int minint(int a, int b)
{
    if (a>b)
        return (b);
    return (a);
}