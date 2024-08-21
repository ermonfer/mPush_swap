/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ord.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontero <fmontero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 19:10:50 by fmontero          #+#    #+#             */
/*   Updated: 2024/08/21 20:07:28 by fmontero         ###   ########.fr       */
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

void	set_top(t_stack *stack, t_ord *ord)
{
	t_loc_node	cur;

	cur = (t_loc_node){stack->head, 0};
	ord->top = cur;
	while (++cur.loc < stack->size)
	{
		cur.node = cur.node->next;
		if (ord->gt(cur.node->value, ord->top.node->value))
			ord->top = cur;
	}
}
