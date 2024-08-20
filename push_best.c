/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_best.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontero <fmontero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 18:03:28 by fmontero          #+#    #+#             */
/*   Updated: 2024/08/19 19:14:56 by fmontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

const static t_ord as = {.gt = greater, .get_top = get_max};
const static t_ord des = {.gt = lower, .get_top = get_min};

void	push_stack(t_stack *src, t_stack dst, t_ord *ord, int limit)
{
	set_peak(dst)
	while (src->size > limit)
	push_best(src, dst, ord);
}

void	push_best(t_stack *src, t_stack *dst, t_ord *ord)
{
	t_rated_node	rots;

	get_rots(src, dst, ord, &rots);
	src->head = rots->src_nd.node;
	dst->head = rots->dst_nd.node;
	dst->peak = (dst->peak.loc - rots->dst_node.loc) % dst.size;
	print_rots(&rots, src);
	push(src, dst, true);
	if (dst->head->value < dst->peak.node->value)
		dst->peak = (t_valued_node){dst->head, 0}
	else
		dst->peak.loc = (dst->peak.loc + 1) dst->size;
}

void	get_rots(t_stack *src, t_stack *dst, t_ord *ord, t_rated_node *rnd)
{
	t_rated_node	cur;

	cur.src_nd.node = src->head;
	cur.src_nd.loc = 0;
	get_target(src, dst, &cur, ord);	
	*rnd = cur;
	while (++cur.src_nd.loc < src->size)
	{
		cur.src_nd.node = cur.src_nd.node->next;
		get_target(src, dst, &cur, ord);
		if (cur.rate < rnd->rate)
			*rnd = cur;
	}
	calc_rots(rnd);
}

void	get_target(t_stack *src, t_stack *dst, t_rated_node *rnd, t_ord *ord)
{
	if (ord->gt(rnd->src_nd.node->value, ord->get_top(dst).node->value))
	{
		rnd->dst_nd.node = ord->get_top(dst).node->next;
		rnd->dst_nd.loc = (ord->get_top(dst).loc + 1) % (dst.size);
		return ;
	}
	rnd->dst_nd.node = dst->head;
	rnd->dst_nd.loc = 0;
	while (ord->gt(rnd->src_nd.node->value, rnd->dst_nd.node->value))
	{
		rnd->dst_nd.node = rnd->dst_nd.node->next;
		rnd->dst_nd.loc++;
	}
	while (ord->gt(rnd->dst_nd.node->value, rnd->src_nd.node->value))
	{
		if (ord->gt(rnd->src_nd.node->value, rnd->dst_nd.node->prev->value))
			break ;
		rnd->dst_nd.node = rnb->dst_nd.node->prev;
		rnd->dst_nd.loc--;
	}
	rnd->dst_nd.loc %= dst.size
	get_cost(src, dst, rnd);
}

void	get_cost(t_stack *src, t_stack *dst, t_rated_node *rnd)
{
	int src_nd_loc;
	int dst_nd_loc;
	
	src_nd_loc = rnd->src_nd.loc;
	dst_nd_loc = rnd->dst_nd.loc;
	rnd->rate = ft_max(src_nd_loc, dst_nd_loc);
	if (rnd->rate > ft_max(src->size - src_nd_loc, dst->size - dst_nd_loc))
	{
		rnd->rate = ft_max(src->size - src_nd_loc, dst->size - dst_nd_loc);
		rnd->src_nd.loc = src_nd_loc - src->size;
		rnd->dst_nd.loc = dst_nd_loc - dst->size; 
	}
	if (rnd->rate > src_nd_loc + (dst->size - dst_nd_loc))
	{
		rnd->rate = src_nd_loc + (dst->size - dst_nd_loc);
		rnd->src_nd.loc = src_nd_loc;
		rnd->dst_nd.loc = dst_nd_loc - dst->size;
	}
	if (rnd->rate > (src->size - src_nd_loc) + dst_nd_loc)
	{
		rnd->rate = (src->size - src_nd_loc) + dst_nd_loc;
		rnd->src_nd.loc = src_nd_loc - src->size;
		rnd->dst_nd.loc = dst_nd_loc;
	}
}
