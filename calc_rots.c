/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_rots.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontero <fmontero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 18:54:12 by fmontero          #+#    #+#             */
/*   Updated: 2024/08/22 18:18:50 by fmontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

static void	case_pp(t_rated_node *rnd);
static void	case_nn(t_rated_node *rnd);

void	calc_rots(t_rated_node *rnd)
{
	if (rnd->src_nd.loc * rnd->dst_nd.loc < 0)
		rnd->rate = 0;
	else if (rnd->src_nd.loc + rnd->dst_nd.loc > 0)
		case_pp(rnd);
	else
		case_nn(rnd);
}

static void	case_pp(t_rated_node *rnd)
{
	if (rnd->src_nd.loc >= rnd->dst_nd.loc)
	{
		rnd->rate = 1;
		rnd->src_nd.loc -= rnd->dst_nd.loc;
	}
	else
	{
		rnd->rate = 2;
		rnd->dst_nd.loc -= rnd->src_nd.loc;
	}
}

static void	case_nn(t_rated_node *rnd)
{
	if (rnd->src_nd.loc <= rnd->dst_nd.loc)
	{
		rnd->rate = -1;
		rnd->src_nd.loc -= rnd->dst_nd.loc;
	}
	else
	{
		rnd->rate = -2;
		rnd->dst_nd.loc -= rnd->src_nd.loc;
	}
}
