/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontero <fmontero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 17:57:21 by fmontero          #+#    #+#             */
/*   Updated: 2024/08/08 17:09:08 by fmontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

t_stacks	*init_stacks(int arr[], int capacity)
{
	t_stacks	*stacks;
	t_node		*current;

	stacks = malloc(sizeof (t_stacks) + capacity * sizeof (t_node));
	if (stacks == NULL)
		return (NULL);
	stacks->capacity = capacity;
	stacks->a_size = capacity;
	stacks->a_head = stacks->nodes;
	stacks->b_head = NULL;
	current = stacks->nodes;
	while (--capacity)
	{
		current->nb = *(arr++);
		current->next = current + 1;
		(current + 1)->prev = current;
		current++;
	}
	current->nb = *arr;
	current->prev = current -1;
	current->next = stacks->nodes;
	return (stacks);
}

void print_circular_list(t_node *node, int size)
{
	if (size == 0)
	{
		printf("vacio\n");
		return;
	}
	while (size--)
	{
		printf("%d\n", node->nb);
		node = node->next;
	}
}

void print_stacks(t_stacks *stacks)
{
	printf("stack a:\n");
	print_circular_list(stacks->a_head, stacks->a_size);
	printf("stack b:\n");
	print_circular_list(stacks->b_head, stacks->capacity - stacks->a_size);
}

int main(void)
{
	int array[] = {10, 212, 43, -4};
	t_stacks* stacks = init_stacks(array, 4);
	print_stacks(stacks);
	return 0;
}