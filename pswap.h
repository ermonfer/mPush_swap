/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pswap.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontero <fmontero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 17:26:00 by fmontero          #+#    #+#             */
/*   Updated: 2024/09/29 16:54:38 by fmontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PSWAP_H
# define PSWAP_H
# include <stddef.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include "./libft/include/libft.h"
# include "./libft/include/extra.h"

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
	t_loc_node	top;
}	t_ord;

bool		greater(int a, int b);
bool		lower(int a, int b);
void		set_top(t_stack *stack, t_ord *ord);

t_stacks	*init_stacks(int arr[], int nbs);
void		print_stacks(t_stacks *stacks);
void		print_circular_list(t_stack *stack);
void		head_to_bottom(t_stack *stack, t_ord *ord);
bool		stack_sorted(t_stack *stack, t_ord *ord, bool relative);

void		rot(t_stack *stack, bool print);
void		rrot(t_stacks *stacks, bool print);
void		rrev(t_stacks *stacks, bool print);
void		rev(t_stack *stack, bool print);
void		push(t_stack *src, t_stack *dst, bool print);
void		swap(t_stack *stack, bool print);
void		sswap(t_stacks *stacks, bool print);

void		print_rots(t_rated_node *rots, t_stack *src);
void		calc_rots(t_rated_node *rnd);

void		push_stack(t_stack *src, t_stack *dst, t_ord *ord, int limit);
void		get_rots(t_stack *src, t_stack *dst, t_ord *ord, t_rated_node *rnd);
void		get_rots(t_stack *src, t_stack *dst, t_ord *ord, t_rated_node *rnd);
void		get_tg(t_stack *src, t_stack *dst, t_rated_node *rnd, t_ord *ord);
void		get_cost(t_stack *src, t_stack *dst, t_rated_node *rnd);

void		sort_2(t_stack *stack);
void		sort_3(t_stack *stack, t_ord *ord, bool relative);
void		push_halves(t_stacks *s, int median, int size);
void		turk(t_stacks *s);

int			*parse(int argc, const char *argv[], int *size, int *median);
#endif
