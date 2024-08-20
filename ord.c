/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ord.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontero <fmontero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 19:10:50 by fmontero          #+#    #+#             */
/*   Updated: 2024/08/20 12:57:19 by fmontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

bool	greater(int a, int b)
{
	return (a > b);
}

bool	lower(int a, int b)
{
	return (a < b);
}

t_loc_node	get_max(t_stack *stack)
{
	t_loc_node	max;

	max.node = stack->peak.node->prev;
	max.loc = (stack->peak.loc - 1) % stack->size;
	return (max);
}

t_loc_node	get_min(t_stack *stack)
{
	return (stack->peak);
}

void	set_peak(t_stack *stack)
{
	t_loc_node	cur;

	cur = (t_loc_node){stack->head, 0};
	stack->peak = cur;
	while (++cur.loc < stack->size)
	{
		cur.node = cur.node->next;
		if (cur.node->value < stack->peak.node->value)
			stack->peak = cur;
	}
}
