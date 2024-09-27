/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontero <fmontero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 18:05:21 by fmontero          #+#    #+#             */
/*   Updated: 2024/09/27 21:17:02 by fmontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

void	sort_2(t_stack *stack);
void	sort_3(t_stack *stack, t_ord *ord, bool relative);

void	sort_2(t_stack *stack)
{
	if (stack->head->value > stack->head->next->value)
		rot(stack, true);
}

void	sort_3(t_stack *stack, t_ord *ord, bool relative)
{
	if (!stack_sorted(stack, ord, 1))
		swap(stack, 1);
	if (!relative)
		head_to_bottom(stack, ord);
}

void	turk(t_stacks *s)
{
	t_ord	as;
	t_ord	des;

	as = (t_ord){greater, {NULL, 0}};
	des = (t_ord){lower, {NULL, 0}};
	if (stack_sorted(&s->a, &as, 0))
		return ;
	if (s->a.size > 4)
		push(&s->a, &s->b, true);
	push(&s->a, &s->b, true);
	push_stack(&s->a, &s->b, &des, 3);
	sort_3(&s->a, &as, 1);
	push_stack(&s->b, &s->a, &as, 0);
	head_to_bottom(&s->a, &as);
}
