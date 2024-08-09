/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontero <fmontero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 17:57:21 by fmontero          #+#    #+#             */
/*   Updated: 2024/08/09 21:22:27 by fmontero         ###   ########.fr       */
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
	stacks->extreme = NULL;
	current = stacks->nodes;
	while (--capacity)
	{
		current->value = *(arr++);
		current->next = current + 1;
		(current + 1)->prev = current;
		current++;
	}
	current->value = *arr;
	current->prev = current -1;
	current->next = stacks->nodes;
	return (stacks);
}

void	get_cheapest_a_des(t_stacks *stacks)
{

}

void	get_movs(t_stacks *stacks, t_located_node node)
{
	int max = stacks
}

t_paired_nodes get_pair(t_stacks *stacks, t_located_node *lnode)
{
	t_paired_nodes pair;
	
	*(pair.node) = *lnode;
	*(pair.target) = get_target_a_des(stacks, lnode->node->value);
}

t_located_node	get_target_a_des(t_stacks *stacks, int value)
{
	t_located_node	target;
	t_node			*current;
	int				location;

	if (value < stacks->extreme->value)
		return (localize_node(stacks->b_head, stacks->extreme->next));
	current = stacks->b_head;
	target.location = 0;
	while (value < current->value)
	{
		if (value > current->next->value)
			break;
		current = current->next;
		target.location++;
	}
	while (value > current->value)
	{
		if (value < current->prev->value)
			break;
		current = current->prev;
		target.location--;
	}
	target.node = current;
	target.location %= (stacks -> capacity - stacks->a_size);
	return(target);
}

t_located_node localize_node(t_node *head, t_node *node)
{
	t_located_node	ret;
	t_node			*current;
	int				depth;

	ret.node = node;
	current = head;
	depth = 0;
	while (current != node)
	{
		current = current->next;
		depth++;
	}
	ret.location = depth;
	return (ret);	
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
// 	print_circular_list(stacks->b_head, stacks->capacity - stacks->a_size);
// }

// int main(void)
// {
// 	int array[] = {10, 212, 43, -4};
// 	t_stacks* stacks = init_stacks(array, 4);
// 	print_stacks(stacks);
// 	printf("\n%d\n", stacks->a_head->next->nb);
// 	return 0;
// }