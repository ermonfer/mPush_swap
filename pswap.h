/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pswap.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontero <fmontero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 17:26:00 by fmontero          #+#    #+#             */
/*   Updated: 2024/08/09 21:22:34 by fmontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct s_node
{
	int				value;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

struct s_valued_node
{
	struct s_node	*node;
	union
	{
		int	location;
		int	weight;
	};			
};

typedef struct s_valued_node	t_located_node;
typedef struct s_valued_node	t_weighted_node;

typedef struct s_paired_nodes
{
	struct s_valued_node	*node;
	struct s_valued_node	*target;
}	t_paired_nodes;

typedef struct s_stacks
{
	int						capacity;
	int						a_size;
	struct s_node			*a_head;
	struct s_node			*b_head;
	struct s_node			*extreme;
	struct s_node			nodes[];
}	t_stacks;