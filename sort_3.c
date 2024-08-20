/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontero <fmontero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 18:05:21 by fmontero          #+#    #+#             */
/*   Updated: 2024/08/18 19:05:09 by fmontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

void    sort_3(t_stack *stack)
{
	if (stack->head->value < stack->head->next->value)
	{
		if(stack->head->next->value < stack->head->prev->value)
			;
		else
			rev(stack, 1);
	}
	else
	{
		if (stack->head->value < stack->head->prev->value)
			;
		else
			rot(stack, 1);
	}
	if (stack->head->value > stack->head->next->value)
		swap(stack, 1);
}

void	turk(t_stacks s)
{

}

