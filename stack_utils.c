/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontero <fmontero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 17:57:21 by fmontero          #+#    #+#             */
/*   Updated: 2024/08/18 18:04:22 by fmontero         ###   ########.fr       */
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
	stacks->a.head->prev = stacks->a.head - 1;
	stacks->a.head->next = stacks->nodes;
	stacks->a.head = stacks->nodes;
	return (stacks);
}


// void print_circular_list(t_node *node, int size)
// {
// 	if (size == 0)
// 	{
// 		printf("vacio\n");
// 		return;
// 	}
// 	while (size--)
// 	{
// 		printf("%d\n", node->nb);
// 		node = node->next;
// 	}
// }

// void print_stacks(t_stacks *stacks)
// {
// 	printf("stack a:\n");
// 	print_circular_list(stacks->a_head, stacks->a_size);
// 	printf("stack b:\n");
// 	print_circular_list(stacks->b_head, stacks->nbs - stacks->a_size);
// }

// int main(void)
// {
// 	int array[] = {10, 212, 43, -4};
// 	t_stacks* stacks = init_stacks(array, 4);
// 	print_stacks(stacks);
// 	printf("\n%d\n", stacks->a_head->next->nb);
// 	return 0;
// }