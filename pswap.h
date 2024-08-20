/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pswap.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontero <fmontero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 17:26:00 by fmontero          #+#    #+#             */
/*   Updated: 2024/08/20 21:17:42 by fmontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "./libft/include/libft.h"
#include "./libft/include/extra.h"

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
	bool		(*gt)(int a, int b);
	t_loc_node	(*get_top)(t_stack * stack);
}	t_ord;

bool		greater(int a, int b);
bool		lower(int a, int b);
t_loc_node	get_max(t_stack *stack);
t_loc_node	get_min(t_stack *stack);
void		set_peak(t_stack *stack);

t_stacks	*init_stacks(int arr[], int nbs);

void		rot(t_stack *stack, bool print);
void		rrot(t_stacks *stacks, bool print);
void		rrev(t_stacks *stacks, bool print);
void		rev(t_stack *stack, bool print);
void		push(t_stack *src, t_stack *dst, bool print);
void		swap(t_stack *stack, bool print);
void		sswap(t_stacks *stacks, bool print);

void		print_rots(t_rated_node *rots, t_stack *src);
void		calc_rots(t_rated_node *rnd);

void		push_stack(t_stack *src, t_stack *dst, const t_ord *ord, int limit);

void		turk(t_stacks *s);
