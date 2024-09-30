/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rots_movs_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontero <fmontero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 10:46:39 by fmontero          #+#    #+#             */
/*   Updated: 2024/09/30 10:46:40 by fmontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

void	rot(t_stack *stack, bool print)
{
	stack->head = stack->head->next;
	if (print)
		write(1, (char []){'r', stack->name, '\n'}, 3);
}

void	rrot(t_stacks *stacks, bool print)
{
	rot(&stacks->a, false);
	rot(&stacks->b, false);
	if (print)
		write(1, (char []){'r', 'r', '\n'}, 3);
}

void	rev(t_stack *stack, bool print)
{
	stack->head = stack->head->prev;
	if (print)
		write(1, (char []){'r', 'r', stack->name, '\n'}, 4);
}

void	rrev(t_stacks *stacks, bool print)
{
	rev(&stacks->a, false);
	rev(&stacks->b, false);
	if (print)
		write(1, (char []){'r', 'r', 'r', '\n'}, 4);
}
