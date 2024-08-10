/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pswap.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontero <fmontero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 17:26:00 by fmontero          #+#    #+#             */
/*   Updated: 2024/08/10 18:38:04 by fmontero         ###   ########.fr       */
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

typedef struct s_valued_node
{
	struct s_node	*node;
	int				loc;
}	t_loc_node;


typedef struct s_rated_node
{
	struct s_valued_node	nd;
	struct s_valued_node	tg;
	int						rate;
}	t_rated_node;

typedef struct s_stacks
{
	int						capacity;
	int						a_size;
	struct s_node			*a_head;
	struct s_node			*b_head;
	struct s_valued_node	extreme;
	struct s_node			nodes[];
}	t_stacks;