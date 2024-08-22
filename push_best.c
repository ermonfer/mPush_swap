/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_best.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontero <fmontero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 18:03:28 by fmontero          #+#    #+#             */
/*   Updated: 2024/08/22 21:51:49 by fmontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

void	get_rots(t_stack *src, t_stack *dst, t_ord *ord, t_rated_node *rnd);
void	get_tg(t_stack *src, t_stack *dst, t_rated_node *rnd, t_ord *ord);
void	get_cost(t_stack *src, t_stack *dst, t_rated_node *rnd);
bool	out_of_bounds(int value, t_ord *ord);

void	push_stack(t_stack *src, t_stack *dst, t_ord *ord, int limit)
{
	t_rated_node	rots;

	set_top(dst, ord);
	printf("%d\n", ord->top.loc);//====================
	while (src->size > limit)
	{
		printf("\n////////\n");
		print_circular_list(src);
		print_circular_list(dst);
		printf("=======\n");
		get_rots(src, dst, ord, &rots);
		printf("%d %d %d\n", rots.src_nd.loc, rots.dst_nd.loc, rots.rate);//=============================
		src->head = rots.src_nd.node;
		dst->head = rots.dst_nd.node;
		ord->top.loc = ((ord->top.loc - rots.dst_nd.loc) % dst->size + dst->size) % dst->size;
		printf("%d   ******\n", ord->top.loc);//====================
		print_rots(&rots, src);
		push(src, dst, true);
		if (ord->gt(dst->head->value, ord->top.node->value))
			ord->top = (t_loc_node){dst->head, 0};
		else
			ord->top.loc = (ord->top.loc + 1) % dst->size;
	}
}

void	get_rots(t_stack *src, t_stack *dst, t_ord *ord, t_rated_node *rnd)
{
	t_rated_node	cur;
	int				pos;

	cur.src_nd.node = src->head;
	cur.src_nd.loc = 0;
	get_tg(src, dst, &cur, ord);
	*rnd = cur;
	pos = 0;
	while (++pos < src->size)
	{
		cur.src_nd.node = cur.src_nd.node->next;
		cur.src_nd.loc = pos;
		get_tg(src, dst, &cur, ord);
		if (cur.rate < rnd->rate)
			*rnd = cur;
	}
	calc_rots(rnd);
}

void	get_tg(t_stack *src, t_stack *dst, t_rated_node *rnd, t_ord *ord)
{
	if (out_of_bounds(rnd->src_nd.node->value, ord))
	{
		rnd->dst_nd.node = ord->top.node->next;
		rnd->dst_nd.loc = (ord->top.loc + 1) % (dst->size);
	}
	else
	{
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
			rnd->dst_nd.node = rnd->dst_nd.node->prev;
			rnd->dst_nd.loc--;
		}
		rnd->dst_nd.loc = ((rnd->dst_nd.loc % dst->size) + dst->size) % dst->size;
		}
	get_cost(src, dst, rnd);
}

void	get_cost(t_stack *src, t_stack *dst, t_rated_node *rnd)
{
	int	src_nd_loc;
	int	dst_nd_loc;

	src_nd_loc = rnd->src_nd.loc;
	dst_nd_loc = rnd->dst_nd.loc;
	rnd->rate = ft_maxint(src_nd_loc, dst_nd_loc);
	if (rnd->rate > ft_maxint(src->size - src_nd_loc, dst->size - dst_nd_loc))
	{
		rnd->rate = ft_maxint(src->size - src_nd_loc, dst->size - dst_nd_loc);
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

bool	out_of_bounds(int value, t_ord *ord)
{
	if (ord->gt(value, ord->top.node->value))
		return (true);
	if (ord->gt(ord->top.node->next->value, value))
		return (true);
	return (false);
}