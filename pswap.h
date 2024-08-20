/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pswap.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontero <fmontero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 17:26:00 by fmontero          #+#    #+#             */
/*   Updated: 2024/08/18 19:09:23 by fmontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stduni.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "./libft/include/libft.h"

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
	struct s_valued_node	src_nd;
	struct s_valued_node	dst_nd;
	int						rate;
}	t_rated_node;

typedef struct s_stack
{
	struct s_node			*head;
	struct s_valued_node	peak;
	int						size;
	char					name;
}	t_stack;

typedef struct s_stacks
{
	struct s_stack			a;
	struct s_stack			b;
	struct s_node			nodes[];
}	t_stacks;

typedef struct s_ord
{
	bool		(*gt)(int, int);
	t_loc_node	(*get_top)(t_loc_node);
}	t_ord;

typedef struct s_buffer
{
	int		index;
	char	movements[BUFFER_SIZE];
}	t_buffer;