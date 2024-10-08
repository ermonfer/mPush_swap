/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontero <fmontero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 17:57:21 by fmontero          #+#    #+#             */
/*   Updated: 2024/10/02 08:35:28 by fmontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

void		head_to_bottom(t_stack *stack, t_ord *ord);
t_stacks	*init_stacks(int arr[], int nbs);
bool		stack_sorted(t_stack *stack, t_ord *ord, bool relative);

t_stacks	*init_stacks(int arr[], int nbs)
{
	t_stacks	*stacks;

	stacks = malloc(sizeof (t_stacks) + nbs * sizeof (t_node));
	if (stacks == NULL)
		return (NULL);
	stacks->a.size = nbs;
	stacks->a.head = stacks->nodes;
	stacks->a.name = 'a';
	stacks->b.size = 0;
	stacks->b.head = NULL;
	stacks->b.name = 'b';
	while (--nbs)
	{
		stacks->a.head->value = *(arr++);
		stacks->a.head->next = stacks->a.head + 1;
		(stacks->a.head + 1)->prev = stacks->a.head;
		stacks->a.head++;
	}
	stacks->a.head->value = *arr;
	stacks->a.head->next = stacks->nodes;
	stacks->nodes->prev = stacks->a.head;
	stacks->a.head = stacks->nodes;
	return (stacks);
}

void	head_to_bottom(t_stack *stack, t_ord *ord)
{
	int	rots;

	rots = (ord->top.loc + 1) % stack->size;
	if (rots < stack->size - rots)
	{
		while (rots--)
			write(1, (char []){'r', stack->name, '\n'}, 3);
	}
	else
	{
		rots = stack->size - rots;
		while (rots--)
			write(1, (char []){'r', 'r', stack->name, '\n'}, 4);
	}
	stack->head = ord->top.node->next;
	ord->top.loc = stack->size - 1;
}

bool	stack_sorted(t_stack *stack, t_ord *ord, bool relative)
{
	t_node	*cur;
	int		i;

	if (relative)
	{
		set_top(stack, ord);
		cur = ord->top.node->next;
	}
	else
		cur = stack->head;
	i = stack->size;
	while (--i)
	{
		if (ord->gt(cur->value, cur->next->value))
			return (0);
		cur = cur->next;
	}
	return (1);
}
