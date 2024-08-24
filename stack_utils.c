/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontero <fmontero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 17:57:21 by fmontero          #+#    #+#             */
/*   Updated: 2024/08/24 15:06:42 by fmontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

void	head_to_bottom(t_stack *stack, t_ord *ord);

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
}

void	print_circular_list(t_stack *stack)
{
	int	size;

	printf("stack %c:\n", stack->name);
	if (stack->size == 0)
	{
		printf("vacio\n");
		return ;
	}
	size = stack->size;
	while (size--)
	{
		printf("%d\n", stack->head->value);
		stack->head = stack->head->next;
	}
}

void	print_stacks(t_stacks *stacks)
{
	print_circular_list(&stacks->a);
	print_circular_list(&stacks->b);
}
