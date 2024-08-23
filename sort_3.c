/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontero <fmontero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 18:05:21 by fmontero          #+#    #+#             */
/*   Updated: 2024/08/23 18:36:01 by fmontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

void	sort_2(t_stack *stack);
void	sort_3(t_stack *stack);

void	sort_2(t_stack *stack)
{
	if (stack->head->value > stack->head->next->value)
		rot(stack, true);
}

void	sort_3(t_stack *stack)
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
	t_ord	as;
	t_ord	des;

	as = (t_ord){greater, {NULL, 0}};
	des = (t_ord){lower, {NULL, 0}};
	push(&s->a, &s->b, true);
	push(&s->a, &s->b, true);
	push_stack(&s->a, &s->b, &des, 3);
	sort_3(&s->a);
	push_stack(&s->b, &s->a, &as, 0);
	head_to_bottom(&s->a, &as);
}
