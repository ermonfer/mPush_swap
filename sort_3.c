/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontero <fmontero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 18:05:21 by fmontero          #+#    #+#             */
/*   Updated: 2024/08/20 21:25:32 by fmontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

const static t_ord	g_as = {.gt = greater, .get_top = get_max};
const static t_ord	g_des = {.gt = lower, .get_top = get_min};
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
	push(&s->a, &s->b, true);
	push(&s->a, &s->b, true);
	set_peak(&s->b);
	push_stack(&s->a, &s->b, &g_des, 3);
	sort_3(&s->a);
	set_peak(&s->a);
	push_stack(&s->b, &s->b, &g_as, 0);
}

// int main(void)
// {
// 	t_stacks	*s;
// 	int size = 8;
// 	int arr[8] = {4,2,5,8,9,-1,-4,12};
// 	s = init_stacks(arr, size);
// 	if (size < 2)
// 		return 0;
// 	if (size == 2)
// 		sort_2(&s->a);
// 	if (size == 3)
// 		sort_3(&s->a);
// 	if (size > 3)
// 		turk(s);
// 	return 0;
// }
