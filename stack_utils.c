/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontero <fmontero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 17:57:21 by fmontero          #+#    #+#             */
/*   Updated: 2024/08/22 18:25:18 by fmontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

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

void print_circular_list(t_stack *stack)
{
	printf("stack %c:\n",  stack->name);
	if (stack->size == 0)
	{
		printf("vacio\n");
		return;
	}
	int	size = stack->size;
	while (size--)
	{
		printf("%d\n", stack->head->value);
		stack->head = stack->head->next;
	}
}

void print_stacks(t_stacks *stacks)
{
	print_circular_list(&stacks->a);
	print_circular_list(&stacks->b);
}

// int main(void)
// {
// 	int array[] = {10, 212, 43, -9};
// 	t_stacks *stacks = init_stacks(array, 4);
// 	printf("size de a: %d\nsize de b: %d\n", stacks->a.size, stacks->b.size);
// 	print_stacks(stacks);
// 	push(&stacks->a, &stacks->b, true);
// 	push(&stacks->a, &stacks->b, true);
// 	printf("size de a: %d\nsize de b: %d\n", stacks->a.size, stacks->b.size);
// 	print_stacks(stacks);
// 	sswap(stacks, true);
// 	print_stacks(stacks);
// 	push(&stacks->b, &stacks->a, true);
// 	print_stacks(stacks);
// 	free(stacks);
// 	return 0;
// }