/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontero <fmontero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 18:05:21 by fmontero          #+#    #+#             */
/*   Updated: 2024/08/21 20:08:58 by fmontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

static void	sort_2(t_stack *stack);
static void	sort_3(t_stack *stack);

static void	sort_2(t_stack *stack)
{
	if (stack->head->value > stack->head->next->value)
		rot(stack, true);
}

static void	sort_3(t_stack *stack)
{
	if (stack->head->value < stack->head->next->value)
	{
		if (stack->head->next->value < stack->head->prev->value)
			;
		else
			rev(stack, true);
	}
	else
	{
		if (stack->head->value < stack->head->prev->value)
			;
		else
			rot(stack, true);
	}
	if (stack->head->value > stack->head->next->value)
		swap(stack, true);
}

void	turk(t_stacks *s)
{
	t_ord	as = {.gt = greater, .top = {NULL, 0}};
	t_ord	des = {.gt = lower, .top = {NULL, 0}};

	as = (t_ord){greater, {NULL, 0}};
	des = (t_ord){lower, {NULL, 0}};
	t_rated_node rots;
	push(&s->a, &s->b, true);
	push(&s->a, &s->b, true);
	print_stacks(s);
	set_top(&s->b, &des);
	rots = (t_rated_node){{s->a.head, 0}, {NULL, 0}, 0};
	printf("%d, %d, %d\n", rots.src_nd.loc, rots.dst_nd.loc, rots.rate);
	get_tg(&s->a, &s->b, &rots, &des);
	printf("%d, %d, %d\n", rots.src_nd.loc, rots.dst_nd.loc, rots.rate);
	return ;
	get_rots(&s->a, &s->b, &des, &rots);
	push_stack(&s->a, &s->b, &des, 3);
	sort_3(&s->a);
	push_stack(&s->b, &s->b, &as, 0);
}

int main(void)
{
	t_stacks	*s;
	int size = 8;
	int arr[8] = {-32,2,0,8,9,-1,-4,12};
	s = init_stacks(arr, size);
	print_stacks(s);
	if (size < 2)
		return 0;
	if (size == 2)
		sort_2(&s->a);
	if (size == 3)
		sort_3(&s->a);
	if (size > 3)
		turk(s);
	free(s);
	return 0;
}
