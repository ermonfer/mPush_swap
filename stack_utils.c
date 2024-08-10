/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontero <fmontero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 17:57:21 by fmontero          #+#    #+#             */
/*   Updated: 2024/08/10 20:49:46 by fmontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

t_stacks	*init_stacks(int arr[], int capacity)
{
	t_stacks	*stacks;
	t_node		*cur;

	stacks = malloc(sizeof (t_stacks) + capacity * sizeof (t_node));
	if (stacks == NULL)
		return (NULL);
	stacks->capacity = capacity;
	stacks->a_size = capacity;
	stacks->a_head = stacks->nodes;
	stacks->b_head = NULL;
	stacks->extreme.node = NULL;
	cur = stacks->nodes;
	while (--capacity)
	{
		cur->value = *(arr++);
		cur->next = cur + 1;
		(cur + 1)->prev = cur;
		cur++;
	}
	cur->value = *arr;
	cur->prev = cur -1;
	cur->next = stacks->nodes;
	return (stacks);
}

t_rated_node	get_best_a_des(t_stacks *stacks)
{
	t_rated_node	best;
	t_rated_node	cur;
	int				loc;

	loc = 0;
	cur.nd.node = stacks->a_head;
	cur.nd.loc = 0;
	rate_node_a_des(stacks, &cur);	
	best = cur;
	while (++loc < stacks->a_size)
	{
		
		cur = rate_node_a_des(stacks, (t_loc_node){cur.nd.node->next, loc});
		if (cur.rate < best.rate)
			best = cur;
	}
	return (best);
}	

void	get_movs(t_stacks *stacks, t_loc_node node)
{

}

void	rate_node_a_des(t_stacks *stacks, t_rated_node *rnd)
{
	t_rated_node res;

	if (nd.node->value < stacks->extreme.node->value)
		
	current = stacks->b_head;
	target.loc = 0;
	while (value < current->value)
	{
		if (value > current->next->value)
			break;
		current = current->next;
		target.loc++;
	}
	while (value > current->value)
	{
		if (value < current->prev->value)
			break;
		current = current->prev;
		target.loc--;
	}
	target.node = current;
	target.loc %= (stacks -> capacity - stacks->a_size);
	return(target);
}

t_loc_node localize_node(t_node *head, t_node *node)
{
	t_loc_node	res;
	t_node			*current;
	int				depth;

	res.node = node;
	current = head;
	depth = 0;
	while (current != node)
	{
		current = current->next;
		depth++;
	}
	res.loc = depth;
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