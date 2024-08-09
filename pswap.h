/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pswap.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontero <fmontero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 17:26:00 by fmontero          #+#    #+#             */
/*   Updated: 2024/08/09 15:09:25 by fmontero         ###   ########.fr       */
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

typedef struct s_located_node
{
	struct s_node	*node;
	int				depth;
}	t_located_node;

typedef struct s_stacks
{
	int						capacity;
	int						a_size;
	struct s_node			*a_head;
	struct s_node			*b_head;
	struct s_located_node	cheapest;
	struct s_located_node	cheapest_target;
	struct s_node			*extreme;
	struct s_node			nodes[];
}	t_stacks;